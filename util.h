#pragma once

#define ENTER	13
#define LEFT    75
#define RIGHT   77
#define UP		72
#define DOWN	80
#define SPACE	32
#define POWERFULL 10

enum {BLANK, TARGET, OBJECT, AI};
void gotoxy(int x, int y);

void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint( int x, int y, char* string );
void SetColor( unsigned short color );
