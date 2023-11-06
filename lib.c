#include "header.h"

int tempAry[MAX_ARRAY];
int top = -1;
int bottom = 0;

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

int checkAry() {

	if (top < bottom) {	// empty
		return 1;
	} else if (top >= MAX_ARRAY - 1) {	// full
		return 0;
	}
	else {
		return 3;
	}
	
}

int push(int value) {

	if (checkAry() != 0) {
		tempAry[++top] = value;
	}

}

int pop() {

	int getValue;

	if (checkAry() != 1) {
		return tempAry[top--];
	}
	
}

void stack() {

	int i;

	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	
	pop();
	pop();
	pop();

	for (i = 0; i < MAX_ARRAY; i++) {
		ary[i] = tempAry[i];
	}

}