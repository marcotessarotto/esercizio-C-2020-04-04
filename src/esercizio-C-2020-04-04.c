#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int c;
	int conta_char=0;
	int conta_string=0;
	float media_attuale;
	float sum=0;

	while ((c = getchar()) != EOF){

		if(c != '\n'){
			conta_char++;
		}
		else{conta_string++;
		sum = sum + conta_char;
		media_attuale = sum/conta_string;
		printf("Media alla riga %d = %f\n", conta_string, media_attuale);
		conta_char = 0;
		}
	}
	printf("Ciao ciao!\n");
	return 0;

}
