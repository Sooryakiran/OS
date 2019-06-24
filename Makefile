# Automatically generate lists of sources using wildcards .
C_SOURCES = $(wildcard kernel/*.c drivers/*.c )
HEADERS = $(wildcard kernel/*.h drivers/*.h )

# Convert the *. c filenames to *. o to give a list of object files to build
OBJ = ${C_SOURCES :.c = .o }
# Defaul build target
all : os-image
	dd if=/dev/zero bs=1M count=4 >> os-image

os-image: boot/boot_sector.bin kernel/kernel.bin
	cat $^ > os-image

kernel/kernel.bin:  kernel/kernel_entry.o kernel/kernel.o cpu/int_asm.o ${OBJ}
	ld  -m elf_i386 -o $@ $^ --oformat binary

boot/boot_sect.bin:

cpu/int_asm.o:
	nasm cpu/int.asm -f elf -o cpu/int_asm.o
	# gcc -ffreestanding -m32 -fno-pie  cpu/isr.c cpu/int_asm.o -o int.o



# Compile C
%.o : %.c ${HEADERS}
	gcc -ffreestanding -m32 -fno-pie -c $< -o $@

# Avengers Assemble
kernel/%.o : kernel/%.asm
	nasm $< -f elf -o $@

boot/%.bin : boot/%.asm
	nasm -fbin $< -o $@

clean:
	rm -fr *.bin *.dis *.o os-image
	rm -fr kernel/*.o boot/*.bin drivers/*.o

run:
	qemu-system-x86_64 os-image --no-reboot
test:
	qemu-system-x86_64 os-image --no-reboot --no-shutdown
