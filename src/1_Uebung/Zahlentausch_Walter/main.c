/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Zahlentausch
	Datum:	20.09.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);

    int zahlen[2] = {0}, *pointer[2] = {NULL}, cache = 0;

    pointer[0] = &zahlen[0];
    pointer[1] = &zahlen[1];

    printf("Zahlentausch:\n\n Gib die 1. Zahl ein: ");
    scanf("%d", pointer[0]);
    printf(" Gib die 2. Zahl ein: ");
    scanf("%d", pointer[1]);

    cache = *pointer[0];
    *pointer[0] = *pointer[1];
    *pointer[1] = cache;

    printf("\n 1. Zahl: %d\n 2. Zahl: %d", *pointer[0], *pointer[1]);

    getch();
    clrscr();
    closeConsole();
    return 0;
}
