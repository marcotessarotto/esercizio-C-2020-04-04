/***********TESTO ESERCIZIO***************
scrivere un programma che legge da stdin una riga alla volta (la riga si considera terminata dal carattere \n).

la lunghezza della riga è arbitraria, non fare ipotesi sulla massima lunghezza di riga.
[in questo esercizio, non occorre immagazzinare l'intera riga].

calcolare la media della lunghezza (=numero di caratteri) delle righe lette che vengono lette da stdin.

dopo ogni riga letta, mostrare la lunghezza della riga e la media "parziale" fino a quel momento.

il programma termina in caso di EOF su stdin.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int c;
	int count_tot = 0;		//contatore per il numero totale di caratteri su tutte le righe
	int count_current = 0;	//contatore per il numero di caratteri su una riga
	int n_righe = 0;		//contatore per il numero di righe
	float media;			//media parziale del numero di caratteri su tutte le righe

	printf("Inserisci del testo : \n");

	while ((c = getchar()) != EOF) {
		count_current++;

		if(c == '\n'){
			n_righe++;
			count_tot += count_current;
			media = (float)(count_tot) / (float)(n_righe);

			printf("\nRiga numero %d, lunghezza = %d caratteri, media parziale di caratteri = %f\n", n_righe, count_current, media);

			count_current = 0;
		}
	}
}
