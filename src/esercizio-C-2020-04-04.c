/** ex 2020-04-04 */
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

	int l_somma = 0;
	int l_cnt = 0;
	int c_len = 0;
	char next;

	while((next = getchar()) != EOF) {
		if (next != '\n') {
			c_len ++;
		} else {
			l_somma += c_len;
			l_cnt ++;
			printf("Line length: %d (current avg.: %f)\n", c_len, (double)l_somma / (double) l_cnt);
			c_len = 0;
		}
	}
}
