#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void title(void);
void menu(void);
void drawTrophy(void);
void drawSadFace(void);
void drawSeriousFace(void);

int main(int argc, char **argv) {
	char buffer;
    unsigned short playerChoice, machineChoice;

    system("setterm --foreground black");
    system("setterm --background cyan");
    system("setterm --clear");

    srand(time(NULL));

    title();
    menu();
    printf("Escolha: ");
    scanf("%hu", &playerChoice);

    enum OPTIONS {
        rock,
        paper,
        scissors
    } choice;

    choice = playerChoice;

    switch(choice) {
        case rock:
            printf("Você escolheu pedra\n");
            break;
        case paper:
            printf("Você escolheu papel\n");
            break;
        case scissors:
            printf("Você escolheu tesoura\n");
    }

    machineChoice = rand() % 3;

    choice = machineChoice;

    switch(choice) {
        case rock:
            printf("A máquina escolheu pedra\n");
            break;
        case paper:
            printf("A máquina escolheu papel\n");
            break;
        case scissors:
            printf("A máquina escolheu tesoura\n");
    }

    if((playerChoice == rock && machineChoice == scissors) ||
    (playerChoice == scissors && machineChoice == paper) ||
    (playerChoice == paper && machineChoice == rock)) {
        drawTrophy();
        printf("Você venceu!!! :-)\n\n");
    } else if(playerChoice == machineChoice) {
        printf("Empatado :-|\n\n");
    } else {
        printf("Você perdeu!!! :-(\n\n");
    }

	printf("Pressione a tecla \"enter\" para sair");
	scanf("*%c", &buffer);

	system("setterm --reset");

    return EXIT_SUCCESS;
}

void title(void) {
    printf("x===========x\n"\
         "| JANKENPON |\n"\
         "x===========x\n");
}

void menu(void) {
    printf("1 - Pedra\n"\
           "2 - Papel\n"\
           "3 - Tesoura\n\n");
}

void drawTrophy(void) {
    printf("   ___________\n");
    printf("  '._==_==_=_.'\n");
    printf("  .-\\:      /-.\n");
    printf(" | (|:.     |) |\n");
    printf("  '-|:.     |-'\n");
    printf("    \\::.    /\n");
    printf("     '::. .'\n");
    printf("       ) (\n");
    printf("     _.' '._\n");
    printf("    `\"\"\"\"\"\"\"`\n\n");
}
