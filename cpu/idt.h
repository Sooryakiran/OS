#ifndef IDT_H
#define IDT_H

#include "../cpu/types.h"

// #define low_16(address) (u16)((address) & 0xFFFF)
// #define high_16(address) (u16)(((address) >> 16) & 0xFFFF)

#define KERNEL_CS 0X08

typedef struct{
  u16 lowOffset;
  u16 sel;
  u8 always0;
  u8 flags;
  u16 highOffset;
} __attribute__((packed)) idt_gate_t;

typedef struct{
  u16 limit;
  u32 base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256

idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void setIDTgate(int n, u32 handler);
void setIDT();

#endif
