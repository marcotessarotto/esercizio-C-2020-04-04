#include <stdio.h>

int main(int argc, char *argv[]) {
	char inputChar;
	int numberOfLine = 1;
	int index = 0;
	double average;
	printf("inserisci le stringhe separate dal carattere spazio:");
	while ((inputChar = getchar()) != EOF) {
		if (inputChar != '\n')
			index++; //counting number of char
		else { // new line
			if (numberOfLine == 1) //first execution
				average = index;
			else
				average = (average + index) / 2;
			printf(
					"la lunghezza della linea corrente è:%d \nla media parziale è: %.2f\n",
					index, average);
			index = 0; //reset number of char
			numberOfLine++;
		}
	}
	printf("EOF raggiunto");
	return 0;
}
