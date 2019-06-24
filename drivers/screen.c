#include "../drivers/screen.h"
#include "../kernel/port.c"

void clearScreen(char attr){
  for(int x=0; x < COLS; x++)
  for(int y=0; y < ROWS; y++)
  {
    putChar(' ', x, y, attr);
  }
}

void putString(char* str, int x, int y, char attr){
  int i=0;
  while(str[i]!='\0'){
    putChar(str[i++], x++, y, attr);
  }
}

void putChar(char c, int x, int y, char attr){
  if(!attr) attr = WHITE_ON_BLACK;
  int offset = getOffset(x,y);

  debug(c, offset);
  debug(attr, offset+1);
}

void putDec(int num, int x, int y, char attr){

  if(num==0){
    putChar('0', x, y, attr);
    return;
  }

  int result = 0;
  char revChar[100];
  int i = 99;
  int start=99;

  while(num>0 ){
    result = num%10;
    num/=10;
    start=i;
    revChar[i--] = result + '0';
  }

  for(int i=start; i<100;i++){
    revChar[i-start]= revChar[i];
    revChar[i-start+1]= '\0';
  }

  revChar[-start] = '\0';
  putString(revChar, x, y, attr);

}

int reverseInt(int num){
  int result = 0;

  while(num>0){

    result = result*10 + num%10;
    num/=10;
  }
  return result;
}

void debug(char c, int offset){
  int COL = 80;
  int ROW = 25;
  char *videoMemory = (char*) 0xb8000;
  *(videoMemory+offset) = c;
}

int getOffset(int x, int y){
  return (y*ROWS+x)*2;
}
