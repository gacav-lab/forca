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
// Github: https://github.com/gabrielcavalcante-cs/games

void initializeLives(char *lives, const char SYMBOL);
void initializeCorrectLetters(char *correctLetters, const char SYMBOL, int length);

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
	}, *secretWord = NULL, *correctLetters = NULL, *lives = malloc(TOTAL_LIVES * sizeof(char)), *topic, kick;
	const char SYMBOL_OF_LIFE = '@', SYMBOL_OF_NONE = '~';
	bool win = false, lose = false, correct;
	const int scoreRate = 218;
	int length, indexLives = TOTAL_LIVES - 1, index, topicIndex, score = scoreRate * TOTAL_LIVES;

	srand(time(NULL));

	enum TOPIC {
		//prefixo "C" de "constant", adicional, para diferenciá-las de arrays multidimensionais de mesmo identificador
		CCountry,
		CFruits,
		CColors,
		CAdjectives
	} ETopic;

	ETopic = rand() % NUMBER_OF_THEMES;

	if(ETopic == CCountry) {
		topic = malloc(strlen("Paises") * sizeof(char));
		topic = "paises";
		index = rand() % NUMBER_OF_COUNTRIES;
		length = strlen(countries[index]);
		secretWord = malloc(length * sizeof(char));
		correctLetters = malloc(length * sizeof(char));
		strcpy(secretWord, countries[index]);
	} else if(ETopic == CFruits) {
		topic = malloc(strlen("Frutas") * sizeof(char));
		topic = "frutas";
		index = rand() % NUMBER_OF_FRUITS;
		length = strlen(fruits[index]);
		secretWord = malloc(length * sizeof(char));
		correctLetters = malloc(length * sizeof(char));
		strcpy(secretWord, fruits[index]);
	} else if(ETopic == CAdjectives) {
		topic = malloc(strlen("Adjetivos") * sizeof(char));
		topic = "adjetivos";
		index = rand() % NUMBER_OF_ADJECTIVES;
		length = strlen(adjectives[index]);
		secretWord = malloc(length * sizeof(char));
		correctLetters = malloc(length * sizeof(char));
		strcpy(secretWord, adjectives[index]);
	} else {
		topic = malloc(strlen("Cores") * sizeof(char));
		topic = "cores";
		index = rand() % NUMBER_OF_COLORS;
		length = strlen(colors[index]);
		secretWord = malloc(length * sizeof(char));
		correctLetters = malloc(length * sizeof(char));
		strcpy(secretWord, colors[index]);
	}

	initializeLives(lives, SYMBOL_OF_LIFE);
	initializeCorrectLetters(correctLetters, SYMBOL_OF_NONE, length);

	while(!win && !lose) {
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
