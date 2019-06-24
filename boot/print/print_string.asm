; print string whose address is at bx
; string is terminated by 0

printString:
  pusha           ; push all

  loopPrintString:
    mov al, [bx]        ; load what bx points to
    mov ah, 0x0e
    cmp al, 0           ; check if the string is terminated
    je return           ; end if string is terminated

    cmp al, 92          ; check for backslash
    jne continue

    ; if backslash found
    inc bx              ; increment bx
    mov al, [bx]        ; get next charector

    cmp al, 'a'         ; check for '\a'
    jne na              ; goto not a
    mov al, 0x07        ; ascii code for new line
    na:

    cmp al, 'b'         ; check for '\b'
    jne nb              ; goto not b
    mov al, 0x08        ; ascii code for backspace
    nb:

    cmp al, 'e'         ; check for '\e'
    jne ne              ; goto not e
    mov al, 0x1b        ; ascii code for escape char
    ne:

    cmp al, 'f'         ; check for '\f'
    jne nf              ; goto not f
    mov al, 0x0c        ; ascii code for page break
    nf:

    cmp al, 'n'         ; check for '\n'
    jne nn              ; goto not n
    mov al, 0x0a        ; ascii code for newline
    nn:

    cmp al, '\'         ; check for '\\'
    jne nsl             ; goto not \
    mov al, 0x5c        ; ascii code for backslash
    nsl:

    cmp al, 't'         ; check for '\t'
    jne nt              ; goto not t
    mov al, 0x09        ; ascii code for tab
    nt:

    cmp al, 'r'         ; check for '\r'
    jne nr              ; goto not r
    mov al, 0x0d        ; ascii code for carriage return
    nr:

    cmp al, 'v'         ; check for '\v'
    jne nv              ; goto not v
    mov al, 0x0b        ; ascii code for vtab
    nv:

    continue:
      int 0x10            ; interrupt
      inc bx              ; increment bx to next charector
      jmp loopPrintString ; iterate


  return:
    popa          ; pop all
    ret           ; return where called
