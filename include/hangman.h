#ifndef HANGMAN_H
#define HANGMAN_H


void drawHang();
void redrawHang(int chances);
void drawAvaliableLetters(char *avletters);
void checkAvaliableLetters(char let, char *avletters);

#endif
