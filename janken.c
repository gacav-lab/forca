#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data: 29/09/2022

void title(void);
void menu(void);
void drawTrophy(void);
void drawSadFace(void);
void drawSeriousFace(void);

int main(int argc, char **argv) {
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
            puts("Você escolheu pedra");
            break;
        case paper:
            puts("Você escolheu papel");
            break;
        case scissors:
            puts("Você escolheu tesoura");
    }

    machineChoice = rand() % 3;

    choice = machineChoice;

    switch(choice) {
        case rock:
            puts("A máquina escolheu pedra");
            break;
        case paper:
            puts("A máquina escolheu papel");
            break;
        case scissors:
            puts("A máquina escolheu tesoura");
    }

    if((playerChoice == rock && machineChoice == scissors) ||
    (playerChoice == scissors && machineChoice == paper) ||
    (playerChoice == paper && machineChoice == rock)) {
        drawTrophy();
        puts("Você venceu!!! :-)");
    } else if(playerChoice == machineChoice) {
		drawSeriousFace();
        puts("Empatado :-|");
    } else {
        drawSadFace();
        puts("Você perdeu!!! :-(");
    }

	system("setterm --reset");

    return EXIT_SUCCESS;
}

void title(void) {
    puts("x===========x\n"\
         "| JANKENPON |\n"\
         "x===========x\n");
}

void menu(void) {
    puts("1 - Pedra\n"\
         "2 - Papel\n"\
         "3 - Tesoura\n");
}

void drawTrophy(void) {
    puts("   ___________");
    puts("  '._==_==_=_.'");
    puts("  .-\\:      /-.");
    puts(" | (|:.     |) |");
    puts("  '-|:.     |-'");
    puts("    \\::.    /");
    puts("     '::. .'");
    puts("       ) (");
    puts("     _.' '._");
    puts("    `\"\"\"\"\"\"\"`\n\n");
}

void drawSadFace(void) {
    //TODO
}

void drawSeriousFace(void) {
    //TODO
}
