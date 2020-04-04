//
/*
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

int i=0,cont=0, c, arraysize=1;

int * val = calloc(arraysize, sizeof(int));

if (val == NULL) {
	perror("calloc error!");
	exit(EXIT_FAILURE);
}

while((c=getchar())!= EOF)
{
	if(c!='\n')
			cont++;
	else
	{
		val[i]=cont;
		arraysize++;
		val = realloc(val,(arraysize)*sizeof(int));
		i++;
		printf("La lunghezza della riga è:%d\n", cont);
		cont=0;
		double somma=0,double media;
    
		for(int j=0; j<arraysize-1;j++)
			somma = somma + val[j];
      
		media=somma/(arraysize-1);
		printf("La media delle righe lette finora:%f\n", media);

	}

}

free(val);

return 0;
}
