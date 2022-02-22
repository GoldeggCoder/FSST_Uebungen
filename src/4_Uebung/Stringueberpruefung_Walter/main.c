/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Stringüberprüfung
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

    int flag = 0, i;
    char string[80] = "";

    printf("Gib einen String ein: ");
    fgets(string, 80, stdin);

    i = 0;
    while(string[i] != '\n' && string[i] != '\0')
    {
        if((int)string[i] < 65 || ((int)string[i] > 90 && (int)string[i] < 97) || (int)string[i] > 122)
            flag = 1;
        i++;
    }

    if(flag)
        printf("\n Der String besteht nicht nur aus Buchstaben.");
    else
        printf("\n Der String besteht nur aus Buchstaben.");

    getch();
    clrscr();
    closeConsole();
    return 0;
}
