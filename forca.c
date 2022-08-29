#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOTAL_LIVES 5
#define NUMBER_OF_COUNTRIES 30
#define NUMBER_OF_FRUITS 15
#define NUMBER_OF_COLORS 16
#define NUMBER_OF_THEMES 3

void initializeLives(char *lives);
void initializeCorrectLetters(char *correctLetters, int length);

int main(int argc, char **argv) {
	char countries[][11] = {
		"Brasil",
		"Alemanha",
		"Dinamarca",
		"Equador",
		"Mexico",
		"Espanha",
		"Chile",
		"Bolivia",
		"Portugal",
		"Madagascar",
		"Japao",
		"China",
		"Brunei",
		"Italia",
		"Canada",
		"Franca",
		"Catar",
		"Croacia",
		"Eslovenia",
		"Egito",
		"Honduras",
		"Hungria",
		"Idonesia",
		"India",
		"Ira",
		"Iraque",
		"Jamaica",
		"Nepal",
		"Nicaragua",
		"Nigeria"
	}, fruits[][11] = {
		"Pitanga",
		"Acerola",
		"Tomate",
		"Manga",
		"Abacaxi",
		"Melancia",
		"Morango",
		"Banana",
		"Maracuja",
		"Melao",
		"Cacau",
		"Pessego",
		"Abacate",
		"Mamao",
		"Maracujina"
	}, colors[][10] = {
		"Azul",
		"Ciano",
		"Amarelo",
		"Roxo",
		"Rosa",
		"Dourado",
		"Carmesim",
		"Carmim",
		"Escarlate",
		"Marrom",
		"Cinza",
		"Preto",
		"Branco",
		"Laranja",
		"Vermelho",
		"Verde"
	}, *secretWord = NULL, *correctLetters = NULL, *lives = malloc(TOTAL_LIVES * sizeof(char)), *theme, kick;
	bool win = false, lose = false, correct;
	int length, indexLives = TOTAL_LIVES - 1, index, themeIndex;

	srand(time(NULL));

	enum THEME {
		//o prefixo "C", se refere a "constant", para diferenciá-las dos arrays multidimensionais
		CCountry,
		CFruits,
		CColors
	} ETheme;

	ETheme = rand() % NUMBER_OF_THEMES;

	if(ETheme == CCountry) {
		theme = malloc(strlen("Paises") * sizeof(char));
		theme = "paises";
		index = rand() % NUMBER_OF_COUNTRIES;
		length = strlen(countries[index]);
		secretWord = malloc(length * sizeof(char));
		correctLetters = malloc(length * sizeof(char));
		strcpy(secretWord, countries[index]);
	} else if(ETheme == CFruits) {
		theme = malloc(strlen("Frutas") * sizeof(char));
		theme = "frutas";
		index = rand() % NUMBER_OF_FRUITS;
		length = strlen(fruits[index]);
		secretWord = malloc(length * sizeof(char));
		correctLetters = malloc(length * sizeof(char));
		strcpy(secretWord, fruits[index]);
	} else {
		theme = malloc(strlen("Cores") * sizeof(char));
		theme = "cores";
		index = rand() % NUMBER_OF_COLORS;
		length = strlen(colors[index]);
		secretWord = malloc(length * sizeof(char));
		correctLetters = malloc(length * sizeof(char));
		strcpy(secretWord, colors[index]);
	}

	initializeLives(lives);
	initializeCorrectLetters(correctLetters, length);

	while(!win && !lose) {
		correct = false;

		printf("%s\n\n", correctLetters);

		printf("Tema: %s\n", theme);
		printf("Vidas: %s\n", lives);
		printf("Chute: ");
		scanf("%c", &kick);

		for(int i = 0; i < length; i++) {
			if(toupper(kick) == toupper(secretWord[i])) {
				correctLetters[i] = kick;
				correct = true;
			}
		}

		if(!correct) {
			lives[indexLives--] = ' ';
		}

		if(*lives == ' ') {
			lose = true;
			system("clear");
			printf("Palavra secreta: %s\n", secretWord);
			puts("Você perdeu!!! :(");
		}

		if(islower(*correctLetters)) {
			*correctLetters = toupper(*correctLetters);
		}

		if (strcmp(secretWord, correctLetters) == 0) {
			win = true;
			system("clear");
			printf("Vidas: %s\n", lives);
			printf("Palavra secreta: %s\n", secretWord);
			puts("Você venceu!!! :)");
		}

		__fpurge(stdin);
	}

	return EXIT_SUCCESS;
}

void initializeLives(char *lives) {
	for(int i = 0; i < TOTAL_LIVES; i++) {
		*(lives + i) = 'o';
	}
}

void initializeCorrectLetters(char *correctLetters, int length) {
	for(int i = 0; i < length; i++) {
		*(correctLetters + i) = '-';
	}
}
