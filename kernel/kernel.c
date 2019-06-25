#include "../drivers/screen.c"
#include "../cpu/isr.c"
#include "../cpu/types.h"

void welcome(){

  char logs0[100] = "        Welcome to NothingOS";
  clearScreen(WHITE_ON_BLACK);
  putString(logs0,0, 0, WHITE_ON_BLACK);
  char logsA[100] = "----- v1-32bit Sooper Edition ------";
  putString(logsA, 0, 1, WHITE_ON_BLACK);

  char logs1[100]="[Boot sector] Started on 16bit";
  putString(logs1, 0, 3, WHITE_ON_BLACK);

  char logs2[100]="[Boot sector] Entered on 32bit protected mode";
  putString(logs2, 0, 4, WHITE_ON_BLACK);

  char logs3[100]="[Boot sector] Loading kernel from 0x200";
  putString(logs3, 0, 5, WHITE_ON_BLACK);

  char logs4[100]="[Sooper Kernel] Kernel entered";
  putString(logs4, 0, 7, WHITE_ON_BLACK);

  char logs5[100]="[Sooper Kernel] Doing nothing, coz that's what I am programmed";
  putString(logs5, 0, 8, WHITE_ON_BLACK);

  char logs6[100]="                to do. So, can't help. \\_('/')_/";
  putString(logs6, 0, 9, WHITE_ON_BLACK);


}

void main(){

  welcome();
  isrInstall();

  // isr_common_stub();
  // isr0();
  // debug('J', 0);
  // __asm__ __volatile__("int $2");
  //
  //
  // __asm__ __volatile__("int $3");

}
