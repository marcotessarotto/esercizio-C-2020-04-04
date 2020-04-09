#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_OF_CHAR 30
double averageLength;

int lenghtOfArray(char *charArray, int arrayLength) {
	int counter = 0;
	for (int i = 0; i < arrayLength; i++) {
		if (charArray[i] != 0) {
			counter++;
		}
	}
	return counter;
}

int main(int argc, char *argv[]) {
	char inputChar;
	char *currentLine = calloc(NUM_OF_CHAR, sizeof(char));
	int index = 0;
	int indexLength = 1; //used for count how many time realloc was invoked in order to give back the correct memory spaces
	int numOfLine = 0;
	printf("inserisci linee di caratteri separate dal carattere spazio \n");

	while ((inputChar = getchar()) != EOF) {
		if (index == (NUM_OF_CHAR * indexLength)) {
			indexLength++;
			if ((realloc(currentLine, NUM_OF_CHAR * indexLength)) == NULL) {
				perror("realloc error!");
				exit(EXIT_FAILURE);
			}
		}
		if (inputChar != '\n') {
			currentLine[index] = inputChar;
			index++;
		} else {
			numOfLine++;
			int lengthOfCurrentLine = lenghtOfArray(currentLine,
			NUM_OF_CHAR * indexLength);
			if (numOfLine == 1) {
				averageLength = lengthOfCurrentLine;
			}
			averageLength = (averageLength + lengthOfCurrentLine) / 2;
			printf(
					"la lunghezza della linea corrente è:%d \nla media parziale è: %.2f\n",
					lengthOfCurrentLine, averageLength);
			memset(currentLine, 0, sizeof(char) * (NUM_OF_CHAR * indexLength));
			index = 0;
			indexLength = 1;
			if ((realloc(currentLine, NUM_OF_CHAR * indexLength)) == NULL) {
				perror("realloc error!");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(currentLine);
	return 0;
}
