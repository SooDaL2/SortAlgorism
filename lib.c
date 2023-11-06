#include "header.h"

void randAry() {

	int i, j, k = 0;

	for (i = 0; i < MAX_ARRAY; i++) {
		ary[i] = rand() % MAX_RAND;

		if (ary[i] == 0) {
			i--;
		}

		for (j = 0; j < i; j++) {
			if (ary[i] == ary[j]) {
				i--;
				break;
			}
		}

	}

	// rand check test
	for (i = 0; i < MAX_ARRAY; i++) {
		printf("%d : %d\n", k++, ary[i]);
	}

	printf("\n\n");

}

void exchange(int i, int j) {

	int temp;

	temp = ary[i];
	ary[i] = ary[j];
	ary[j] = temp;

}

void printAry() {

	int i;

	for (i = 0; i < MAX_ARRAY; i++) {
		printf("%d\t", ary[i]);
	}

}