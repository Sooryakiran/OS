; Global Description Table (GDT)
; GDT start

gdt_start:

gdt_null:
  ; the null descriptor 8 bytes
  dd 0x0
  dd 0x0

gdt_code:
  ; the code segment
  dw 0xffff     ; limit 0-15 bits
  dw 0x0        ; base
  db 0x0        ; base
  db 10011010b  ; 1st flags, type flags
  db 11001111b  ; 2nd flags, limit
  db 0x0        ; base

gdt_data:
  ; the data segment
  dw 0xffff     ; limit 0-15 bits
  dw 0x0        ; base
  db 0x0        ; base
  db 10010010b  ; 1st flags, type flags
  db 11001111b  ; 2nd flags, limit
  db 0x0        ; base

gdt_end:
  ; the end label

gdt_descriptor:
  dw gdt_end - gdt_start - 1
  dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
