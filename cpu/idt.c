#include "../cpu/idt.h"
#include "../cpu/types.h"

void setIDTgate(int n, u32 handler){
  idt[n].lowOffset = low_16(handler);
  idt[n].sel = KERNEL_CS;
  idt[n].always0 = 0;
  idt[n].flags = 0x8E;
  idt[n].highOffset = high_16(handler);
}

void setIDT(){
  idt_reg.base = (u32) &idt;
  idt_reg.limit = IDT_ENTRIES* sizeof(idt_gate_t) - 1;

  __asm__ __volatile__("lidtl (%0)" : : "r"(&idt_reg));
}
