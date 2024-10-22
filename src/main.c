#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hangman.h"
#include "menu.h"


/* Themes */
static const char *animals[] = {
    "cachorro",
    "gato",
    "papagaio",
    "leao",
    "cobra",
};

static const char *countrys[] = {
    "brasil",
    "portugal",
    "bangladesh",
    "luxenburgo",
    "china",
};

static const char *sports[] = {
    "volei",
    "futebol",
    "tenis",
    "ciclismo",
    "nataçao",
};

static const char *foods[] = {
    "pizza",
    "feijoada",
    "canja",
    "esifirra",
    "estrogonofe",
};

static const char *works[] = {
    "programador",
    "medico",
    "mecanico",
    "professor",
    "tiktoker",
};

/* Avaliable letters on the keyboard */
char avaliableLetters[] = {
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
        'z', 'x', 'c', 'v', 'b', 'n', 'm',

    };

const char *choosed_word()
{
    int option = themeSelection();

    if (option == 0) {
        fprintf(stderr, "Opção inválida\n");
        return NULL;
    }
    if (option == 1) {
         
    int size = sizeof(animals) / sizeof(animals[0]);
    int selector = rand() % size;

    return animals[selector];
    }

    if (option == 2) {

        int size = sizeof(countrys) / sizeof(countrys[0]);
        int selector = rand() % size;

        return countrys[selector];
    }

    if (option == 3) {

        int size = sizeof(sports) / sizeof(sports[0]);
        int selector = rand() % size;

        return sports[selector];
    }

    if (option == 4) {

        int size = sizeof(foods) / sizeof(foods[0]);
        int selector = rand() % size;

        return foods[selector];
    }
    if (option == 5) {

        int size = sizeof(works) / sizeof(works[0]);
        int selector = rand() % size;

        return works[selector];
    }
    return NULL;
}

char *blank_spaces(int wsize)
{
    char *blank = (char*)malloc(wsize * sizeof(char));

    for (int i = 0; i < wsize; i++) {
        blank[i] = '_';
    }

    return blank;
}

void game(int wsize, const char *word)
{
    char letter;
    int check_chances = 7;
    char *word_to_guess = blank_spaces(wsize);

    while (1) {

        redrawHang(check_chances);
        printf("Palavra secreta: %s\n\n", word_to_guess);
        drawAvaliableLetters(avaliableLetters);
        printf("\nDigite uma letra: ");
        scanf(" %c", &letter);
        checkAvaliableLetters(letter, avaliableLetters);

        int found = 0;

        for (int i = 0; i < wsize; i++) {
            if (letter == word[i]) {
                word_to_guess[i] = letter;
                found = 1;
            }
        }

        if (!found) {
            check_chances--;
        }

        if (check_chances == 1) {

            redrawHang(check_chances);
            printf("Você perdeu\nResposta: %s\n", word);
            break;
        }

        if (strcmp(word_to_guess, word) == 0) {
            printf("Você ganhou\nResposta: %s\n", word_to_guess); 
            break;
        }

    }
    free(word_to_guess);
}

int main(void)
{

    int menu = drawMenu();
    if (menu == 0) { return 0; }

    drawThemes();

    srand(time(NULL));

    const char *word = choosed_word();

    if (word == NULL) { return 0; }

    int word_size = strlen(word);

    game(word_size, word);

    return 0;
}
