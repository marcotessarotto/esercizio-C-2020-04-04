#include <stdio.h>

/*

scrivere un programma che legge da stdin una riga alla volta (la riga si considera terminata dal carattere \n).

la lunghezza della riga è arbitraria, non fare ipotesi sulla massima lunghezza di riga.
[in questo esercizio, non occorre immagazzinare l'intera riga].

calcolare la media della lunghezza (=numero di caratteri) delle righe lette che vengono lette da stdin.

dopo ogni riga letta, mostrare la lunghezza della riga e la media "parziale" fino a quel momento.

il programma termina in caso di EOF su stdin.

*/
void print(int counter);

unsigned long average;
unsigned int row_counter;

int main(int argc, char *argv[]) {
	int c;
	unsigned long counter = 0;

	printf("Insert text: ");

	while ((c = getchar()) != EOF) {

		if (c == '\n') {
			row_counter++;
			average += counter;
			print(counter);
			counter = 0;
			printf("Insert text: ");
		} else {
			counter++;
		}
	}
}

void print(int counter) {
	printf("Number of character on the row: %d\nCurrent average: %ld\n", counter, (average / row_counter));
}

