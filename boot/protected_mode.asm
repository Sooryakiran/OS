[bits 16]

switchToPm:
  ; switch to protected 32 bit mode
  cli                     ; switch off interrupts
  lgdt [gdt_descriptor]   ; load gdt_descriptor table, see gdt.asm

  ; set first bit of control register
  mov eax, cr0
  or eax, 0x1
  mov cr0, eax




  jmp CODE_SEG:init_pm    ; that trixk to flush out instructions

[bits 32]

init_pm:
  mov ax, DATA_SEG        ; point old stuffs to new stuffs
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax


  mov ebp, 0x90000        ; stack at the top
  mov esp, ebp

  call BEGIN_PM
