// Diaa Nehme  IN0500345  esercizio20200404

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int character;
  unsigned int sentenceChar = 0; // counter for the number of characters on a line
  unsigned int totChar = 0; // counter for the total number of characters
  unsigned int numLines = 0; // counter for the number of lines
  double partialAverage = 0; // partial average of the number of characters on all lines

    printf("Insert some sentence : \n");

	while ((character = getchar()) != EOF){
		sentenceChar++;

		if(character == '\n'){
			numLines++;
			totChar += sentenceChar;
			partialAverage = (double) (totChar) / (double) (numLines);

			printf("\nLine number %u, length = %u Chars, partial average of chars = %lf\n", numLines, sentenceChar, partialAverage);

			sentenceChar = 0;
		}
	}
}
