#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

char* fillCorrectLetters(int length);

int main(int argc, char **argv) {
	char secretWord[] = "abacaxi", kick;
	int length = strlen(secretWord);
	char *correctLetters = fillCorrectLetters(length);
	char lifes[] = "ooooo";
	bool win, lose, correctLetter;
	int indexLifes = 0;

	win = lose = false;

	while(!win && !lose) {
		correctLetter = false;
		printf("%s\n\n", correctLetters);

		printf("vidas: %s\n", lifes);
		printf("Chute: ");
		scanf("%c", &kick);

		for(int i = 0; i < length; i++) {
			if(toupper(kick) == toupper(secretWord[i])) {
				correctLetters[i] = kick;
				correctLetter = true;
			}
		}

		if(!correctLetter) {
			lifes[indexLifes] = 'x';
			indexLifes++;
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

char* fillCorrectLetters(int length) {
	char *memory = malloc(length * sizeof(char));

	for(int i = 0; i < length; i++) {
		*(memory + i) = '-';
	}

	return memory;
}
