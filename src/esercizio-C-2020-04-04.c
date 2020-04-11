#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
	scrivere un programma che legge da stdin una riga alla volta (la riga si considera terminata dal carattere \n).
	la lunghezza della riga è arbitraria, non fare ipotesi sulla massima lunghezza di riga.
	[in questo esercizio, non occorre immagazzinare l'intera riga].
	calcolare la media della lunghezza (=numero di caratteri) delle righe lette che vengono lette da stdin.

	dopo ogni riga letta, mostrare la lunghezza della riga e la media "parziale" fino a quel momento.
	il programma termina in caso di EOF su stdin.
*/

int main(int argc, char *argv[]){

	unsigned int lines_counter=0;
	unsigned int char_counter=0;
	unsigned int sum=0;
	char ch;
	double average;


	printf("Digita dei caratteri, '\\n' per inserire nuove righe: ");

	while( (ch=getchar()) != EOF ){
		if ( ch == '\n'){
			lines_counter++;
			sum += char_counter;
			printf("character sum= %u\n", sum);
			average = (double) sum / lines_counter;

			printf("riga: %u, numero di caratteri= %u, media= %1.2f\n", lines_counter,char_counter, average);
			printf("*****************************\n");
			//printf("char_counter= %u", char_counter);
			char_counter=0;
		}
		else{
			char_counter++;
		}
	}


	return EXIT_SUCCESS;
}

