[bits 32]

; define some constants
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

printString32:
  ; Implimentation of printString in 32 bit protected mode
  ; without any luxuries offered by bios
  pusha                   ; push to stack
  mov edx, VIDEO_MEMORY   ; edx at start of video memory

  printString32Loop:

    mov al, [ebx]
    mov ah, WHITE_ON_BLACK

    cmp al, 0             ; check if we have reached the end
    je printString32Done

    mov [edx], ax         ; store char at cell

    add ebx, 1            ; increment ebx
    add edx, 2            ; move to next char cell

    jmp printString32Loop ; loop

  printString32Done:
    popa                  ; pop all
    ret                   ; go where ever u came from
