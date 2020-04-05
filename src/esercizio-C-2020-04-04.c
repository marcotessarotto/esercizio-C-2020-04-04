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
#include<locale.h>
#include<stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char * argv[]) {
	char ch='a';
	int count_char=0;
	float count_temp=0.0;
	int count_righe=0;
    float media_parziale=0;
while(ch != EOF){
	printf("\nscrivi una riga\n");

	count_temp=media_parziale;
	count_char=0;
do{
	ch=getchar();
	count_char++;
}while (ch !='\n' && ch != EOF);
count_righe++;
if(count_righe==1){
	printf("nr di caratt di righa %d è %d\n",count_righe,count_char);
	printf("media parziale è %d\n",count_char);
	media_parziale=count_char;

}
else {
media_parziale=(count_char+count_temp)/2;
printf("nr di caratt di righa %d è %d\n",count_righe,count_char);
printf("media parziale è %f\n",(count_char+count_temp)/2.);
}
}




	return 0;
}
