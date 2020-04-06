/*scrivere un programma che legge da stdin una riga alla volta
 * (la riga si considera terminata dal carattere \n).
 * la lunghezza della riga è arbitraria, non fare ipotesi sulla massima lunghezza di riga.
 * [in questo esercizio, non occorre immagazzinare l'intera riga].
 * calcolare la media della lunghezza (=numero di caratteri) delle righe lette
 * che vengono lette da stdin.
 * dopo ogni riga letta, mostrare la lunghezza della riga e la media "parziale" fino a quel momento.
 * il programma termina in caso di EOF su stdin.
 * */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include <unistd.h>
#include <errno.h>

unsigned long int averange=0;
unsigned long int pastAverange=0;
unsigned long int computeAverange(unsigned long int charNumber, unsigned long int lineNumber);


int main(int argc, char **argv) {

	int c;
	unsigned long int char_counter=0;
	unsigned long int line_counter=1;
	printf("Inserire una riga: \n");
	while((c=getchar())!=EOF){

		if(c=='\n'){

			printf("La media di caratteri è: %ld",computeAverange(char_counter, line_counter));
			line_counter++;
			printf("\n-------- Riga %ld --------\n",line_counter);
			printf("Inserire del testo: \n");
			char_counter=0;
		}else
			char_counter++;
	}

	return EXIT_SUCCESS;

}

unsigned long int computeAverange(unsigned long int charNumber, unsigned long int lineNumber) {
	unsigned long int result=0;
	if(lineNumber == 1){
		pastAverange=charNumber;
		return charNumber;
	}
	else if (charNumber == 0)
		return pastAverange;
	else
		result = ((pastAverange*(lineNumber-1))+charNumber)/lineNumber;

	pastAverange = result;

	return result;
}
