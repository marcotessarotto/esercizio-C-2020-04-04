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
int media(int * array, int numero_righe){
	int sum = 0;

	for(int i=0; i<numero_righe; i++){
		sum += array[i];
	}

	float media = 0.0;

	media = (sum*1.0)/numero_righe;

	return media;

}

void prendi_caratteri(int * array, int indice){

	int counter = 1;
	int c ;

	while((c=getchar()) != '\n'){
		counter++;
	}
	array[indice] = counter;

	float medio = 0.0;

	medio = media(array, indice+1);

	printf("la riga appena inserita misura %d\n", counter);

	printf("Al momento la media è: %.2f\n", medio);

}



int main(){

	printf("Scrivi un paio di righe di caratteri, calcolerò il numero medio di caratteri per riga\n");

	int * array;
	int size = 10;
	array = calloc(10, sizeof(int));
	int c;
	int indice = 0;

	while((c=getchar()) != EOF){
		prendi_caratteri(array, indice);
		indice++;

		if(indice>size){
			array = realloc(array, indice*sizeof(int));
			size = indice;

			if(array == NULL){
				perror("realloc()");

				exit(EXIT_FAILURE);
			}
		}
	}
	free(array);

	printf("Ricevuto, ora terminerò!");

	return 0;

}
