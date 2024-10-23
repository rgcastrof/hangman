#include "../include/menu.h"
#include <stdio.h>

int drawMenu()
{
    int option;

    printf(" _    _          _   _  _____ __  __          _   _\n");
    printf("| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |\n");
    printf("| |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| |\n"); 
    printf("|  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` |\n");
    printf("| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |\n");
    printf("|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|\n");

    printf("\n1. Jogar\n");
    printf("2. Sair\n");

    scanf("%d", &option);

    if (option == 2) {
        printf("Fim do programa\n");
        return 0; 
    } else if (option != 1 && option != 2) {
        printf("Opção inválida\n");
        return 0;
    }
    

    return 1;
}

void drawThemes()
{

    printf("Selecione o tema:\n\n");
    printf("1. Animais\n"); 
    printf("2. Países\n");
    printf("3. Esportes\n");
    printf("4. Comidas\n");
    printf("5. Profissões\n");
}

int themeSelection()
{
    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            return 1;                    
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;                    
            break;
        case 4:
            return 4;
            break;
        case 5:
            return 5;
            break;
        default:
            return 0;
            break;
    }
}
