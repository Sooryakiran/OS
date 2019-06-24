#include "../drivers/screen.c"
#include "../cpu/isr.c"

void welcome(){

  char string[100] = "Welcome to SooperOS";
  clearScreen(WHITE_ON_BLACK);
  putString(string,0, 0, WHITE_ON_BLACK);
  char logs[100]="----- v1-32bit ------";
  putString(logs, 0, 1, WHITE_ON_BLACK);

}

void main(){

  welcome();
  isrInstall();

  __asm__ __volatile__("int $2");
}
