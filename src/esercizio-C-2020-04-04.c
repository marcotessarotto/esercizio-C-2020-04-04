/*scrivere un programma che legge da stdin una riga alla volta (la riga si considera terminata dal carattere \n).

la lunghezza della riga è arbitraria, non fare ipotesi sulla massima lunghezza di riga.
[in questo esercizio, non occorre immagazzinare l'intera riga].

calcolare la media della lunghezza (=numero di caratteri) delle righe lette che vengono lette da stdin.

dopo ogni riga letta, mostrare la lunghezza della riga e la media "parziale" fino a quel momento.

il programma termina in caso di EOF su stdin.*/


#include <stdio.h>


int main(int argc, char *argv[]) {

	char c;
	double media=0;
	unsigned int riga_counter=0;
	unsigned int c_counter=0;

	while((c=getchar())!=EOF){
		if(c=='\n'){
			//mi è arrivata la prima riga
			riga_counter++;
			media=media+(c_counter-media)/riga_counter;
			printf("\nLa riga è lunga %u, in media le righe che ho letto sono lunghe %.2lf\n", c_counter, media);
			c_counter=0;
		}
		else{
			//conto la lughezza della riga
			c_counter++;
		}
	}

	printf("\nIn media le righe sono state lunghe %.2lf\n", media);

	return 0;
}
