#include "../cpu/isr.h"
#include "../cpu/idt.c"
#include "../cpu/types.h"
#include "../drivers/screen.h"

void isrInstall(){
  setIDTgate(0,(u32)isr0);
  setIDTgate(1,(u32)isr1);
  setIDTgate(2,(u32)isr2);
  setIDTgate(3,(u32)isr3);
  setIDTgate(4,(u32)isr4);
  setIDTgate(5,(u32)isr5);
  setIDTgate(6,(u32)isr6);
  setIDTgate(7,(u32)isr7);
  setIDTgate(8,(u32)isr8);
  setIDTgate(9,(u32)isr9);
  setIDTgate(10,(u32)isr10);
  setIDTgate(11,(u32)isr11);
  setIDTgate(12,(u32)isr12);
  setIDTgate(13,(u32)isr13);
  setIDTgate(14,(u32)isr14);
  setIDTgate(15,(u32)isr15);
  setIDTgate(16,(u32)isr16);
  setIDTgate(17,(u32)isr17);
  setIDTgate(18,(u32)isr18);
  setIDTgate(19,(u32)isr19);
  setIDTgate(20,(u32)isr20);
  setIDTgate(21,(u32)isr21);
  setIDTgate(22,(u32)isr22);
  setIDTgate(23,(u32)isr23);
  setIDTgate(24,(u32)isr24);
  setIDTgate(25,(u32)isr25);
  setIDTgate(26,(u32)isr26);
  setIDTgate(27,(u32)isr27);
  setIDTgate(28,(u32)isr28);
  setIDTgate(29,(u32)isr29);
  setIDTgate(30,(u32)isr30);
  setIDTgate(31,(u32)isr31);

  setIDT();
}


char *exceptionMessages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};


void isrHandle(registers_t r){
  char logs[100]="Interrupt Recieved";
  putString(logs, 0, 24, WHITE_ON_BLACK);
}
