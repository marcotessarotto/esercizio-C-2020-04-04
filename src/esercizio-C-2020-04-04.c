/**
 * scrivere un programma che legge da stdin una riga alla volta (la riga si considera terminata dal carattere \n).

la lunghezza della riga è arbitraria, non fare ipotesi sulla massima lunghezza di riga.
[in questo esercizio, non occorre immagazzinare l'intera riga].

calcolare la media della lunghezza (=numero di caratteri) delle righe lette che vengono lette da stdin.

dopo ogni riga letta, mostrare la lunghezza della riga e la media "parziale" fino a quel momento.

il programma termina in caso di EOF su stdin.
 */
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	int l_somma = 0;
	int l_cnt = 0;
	int c_len = 0;
	char next;

	while((next = getchar()) != EOF) {
		if (next != '\n') {
			c_len ++;
		} else {
			l_somma += c_len;
			l_cnt ++;
			printf("Line length: %d (current avg.: %f)\n", c_len, (double)l_somma / (double) l_cnt);
			c_len = 0;
		}
	}
}
