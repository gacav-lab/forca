#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define NUMBER_OF_ADJECTIVES 31
#define NUMBER_OF_COLORS 16
#define NUMBER_OF_COUNTRIES 30
#define NUMBER_OF_FRUITS 15
#define NUMBER_OF_TOPICS 4
#define TOTAL_LIVES 5

/*
x=================================================x
| Autor: Gabriel Cavalcante de Jesus Oliveira     |
| Data: 28/08/2022                                |
| Linguagem de programação: C                     |
| Versão da linguagem: C17                        |
| Compatível com: sistemas Unix-like              |
| Compilador: GCC                                 |
| Github: https://github.com/gabrielcavalcante-cs |
x=================================================x
*/

void title(void);
void initializeLives(char *lives, const char SYMBOL);
void initializeCorrectLetters(char *correctLetters, const char SYMBOL, int stringLength);
void wasAllocated(char *array);

int main(int argc, char **argv) {
	char countries[][11] = {
		"Brasil", "Alemanha", "Dinamarca", "Equador", "Mexico", "Espanha",
		"Chile", "Bolivia", "Portugal", "Madagascar", "Japao", "China",
		"Brunei", "Italia", "Canada", "Franca", "Catar", "Croacia",
		"Eslovenia", "Egito", "Honduras", "Hungria", "Idonesia", "India",
		"Ira", "Iraque", "Jamaica", "Nepal", "Nicaragua", "Nigeria"
	}, fruits[][11] = {
		"Pitanga", "Acerola", "Tomate", "Manga", "Abacaxi", "Melancia",
		"Morango", "Banana", "Maracuja", "Melao", "Cacau", "Pessego",
		"Abacate", "Mamao", "Maracujina"
	}, colors[][10] = {
		"Azul", "Ciano", "Amarelo", "Roxo", "Rosa", "Dourado", "Carmesim",
		"Carmim", "Escarlate", "Marrom", "Cinza", "Preto", "Branco",
		"Laranja", "Vermelho", "Verde"
	}, adjectives[][15] = {
		"Bonito", "Alto", "Elegante", "Formoso", "Inteligente",
		"Carismatico", "Compreensivo", "Reflexivo", "Pensativo", "Forte",
		"Talentoso", "Agradavel", "Cheiroso", "Aplicado", "Companheiro",
		"Determinado", "Educado", "Escrupuloso", "Extraordinario",
		"Habilidoso", "Genuino", "Independente", "Maravilhoso",
		"Organizado", "Perseverante", "Persistente", "Perspicaz",
		"Valoroso", "Verdadeiro", "Zeloso", "Cuidadoso"
	}, *secretWord = NULL, *correctLetters = NULL, *lives = NULL, *topic = NULL, kick;
	const char SYMBOL_OF_LIFE = '@', SYMBOL_OF_NONE = '~';
	bool win = false, lose = false, correct;
	const int SCORE_RATE = 218, BONUS_RATE = 18;
	int stringLength, indexLives = TOTAL_LIVES - 1, topicIndex, index, score = SCORE_RATE * TOTAL_LIVES, bonus = 0;

	lives = malloc(TOTAL_LIVES * sizeof(char));
	wasAllocated(lives);

	srand(time(NULL));

	enum TOPIC {
		topicCountries,
		topicFruits,
		topicColors
	} raffledTopic;

    raffledTopic = rand() % NUMBER_OF_TOPICS;

	if(raffledTopic == topicCountries) {
		topic = "paises";
		index = rand() % NUMBER_OF_COUNTRIES;
		stringLength = strlen(countries[index]);
		secretWord = malloc(stringLength * sizeof(char));
		wasAllocated(secretWord);
		correctLetters = malloc(stringLength * sizeof(char));
		wasAllocated(correctLetters);
		strcpy(secretWord, countries[index]);
	} else if(raffledTopic == topicFruits) {
		topic = "frutas";
		index = rand() % NUMBER_OF_FRUITS;
		stringLength = strlen(fruits[index]);
		secretWord = malloc(stringLength * sizeof(char));
		wasAllocated(secretWord);
		correctLetters = malloc(stringLength * sizeof(char));
		wasAllocated(correctLetters);
		strcpy(secretWord, fruits[index]);
	} else if(raffledTopic == topicColors) {
        topic = "cores";
        index = rand() % NUMBER_OF_COLORS;
		stringLength = strlen(colors[index]);
		secretWord = malloc(stringLength * sizeof(char));
		wasAllocated(secretWord);
		correctLetters = malloc(stringLength * sizeof(char));
		wasAllocated(correctLetters);
		strcpy(secretWord, colors[index]);
	} else {
		topic = "adjetivos";
		index = rand() % NUMBER_OF_ADJECTIVES;
		stringLength = strlen(adjectives[index]);
		secretWord = malloc(stringLength * sizeof(char));
		wasAllocated(secretWord);
		correctLetters = malloc(stringLength * sizeof(char));
		wasAllocated(correctLetters);
		strcpy(secretWord, adjectives[index]);
	}

	initializeLives(lives, SYMBOL_OF_LIFE);
	initializeCorrectLetters(correctLetters, SYMBOL_OF_NONE, stringLength);

	for(int counter = 0; counter < stringLength; counter++) {
		bonus += BONUS_RATE;
	}

	score += bonus;

	while(!win && !lose) {
		system("clear");
		title();
		correct = false;

		printf("%s\n\n", correctLetters);
		printf("Tópico: %s\n", topic);
		printf("Vidas: %s\n", lives);
		printf("Chute: ");
		scanf("%c", &kick);

		for(int i = 0; i < stringLength; i++) {
			if(toupper(kick) == toupper(secretWord[i])) {
				correctLetters[i] = kick;
				correct = true;
			}
		}

		if(!correct) {
			lives[indexLives--] = ' ';
			score -= SCORE_RATE;
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

void initializeCorrectLetters(char *correctLetters, const char SYMBOL, int stringLength) {
	for(int i = 0; i < stringLength; i++) {
		*(correctLetters + i) = SYMBOL;
	}
}
