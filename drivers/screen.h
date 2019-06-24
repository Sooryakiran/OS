#define VIDEO_ADDRESS 0xb8000
#define ROWS 80
#define COLS 80

#define WHITE_ON_BLACK 0x0f

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

int getOffset(int, int);
void debug(char, int);
void putChar(char, int, int, char);
void putString(char*, int, int, char);
void clearScreen(char);

void putDec(int, int, int, char);
int reverseInt(int);
