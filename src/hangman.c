#include "../include/hangman.h"
#include <stdio.h>

static const char *hangman[] = {
    "    |--------|-",
    "    |        |",
    "    |        |",
    "    |        O",
    "    |",
    "    |",
    "    |",
    "    |",
    "____|____",
};

void drawHang() {

    for (int i = 0; i < 9; i++) {
        printf("%s\n", hangman[i]); 
    }
}

void redrawHang(int chances)
{
    switch (chances) {
        case 6:
            hangman[3] = "    |        o",
            drawHang();
            printf("\n");
            break;
        case 5:
            hangman[4] = "    |        |",
            drawHang();
            printf("\n");
            break;
        case 4:
            hangman[4] = "    |       /|",
            drawHang();
            printf("\n");
            break;
        case 3:
            hangman[4] = "    |       /|\\",
            drawHang();
            printf("\n");
            break;
        case 2:
            hangman[5] = "    |       /",
            drawHang();
            printf("\n");
            break;
        case 1:
            hangman[5] = "    |       / \\",
            drawHang();
            printf("\n");
            break;

        default:
            drawHang();
            printf("\n");
            break;
    }
}

void drawAvaliableLetters(char *avletters)
{
    printf("Letras disponíveis:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c ", avletters[i]); 
        if (i == 9 || i == 18) { printf("\n"); }
    }
}

void checkAvaliableLetters(char let, char *avletters)
{
    for (int i = 0; i < 26; i++) {

        if (avletters[i] == let) {
            avletters[i] = '-';
        } 
    }

}
