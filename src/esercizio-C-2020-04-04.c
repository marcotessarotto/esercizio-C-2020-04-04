
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {

	char c;
	float n_righe = 0;
	int len_riga = 0;
	float cTot = 0;
	float media;


	while((c=getchar()) != EOF){

		if (c == '\n'){
			printf("La lunghezza della riga seguente è pari a: %d \n", len_riga);
			n_righe++;
			media = (cTot/n_righe);
			printf("La media per ogni riga fino ad ora è pari a: %.2f \n", media);
			//imposto a -1 e non ha zero per non contare \n
			len_riga =-1;
			// per lo stesso motivo decremento cTot
			cTot --;
			printf("_____________________________________\n\n");

		}

		cTot++;
		len_riga++;


	}

}
