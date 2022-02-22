/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Preisnachlass
	Datum:	27.09.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

#define PERCENT 37

void rabatt(float *);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);

    float preis;

    printf("Geben sie einen Preis ein: ");
    scanf("%f", &preis);

    rabatt(&preis);

    printf(" 20%c abgezogen: %.3f", PERCENT, preis);

    getch();
    clrscr();
    closeConsole();
    return 0;
}

void rabatt(float *preis)
{
    *preis = *preis * 0.8;
}
