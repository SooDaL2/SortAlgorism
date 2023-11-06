#include "header.h"

int main() {

	int test = TEST;

	srand(time(NULL));

	randAry();

	switch (test) {
		case 0 :
			Min();
			break;
		case 1 :
			Max();
			break;
		case 2 :
			bubbleSort();
			printAry();
			break;
		case 3 :
			selectSort();
			printAry();
		case 4 :
			insertSort();
			printAry();
		case 5 :
			mergeSort(0, MAX_ARRAY - 1);
			printAry();
		case 6 :
			quickSort(0, MAX_ARRAY - 1);
			printAry();
		case 7 :
			stack();
			printAry();
		default:
			break;
	}

}