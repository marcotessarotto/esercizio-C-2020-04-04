#include <stdio.h>
#include <stdlib.h>


int tot_length = 0;
int tot_lines = 0;

void mean_char() {
	int mean = tot_length/tot_lines;
	printf("\nLa media di caratteri per ogni riga è: %d\n", mean);
}

void count_char(int counter){
	char c;
	while((c = getchar())!= '\n'){
		counter++;
	}
	printf("\nLa riga inserita ha %d caratteri.\n", counter);
	tot_length += counter;
	tot_lines++;
	mean_char();
	counter = 0;
	count_char(counter);
}


int main (int argc, char * argv[]) {
	printf("Scrivere tutto ciò che si vuole:\n");
	char input;
	while((input = getchar()) != EOF){
		int counter = 1;  
    /* ho dovuto impostare per la prima esecuzione di count_char il counter ad 1 
     * poichè tendeva a calcolare un carattere in meno nella prima riga che veniva
     * inserita, nelle altre non si presentava il problema.
     */
		count_char(counter);
	}

	return 0;
}
