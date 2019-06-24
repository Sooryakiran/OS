#ifndef IDT_H
#define IDT_H

#define low_16(address) (unsigned short)((address) & 0xFFFF)
#define high_16(address) (unsigned short)(((address) >> 16) & 0xFFFF)

#define KERNEL_CS 0X08

typedef struct{
  unsigned short lowOffset;
  unsigned short sel;
  unsigned char always0;
  unsigned char flags;
  unsigned short highOffset;
} __attribute__((packed)) idt_gate_t;

typedef struct{
  unsigned short limit;
  unsigned int base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256

idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void setIDTgate(int n, unsigned int handler);
void setIDT();

#endif
