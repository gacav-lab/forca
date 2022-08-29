#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOTAL_LIVES 5

void initializeLives(char *lives);
void initializeCorrectLetters(char *correctLetters, int length);

int main(int argc, char **argv) {
	char dictionary[][11] = {
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
	}, *secretWord = NULL, *correctLetters = NULL, lives[TOTAL_LIVES], kick;
	bool win = false, lose = false, correct;
	int length, indexLives = TOTAL_LIVES - 1, indexDictionary;

	srand(time(NULL));

	indexDictionary = rand() % 30; // 0 a 29
	length = strlen(dictionary[indexDictionary]);
	secretWord = malloc(length * sizeof(char));
	correctLetters = malloc(length * sizeof(char));
	strcpy(secretWord, dictionary[indexDictionary]);

	initializeLives(&lives[0]);
	initializeCorrectLetters(correctLetters, length);

	while(!win && !lose) {
		correct = false;
		printf("%s\n\n", correctLetters);

		printf("vidas: %s\n", lives);
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

		if(lives[0] == ' ') {
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
