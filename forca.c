#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {
	const int TOTAL_LIFES = 5;
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
	}, *secretWord = NULL, *correctLetters = NULL, lifes[TOTAL_LIFES], kick;
	bool win = false, lose = false, correct;
	int length, indexLifes = TOTAL_LIFES - 1, indexDictionary;

	srand(time(NULL));

	indexDictionary = rand() % 30; // 0 a 29
	length = strlen(dictionary[indexDictionary]);
	secretWord = malloc(length * sizeof(char));
	correctLetters = malloc(length * sizeof(char));
	strcpy(secretWord, dictionary[indexDictionary]);

	for(int i = 0; i < TOTAL_LIFES; i++) {
		lifes[i] = 'o';
	}

	for(int i = 0; i < length; i++) {
		*(correctLetters + i) = '-';
	}

	while(!win && !lose) {
		correct = false;
		printf("%s\n\n", correctLetters);

		printf("vidas: %s\n", lifes);
		printf("Chute: ");
		scanf("%c", &kick);

		for(int i = 0; i < length; i++) {
			if(toupper(kick) == toupper(secretWord[i])) {
				correctLetters[i] = kick;
				correct = true;
			}
		}

		if(!correct) {
			lifes[indexLifes--] = ' ';
		}

		if(lifes[0] == ' ') {
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
			printf("Vidas: %s\n", lifes);
			printf("Palavra secreta: %s\n", secretWord);
			puts("Você venceu!!! :)");
		}

		__fpurge(stdin);
	}

	return EXIT_SUCCESS;
}
