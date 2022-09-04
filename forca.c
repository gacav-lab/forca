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
#define NUMBER_OF_ADJECTIVES 31
#define NUMBER_OF_THEMES 4

// Autor: Gabriel Cavalcante de Jesus Oliveira
// Data de criação: 28/08/2022
// Linguagem de programação: C
// Versão da linguagem: C17
// Compatível com: sistemas Unix-like
// Compilador: gcc
// Github: https://github.com/gabrielcavalcante-cs

void title(void);
void initializeLives(char *lives, const char SYMBOL);
void initializeCorrectLetters(char *correctLetters, const char SYMBOL, int length);
void wasAllocated(char *array);

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
	}, adjectives[][15] = {
		"Bonito",
		"Alto",
		"Elegante",
		"Formoso",
		"Inteligente",
		"Carismatico",
		"Compreensivo",
		"Reflexivo",
		"Pensativo",
		"Forte",
		"Talentoso",
		"Agradavel",
		"Cheiroso",
		"Aplicado",
		"Companheiro",
		"Determinado",
		"Educado",
		"Escrupuloso",
		"Extraordinario",
		"Habilidoso",
		"Genuino",
		"Independente",
		"Maravilhoso",
		"Organizado",
		"Perseverante",
		"Persistente",
		"Perspicaz",
		"Valoroso",
		"Verdadeiro",
		"Zeloso",
		"Cuidadoso"
	}, *secretWord = NULL, *correctLetters = NULL, *lives, *topic, kick;
	const char SYMBOL_OF_LIFE = '@', SYMBOL_OF_NONE = '~';
	bool win = false, lose = false, correct;
	const int scoreRate = 218;
	int length, indexLives = TOTAL_LIVES - 1, index, topicIndex, score = scoreRate * TOTAL_LIVES;

	lives = malloc(TOTAL_LIVES * sizeof(char));
	wasAllocated(lives);

	srand(time(NULL));

	enum Topic {
		ECountries,
		EFruits,
		EColors,
		EAdjectives
	} ETopic;

	ETopic = rand() % NUMBER_OF_THEMES;

	if(ETopic == ECountries) {
		topic = malloc(strlen("Paises") * sizeof(char));
		wasAllocated(topic);
		topic = "paises";
		index = rand() % NUMBER_OF_COUNTRIES;
		length = strlen(countries[index]);
		secretWord = malloc(length * sizeof(char));
		wasAllocated(secretWord);
		correctLetters = malloc(length * sizeof(char));
		wasAllocated(correctLetters);
		strcpy(secretWord, countries[index]);
	} else if(ETopic == EFruits) {
		topic = malloc(strlen("Frutas") * sizeof(char));
		wasAllocated(topic);
		topic = "frutas";
		index = rand() % NUMBER_OF_FRUITS;
		length = strlen(fruits[index]);
		secretWord = malloc(length * sizeof(char));
		wasAllocated(secretWord);
		correctLetters = malloc(length * sizeof(char));
		wasAllocated(correctLetters);
		strcpy(secretWord, fruits[index]);
	} else if(ETopic == EAdjectives) {
		topic = malloc(strlen("Adjetivos") * sizeof(char));
		wasAllocated(topic);
		topic = "adjetivos";
		index = rand() % NUMBER_OF_ADJECTIVES;
		length = strlen(adjectives[index]);
		secretWord = malloc(length * sizeof(char));
		wasAllocated(secretWord);
		correctLetters = malloc(length * sizeof(char));
		wasAllocated(correctLetters);
		strcpy(secretWord, adjectives[index]);
	} else {
		topic = malloc(strlen("Cores") * sizeof(char));
		wasAllocated(topic);
		topic = "cores";
		index = rand() % NUMBER_OF_COLORS;
		length = strlen(colors[index]);
		secretWord = malloc(length * sizeof(char));
		wasAllocated(secretWord);
		correctLetters = malloc(length * sizeof(char));
		wasAllocated(correctLetters);
		strcpy(secretWord, colors[index]);
	}

	initializeLives(lives, SYMBOL_OF_LIFE);
	initializeCorrectLetters(correctLetters, SYMBOL_OF_NONE, length);

	while(!win && !lose) {
		system("clear");
		title();
		correct = false;

		printf("%s\n\n", correctLetters);

		printf("Tópico: %s\n", topic);
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
			score -= scoreRate;
		}

		if(*lives == ' ') {
			lose = true;
			system("clear");
			title();
			printf("Pontuação: %d\n", score);
			printf("Palavra secreta: %s\n", secretWord);
			puts("Você perdeu!!! :(");
		}

		if(islower(*correctLetters)) {
			*correctLetters = toupper(*correctLetters);
		}

		if (strcmp(secretWord, correctLetters) == 0) {
			win = true;
			system("clear");
			title();
			printf("Vidas: %s\n", lives);
			printf("Pontuação: %d\n", score);
			printf("Palavra secreta: %s\n", secretWord);
			puts("Você venceu!!! :)");
		}

		__fpurge(stdin);
	}

	free(secretWord);
	free(correctLetters);
	free(lives);

	return EXIT_SUCCESS;
}

void title() {
	puts("x===============x\n"\
		 "| JOGO DA FORCA |\n"\
		 "x===============x\n");
}

void wasAllocated(char *array) {
	if(array == NULL) {
		fprintf(stderr, "Erro: falha na alocação de memória!\n");
		exit(EXIT_FAILURE);
	}
}

void initializeLives(char *lives, const char SYMBOL) {
	for(int i = 0; i < TOTAL_LIVES; i++) {
		*(lives + i) = SYMBOL;
	}
}

void initializeCorrectLetters(char *correctLetters, const char SYMBOL, int length) {
	for(int i = 0; i < length; i++) {
		*(correctLetters + i) = SYMBOL;
	}
}
