[org 0x7c00]

KERNEL_OFFSET equ 0x200

mov [BOOT_DRIVE], dl
mov bp, 0x200
mov sp, bp

mov bx, MSG_REAL_MODE   ; move 16 bit msg to bx
call printString        ; printString

call loadKernel         ; Load our kernel
call switchToPm         ; a giant leap for ......




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; external files
%include "boot/print/print_string.asm"
%include "boot/disk_load.asm"
%include "boot/gdt.asm"
%include "boot/print/print_string32.asm"
%include "boot/protected_mode.asm"


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Load kernel

[bits 16]

loadKernel:
  mov bx, MSG_LOAD_KERNEL       ; kernel load message
  call printString              ; print message

  mov bx, KERNEL_OFFSET
  mov dh, 18
  mov dl, [BOOT_DRIVE]
  call diskLoad

  ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Begin protected mode

[bits 32]

BEGIN_PM:
  mov ebx, MSG_PROTECTED_MODE   ; load protected mode message
  call printString32            ; printString in 32 bit mode

  ; mov ebx, KERNEL_OFFSET
  ; call printString32
  call KERNEL_OFFSET            ; Run kernel

  jmp $                         ; the most beautiful infinite loop


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Global variables (sort of)

BOOT_DRIVE:
  db 0

MSG_LOAD_KERNEL:
  db "Loading sooper kernel into memory.\n\r", 0

MSG_REAL_MODE:
  db "Boot sector started in 16-bit real mode.\n\r", 0

MSG_PROTECTED_MODE:
  db "Boot sector entered 32-bit protected mode.", 0

MSG_DEBUG_FLAG:
  db "Reached here"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 510 zeros minus size of previous code
times 510-($-$$) db 0

; boot sector identification
dw 0xaa55
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
