#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

float media (float * array, int x){
	float totale=0;
	for (int i=0;i<x;++i)
		totale+=array[i];
	return totale/(float)x;
}



int main(int argc, char **argv) {
	char c;
	int counter=0;
	int num_righe=0;
	float * length_righe;

	length_righe=malloc(sizeof(float));



	while((c=getchar())!=EOF){

		if(c!='\n')
			++counter;
		else{

			length_righe[num_righe]=(float)counter;

			++num_righe;
			printf("Lunghezza ultima riga= %d\n",counter);
			printf("Media parziale= %f\n\n",media(length_righe,num_righe));

			counter=0;
			realloc(length_righe,num_righe*sizeof(float));
		}
	}
	printf("\nMedia totale= %f",media(length_righe,num_righe));

	return 0;
}
