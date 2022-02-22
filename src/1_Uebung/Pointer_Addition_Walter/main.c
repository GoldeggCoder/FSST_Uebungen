/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:  Pointer Erstellung
	Datum:  20.09.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

#define UE 129

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(0,0);

    int zahlen[2] = {0}, summe = 0, *pointer[2] = {NULL};

    for(int i = 0; i < 2; i++)
    {
        printf("\n Gib die %d. Zahl f%cr die Addition ein: ", i+1, UE);
        scanf("%d", &zahlen[i]);
        pointer[i] = &zahlen;
        summe += *pointer[i];
    }

    printf("\n Das Ergebnis: %d", summe);

    getch();
    clrscr();
    closeConsole();
    return 0;
}
