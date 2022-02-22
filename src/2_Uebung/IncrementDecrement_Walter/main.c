/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Increment/Decrement
	Datum:	27.09.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void increment(int *);
void decrement(int *);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);

    int cache = 5;

    increment(&cache);
    printf("5 + 1 = %d", cache);
    decrement(&cache);
    printf("\n 6 - 1 = %d", cache);

    getch();
    clrscr();
    closeConsole();
    return 0;
}

void increment(int *zahl)
{
    (*zahl)++;
}

void decrement(int *zahl)
{
    (*zahl)--;
}
