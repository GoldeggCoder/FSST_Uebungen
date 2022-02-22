/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Array Subset
	Datum:	18.10.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int subsetCheck(int [][2], int []);

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(0,1);

    int sizeArray[2] = {0,0}, i, j;

    do
    {
        for(i = 0; i < 2; i++)
        {
            do
            {
                printf(" Gib an wie gross das %d. Array ist: ", i+1);
                scanf("%d", &sizeArray[i]);
            }
            while(sizeArray[i] < 1);
        }
    }
    while(sizeArray[0] > sizeArray[1]);

    int array[sizeArray[1]][2];
    for(i = 0; i < 2; i++)
    {
        printf("\n");
        for(j = 0; j < sizeArray[i]; j++)
        {
            printf(" Gib die %d. Stelle vom %d. Array ein: ", j+1, i+1);
            scanf("%d", &array[j][i]);
        }
    }

    if(subsetCheck(&array, &sizeArray) == 1)
        printf("\n Array 1 ist kein Subset von Array 2");
    else
        printf("\n Array 1 ist ein Subset von Array 2");

    getch();
    clrscr();
    closeConsole();
    return 0;
}

int subsetCheck(int array[][2], int sizeArray[])
{
    int flag;
    for(int i = 0; i < sizeArray[0]; i++)
    {
        flag = 0;
        for(int j = 0; j < sizeArray[1]; j++)
        {
            if(array[i][0] == array[j][1])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return 1;
    }
    return 0;
}
