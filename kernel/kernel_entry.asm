section .text
        global _start       ; must be declared for using gcc
_start:
; times 0xa db 0    ; Some free space
[bits 32]
[extern main]
call main
jmp $
; times 0xa00 - ($-$$) db 0  
