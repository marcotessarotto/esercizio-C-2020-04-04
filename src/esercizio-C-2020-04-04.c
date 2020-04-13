#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 scrivere un programma che legge da stdin una riga alla volta
 (la riga si considera terminata dal carattere \n).

la lunghezza della riga è arbitraria, non fare ipotesi sulla massima lunghezza di riga.
[in questo esercizio, non occorre immagazzinare l'intera riga].

calcolare la media della lunghezza (=numero di caratteri) delle righe lette che vengono lette da stdin.

dopo ogni riga letta, mostrare la lunghezza della riga e la media "parziale" fino a quel momento.

il programma termina in caso di EOF su stdin.
 */

int main(int argc, char *argv[]) {

	int ch;
	int current_line_len = 0;
	double line_len_average = 0;
	int line_counter = 1;


	// incremental average:
	// m(n) = m(n-1) + (a(n) - m(n-1)) / n

	// vedere anche progetto 004.4pass-to-array-function

	while ((ch = getchar()) != EOF) {

		switch (ch) {
		case '\n':

			line_len_average = line_len_average + (current_line_len - line_len_average) / line_counter;

			printf("line length: %d, line length average: %.2f\n", current_line_len, line_len_average);

			current_line_len = 0;
			line_counter++;
			break;
		default:
			current_line_len++;
		}

	}

	printf("bye!\n");

	return 0;
}
