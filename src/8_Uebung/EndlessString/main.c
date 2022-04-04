/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Endless String
	Datum:	4.4.2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.c"

#define ENTER 0x0D

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);

    int counter = 0;
    char key, *startPtr = malloc(0 * sizeof(char));

    printf("\n Gib einen String ein: ");

    while(1)
    {
        key = getch();
        if(key == ENTER)
            break;
        counter++;
        startPtr = realloc(startPtr, counter * sizeof(char));
        startPtr[counter-1] = key;
        printf("%c", startPtr[counter-1]);
    }

    printf("\n Dein String: ");
    for(int i = 0; i < counter; i++)
    {
        printf("%c", startPtr[i]);
    }

    free(startPtr);

    getch();
    clrscr();
    closeConsole();
    return 0;
}