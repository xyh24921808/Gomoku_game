#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROW 30
#define COL 30

#define Player1 1
#define Player2 2

#define NEXT       0
#define Player1win 1
#define Player2win 2
#define Draw       3


enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFT_UP,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN
};
void game();
