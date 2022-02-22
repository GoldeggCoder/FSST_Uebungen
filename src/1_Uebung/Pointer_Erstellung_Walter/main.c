/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:  Pointer Erstellung
	Datum:  20.09.2021
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

    int var = 3, pointer = NULL;

    pointer = &var;

    printf("Adresse von var: %p\n ", &var);
    printf("Wert von var: %d\n ", var);
    printf("Adresse von pointer: %p\n ", &pointer);
    printf("Wert von pointer: %p\n ", pointer);

    getch();
    clrscr();
    closeConsole();
    return 0;
}
