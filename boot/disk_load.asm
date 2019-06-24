; load dh sectors to es:bx from drive dl

diskLoad:
  push dx               ; push dx stack
  mov ah, 0x02          ; bios read sector
  mov al, dh            ; read dh sectors
  mov ch, 0x00          ; cylinder 0
  mov dh, 0x00          ; head 0
  mov cl, 0x02          ; from second sector

  int 0x13              ; interrupt
  jc diskError          ; error handling

  pop dx                ; restore dx
  cmp dh, al            ; check if everything read
  jne diskError
  ret

diskError:
  mov bx, MSG_DISK_ERROR
  call printString

; variables
MSG_DISK_ERROR:
  db "waltos- Error readinf disk", 0
