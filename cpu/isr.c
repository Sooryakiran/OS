#include "../cpu/isr.h"
#include "../cpu/idt.c"
#include "../drivers/screen.h"

void isrInstall(){
  setIDTgate(0,(unsigned int)isr0);
  setIDTgate(1,(unsigned int)isr1);
  setIDTgate(2,(unsigned int)isr2);
  setIDTgate(3,(unsigned int)isr3);
  setIDTgate(4,(unsigned int)isr4);
  setIDTgate(5,(unsigned int)isr5);
  setIDTgate(6,(unsigned int)isr6);
  setIDTgate(7,(unsigned int)isr7);
  setIDTgate(8,(unsigned int)isr8);
  setIDTgate(9,(unsigned int)isr9);
  setIDTgate(10,(unsigned int)isr10);
  setIDTgate(11,(unsigned int)isr11);
  setIDTgate(12,(unsigned int)isr12);
  setIDTgate(13,(unsigned int)isr13);
  setIDTgate(14,(unsigned int)isr14);
  setIDTgate(15,(unsigned int)isr15);
  setIDTgate(16,(unsigned int)isr16);
  setIDTgate(17,(unsigned int)isr17);
  setIDTgate(18,(unsigned int)isr18);
  setIDTgate(19,(unsigned int)isr19);
  setIDTgate(20,(unsigned int)isr20);
  setIDTgate(21,(unsigned int)isr21);
  setIDTgate(22,(unsigned int)isr22);
  setIDTgate(23,(unsigned int)isr23);
  setIDTgate(24,(unsigned int)isr24);
  setIDTgate(25,(unsigned int)isr25);
  setIDTgate(26,(unsigned int)isr26);
  setIDTgate(27,(unsigned int)isr27);
  setIDTgate(28,(unsigned int)isr28);
  setIDTgate(29,(unsigned int)isr29);
  setIDTgate(30,(unsigned int)isr30);
  setIDTgate(31,(unsigned int)isr31);

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
