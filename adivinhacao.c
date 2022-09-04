#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data de criação: 01/08/2022

void showKicks(int *kicks, int i);
void wasAllocated(int *array);

int main(int argc, char **argv) {
	const int MAXIMUM_NUMBER = 1000;
	int secretNumber, kick, attempts = 1, i = 0, *kicks = NULL;
	bool win = false;

	kicks = malloc(sizeof(int));
	wasAllocated(kicks);

	srand(time(NULL));

	secretNumber = 1 + (rand() % MAXIMUM_NUMBER);

	system("clear");

	while(!win) {
		printf("Chute: ");
		scanf("%d", &kick);
		*(kicks + i++) = kick;

		if(kick < secretNumber) {
			system("clear");
			puts("Chute um número mais alto");
			showKicks(kicks, i);
		} else if(kick > secretNumber) {
			system("clear");
			puts("Chute um número mais baixo");
			showKicks(kicks, i);
		} else {
			system("clear");
			printf("Tentativa(s): %d\n", attempts);
			puts("Você descobriu o número secreto!!! :)");
			win = true;
		}

		// bug na realocação: realloc(): invalid next size
		kicks = (int*) realloc(kicks, sizeof(char));
		wasAllocated(kicks);

		attempts++;
	}

	free(kicks);

	return EXIT_SUCCESS;
}

void showKicks(int *kicks, int i) {
	printf("Chutes: ");
	for(int j = 0; j < i; j++) {
		printf("%d ", *(kicks + j));
	}
	printf("\n");
}

void wasAllocated(int *array) {
	if(array == NULL) {
		fprintf(stderr, "Erro: memória não alocada!");
		exit(EXIT_FAILURE);
	}
}
