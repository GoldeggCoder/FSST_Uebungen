/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Bitverarbeitung
	Datum:	17.1.2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "console.c"

void to_binary(unsigned char);
void to_hex();

int main()
{
    setCursorType(0);
    initConsole();
    textcolor(GREEN);
    gotoxy(1,1);

    //1. Teil
    unsigned char x;
    printf("Geben Sie eine HEX Zahl ein: ");
    scanf("%x", &x);
    to_binary(x);

    printf("\n\n");
    
    //2. Teil
    to_hex();

    printf("\n\n");

    //3. Teil
    unsigned char z = 39;
    z >>= 2;
    printf(" 39 >> 2 = %d\n", z);
    to_binary(z);

    getch();
    clrscr();
    closeConsole();
    return 0;
}

void to_binary(unsigned char x)
{
    printf(" 0b");
    for(int i = 0; i < 8; i++)
    {
        if((int)x >= 1 << (7-i))
        {
            x -= 1 << (7-i);
            printf("1");
        }
        else if((int) x == 0)
            break;
        else
            printf("0");
    }
}

void to_hex()
{
    printf(" Geben Sie eine BIN Zahl ein: ");
    unsigned char input, value = 0;
    for(int i = 0; i < 8; i++)
    {
        input = getch();
        if(input == '1')
            value += 1 << (7-i);
        else if(input != '0')
            return;
        printf("%c", input);    
    }
    printf("\n 0x%x", value);
}