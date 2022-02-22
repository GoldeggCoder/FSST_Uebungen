/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Stringverkettung
	Datum:	22.11.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.c"


int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);

    int stringLength, i, j;
    char strings[2][80] = {"", ""}, endString[160] = "";

    printf("Erster String: ");
    fgets(strings[0], 80, stdin);
    printf(" Zweiter String: ");
    fgets(strings[1], 80, stdin);

    stringLength = 0;
    for(i = 0; i < 2; i++)
    {
        j = 0;
        while(strings[i][j] != '\0' && strings[i][j] != '\n')
        {
            endString[stringLength] = strings[i][j];
            j++;
            stringLength++;
        }
        endString[stringLength] = ' ';
        stringLength++;
    }

    printf(" %s", endString);  

    getch();
    clrscr();
    closeConsole();
    return 0;
}
