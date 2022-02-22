/*
	Autor:	Benedikt Walter
	Klasse:	2AHELS
	Titel:	Hangman
	Datum:	7.12.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "console.cpp"

#define BACKSLASH 92
#define FRONTSLASH 47
#define WAAGRECHTER_STRICH 196
#define SENKRECHTER_STRICH 124
#define CIRCLE 157

using namespace std;

int getWordFromFile(FILE *, char *, int, int *);
void startUI(int, char *);
void refreshUI(int, char *, int, char *);
int checkWord(char, char *, int);
int alreadyMistake(char, char *, int);
void paintHangman(int);

int main()
{
    setCursorType(0);
    initConsole();

    int entireRun = true;
    do
    {
        clrscr();
        textcolor(BLUE);
        gotoxy(1,1);
        srand(time(0));

        int randomNumber = rand()%312+1, len, currentMistakes = 0, runs = true, flag, i;
        char word[20], key = '0', mistakes[30];
        char answerWord[] = "********************";
        FILE *filePtr = NULL;

        if(getWordFromFile(filePtr, word, randomNumber, &len))
            return 1;
        startUI(len, answerWord);

        do
        {
            key = getch();
            if(checkWord(key, word, len))
            {
                flag = 0;
                for(i = 0; i < len; i++)
                {
                    if(word[i] == key)
                        answerWord[i] = key;
                    if(word[i] == answerWord[i])
                        flag++;
                }
                if(len == flag)
                    runs = false;
            }
            else
            {
                if(alreadyMistake(key, mistakes, currentMistakes) == 0)
                {
                    if(currentMistakes < 11)
                    {
                        mistakes[currentMistakes] = key;
                        currentMistakes++;
                        paintHangman(currentMistakes);
                    }
                    else
                    {
                        currentMistakes++;
                        runs = false;             
                    }
                }
            }
            refreshUI(len, answerWord, currentMistakes, mistakes);
        }
        while(runs);

        getch();
        clrscr();
        gotoxy(1,1);
        textcolor(BLUE);
        if(currentMistakes < 12)
            cout << "Super du hast es in " << currentMistakes << " Versuchen geschafft!" << endl;
        else
            cout << "Leider nicht geschafft... Das war das Wort: " << word << endl;
        cout << " Nochmal?(Y/N)";
        do
        {
            key = getch();
        }
        while(key != 'Y' && key != 'N');
        if(key == 'N')
            entireRun = false;
    }
    while(entireRun);

    getch();
    clrscr();
    closeConsole();
    return 0;
}

int getWordFromFile(FILE *filePtr, char word[], int randomNumber, int *len)
{
    filePtr = fopen("wordlist.txt", "r");
    if(filePtr == NULL)
        return 1;
    fseek(filePtr, 0, SEEK_SET);
    for(int i = 0; i < randomNumber; i++)
        fscanf(filePtr, "%s", word);
    fclose(filePtr);
    *len = strlen(word);
    return 0;
}

void startUI(int len, char answerWord[])
{
    cout << "Hallo, heute spielen wir Hangman." << endl;
    cout << " Gib einen Buchtstaben ein wo du glaubst, dass er vorkommt." << endl;
    cout << " Los geht es!" << endl;
    textcolor(GREEN);
    cout << " Das ist das Wort: ";
    for(int i = 0; i < len; i++)
        cout << answerWord[i];
    textcolor(RED);
    cout << "\n Falsche Buchtstaben: ";
}

void refreshUI(int len, char answerWord[], int currentMistakes, char mistakes[])
{
    textcolor(GREEN);
    gotoxy(19,4);
    for(int i = 0; i < len; i++)
        cout << answerWord[i];
    textcolor(RED);
    gotoxy(22,5);
    for(int i = 0; i < currentMistakes; i++)
    {
        if(i == currentMistakes-1)
            cout << mistakes[i];
        else
            cout << mistakes[i] << ", ";
    }
}

int checkWord(char key, char word[], int len)
{
    for(int i = 0; i < len; i++)
    {
        if(word[i] == key)
            return 1;
    }
    return 0;
}

int alreadyMistake(char key, char mistakes[], int currentMistakes)
{
    for(int i = 0; i < currentMistakes; i++)
    {
        if(mistakes[i] == key)
            return 1;
    }
    return 0;
}

void paintHangman(int hangman)
{
    textcolor(BLUE);
    switch(hangman)
    {
        case 1: 
            gotoxy(9,14);
            cout << (char)WAAGRECHTER_STRICH;
            gotoxy(8,15);
            cout << (char)FRONTSLASH;
            gotoxy(10,15);
            cout << (char)BACKSLASH;
            gotoxy(7,16);
            cout << (char)FRONTSLASH;
            gotoxy(11,16);
            cout << (char)BACKSLASH;
            break;
        case 2:
            gotoxy(8,12);
            cout << (char)BACKSLASH;
            gotoxy(9,12);
            cout << (char)SENKRECHTER_STRICH;
            gotoxy(9,13);
            cout << (char)SENKRECHTER_STRICH;
            break;
        case 3:
            gotoxy(4,11);
            cout << (char)WAAGRECHTER_STRICH;
            gotoxy(5,11);
            cout << (char)WAAGRECHTER_STRICH;
            gotoxy(6,11);
            cout << (char)WAAGRECHTER_STRICH;
            gotoxy(7,11);
            cout << (char)WAAGRECHTER_STRICH;
            gotoxy(8,11);
            cout << (char)WAAGRECHTER_STRICH;
            break;
        case 4:
            gotoxy(3,12);
            cout << (char)SENKRECHTER_STRICH;
            break;
        case 5:
            gotoxy(3,13);
            cout << (char)CIRCLE;
            break;
        case 6:
            gotoxy(3,14);
            cout << (char)SENKRECHTER_STRICH;
            gotoxy(3,15);
            cout << (char)SENKRECHTER_STRICH;
            break;
        case 7:
            gotoxy(2,14);
            cout << (char)BACKSLASH;
            break;
        case 8:
            gotoxy(2,16);
            cout << (char)FRONTSLASH;
            break;
        case 9:
            gotoxy(4,14);
            cout << (char)FRONTSLASH;
            break;
        case 10:
            gotoxy(4,16);
            cout << (char)BACKSLASH;
            break;
        case 11:
            textcolor(RED);
            gotoxy(3,13);
            cout << (char)CIRCLE;
            break;            
    }
    textcolor(GREEN);
}