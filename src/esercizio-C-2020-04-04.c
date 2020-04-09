#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float avg(int* arr, int bound)
{
	int sum = 0;
	for (int i = 0; i < bound; i++)
		sum += arr[i];

	/*
	 * 'bound' here is the index of the first unwritten
	 * cell of the array, thus can be used as the total
	 * number of elements we are calculating the average of.
	 * It gets automatically promoted to float
	 * due to the casting of 'sum'.
	 */
	return ((float)sum/bound);
}

int main (int argc, char* argv[])
{
	char c;
	int i = 0, len = 5, count = 0;
	int* lengths = calloc(len, sizeof(int));
	if (lengths == NULL) {
		perror("calloc() failed!");
		exit(EXIT_FAILURE);
	}

	while ((c = getchar()) > 0) {
		if (i == len - 1) {
			len += 5;
			int* ptr = realloc(lengths, len * sizeof(int));
			if (ptr == NULL) {
				perror("realloc() failed!");
				exit(EXIT_FAILURE);
			}
			lengths = ptr;
			memset(lengths + i + 1, 0, 5);
		}
		if (c == '\n') {
			lengths[i++] = count;
			printf("Input line length: %d\n", count);
			printf("Current average line length: %f\n", avg(lengths, i));
			count = 0;
			continue;
		}
		count++;
	}

	printf("\nFinal average line length: %f\n", avg(lengths, i));

	return 0;
}
