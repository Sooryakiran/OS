
gcc -ffreestanding -m32 -fno-pie -c kernel/kernel.c -o kernel/kernel.o
nasm kernel/kernel_entry.asm -f elf -o kernel/kernel_entry.o
# ld  -m elf_i386 -o kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary
ld  -m elf_i386 -o kernel/kernel.bin  kernel/kernel_entry.o kernel/kernel.o --oformat binary
cat boot/boot_sect.bin kernel/kernel.bin > os-image
