#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {
	char dictionary[][11] = {
		"brasil",
		"alemanha",
		"dinamarca",
		"equador",
		"mexico",
		"espanha",
		"chile",
		"bolivia",
		"portugal",
		"madagascar",
		"japao",
		"china",
		"brunei",
		"italia",
		"canada",
		"franca",
		"catar",
		"croacia",
		"eslovenia",
		"egito",
		"honduras",
		"hungria",
		"idonesia",
		"india",
		"ira",
		"iraque",
		"jamaica",
		"nepal",
		"nicaragua",
		"nigeria"
	}, *secretWord, *correctLetters, lifes[] = "ooooo", kick;
	bool win, lose, correct;
	int length, indexLifes = 0, indexDictionary;

	srand(time(NULL));

	win = lose = false;
	indexDictionary = rand() % 30; // 0 a 29
	length = strlen(dictionary[indexDictionary]);
	secretWord = malloc(length * sizeof(char));
	strcpy(secretWord, dictionary[indexDictionary]);
	correctLetters = malloc(length * sizeof(char));

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
			lifes[indexLifes++] = 'x';
		}

		if(strcmp(lifes, "xxxxx") == 0) {
			lose = true;
			system("clear");
			printf("vidas: %s\n", lifes);
			puts("Você perdeu!!! :(");
		}

		if (strcmp(secretWord, correctLetters) == 0) {
			win = true;
			system("clear");
			printf("vidas: %s\n", lifes);
			puts("Você venceu!!! :)");
		}

		__fpurge(stdin);
	}

	return EXIT_SUCCESS;
}
