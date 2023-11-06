#include "header.h"

int ary[MAX_ARRAY] = { 0 };

void Min() {

	int i, j, minInt, minIndex;

	minInt = ary[0];

	for (i = 0; i < MAX_ARRAY; i++) {
		for (j = 0; j < i; j++) {
			if (minInt > ary[j]) {
				minInt = ary[j];
				minIndex = j;
			}
		}
	}

	printf("index : %d\t value : %d", minIndex, minInt);

}

void Max() {

	int i, j, maxInt, maxIndex;

	maxInt = ary[0];

	for (i = 0; i < MAX_ARRAY; i++) {
		for (j = 0; j < i; j++) {
			if (maxInt < ary[j]) {
				maxInt = ary[j];
				maxIndex = j;
			}
		}
	}

	printf("index : %d\t value : %d", maxIndex, maxInt);

}

void bubbleSort() {		// �տ������� ���� �̿��� �� ���� ���س����鼭 �ڿ������� ������� ����

	int i, j;

	for (i = 0; i < MAX_ARRAY; i++) {
		for (j = 0; j < (MAX_ARRAY - 1) - i; j++) {
			if (ary[j] > ary[j + 1]) {
				exchange(j, j + 1);
			}
		}
	}

}

void selectSort() {		// �ּҰ��� ã�� �� ���� index(��ġ)�� �տ������� ������� ����

	int i, j, k, minIndex;

	for (i = 0; i < MAX_ARRAY; i++) {
		k = ary[i];
		minIndex = i;
		for (j = i + 1; j < MAX_ARRAY; j++) {
			if (k > ary[j]) {
				minIndex = j;
				k = ary[j];
			}
		}
		exchange(i, minIndex);
	}

}

void insertSort() {		// ���� index�� �ϳ��� �÷����� ���� index ���� ����� ���Ͽ� ������� ����

	int i, j;

	// case 1
	for (i = 0; i < MAX_ARRAY; i++) {
		for (j = i; j >= 0; j--) {
			if (ary[j] < ary[j - 1]) {
				exchange(j, j - 1);
			}
		}
	}

	// case 2
	/*
	for (i = 0; i < MAX_ARRAY; i++) {
		j = i;
		while (j >= 0 && ary[j] < ary[j - 1]) {
			exchange(j, j - 1);
			j--;
		}
	}
	*/

}

void merge(int left, int mid, int right) {

	int tempAry[MAX_ARRAY] = { 0 };	// �񱳸� ���� ���ο� Ary
	int Lindex, Rindex, Cindex, i;
	Cindex = left;		// tempAry�� ���� Cursor Index
	Lindex = left;		// merge�� ary�� ���� Index
	Rindex = mid + 1;	// merge�� ary�� ������ Index

	while ((Lindex <= mid) && (Rindex <= right)) {	// ���� ������ �迭�� ũ�⸸ŭ ��� ��
		if (ary[Lindex] < ary[Rindex]) {
			tempAry[Cindex++] = ary[Lindex++];
		}
		else {
			tempAry[Cindex++] = ary[Rindex++];
		}
	}

	if (Lindex > mid) {	// ���� �迭�� ��� �񱳿� �� ���ƴٸ� �ݴ��� ������ �迭 �Է�
		while (Rindex <= right) {
			tempAry[Cindex++] = ary[Rindex++];
		}
	}
	else {
		while (Lindex <= mid) {
			tempAry[Cindex++] = ary[Lindex++];
		}
	}

	// �迭 ����
	for (i = left; i <= right; i++) {
		ary[i] = tempAry[i];
	}

}

void mergeSort(int left, int right) {

	int mid;

	if (left == right) {	// �� �̻� ���� �迭�� ���� ��� �Լ� ����
		return;
	}

	mid = (left + right) / 2;	// �迭�� �������� ����

	mergeSort(left, mid);		// ����
	mergeSort(mid + 1, right);	// ������

	merge(left, mid, right);	// �պ�, ����

}

int quick(int left, int right) {

	int pivot, low, high;
	int i, j;

	/*
	// do ~ while ��

	low = left;
	high = right + 1;
	pivot = ary[left];
	
	do {
		
		do {
			low++;
		} while ((low < right) && (ary[low] < pivot));
		
		do {
			high--;
		} while ((high > left) && (ary[high] > pivot));

		if (low < high) {
			exchange(low, high);
		}

	} while (low < high);

	exchange(left, high);

	return high;

	*/

	/*
	// while ��
	
	low = left + 1;
	high = right;
	pivot = ary[left];

	while (low <= high) {

		while ((low <= right) && (ary[low] < pivot)) {
			low++;
		}

		while ((high > left) && (ary[high] > pivot)) {
			high--;
		}

		if (low <= high) {
			exchange(low, high);
		}

	}

	exchange(left, high);

	return high;
	*/

	
	// for ��
	
	low = left + 1;
	high = right;
	pivot = ary[left];

	for ( ; low <= high; ) {

		for ( ; (low <= right) && (ary[low] < pivot); ) {
			low++;
		}

		for ( ; (high > left) && (ary[high] > pivot); ) {
			high--;
		}

		if (low <= high) {
			exchange(low, high);
		}

	}

	exchange(left, high);

	return high;
	
}

void quickSort(int left, int right) {

	int standard;

	if (left < right) {
		
		standard = quick(left, right);

		quickSort(left, standard - 1);
		quickSort(standard + 1, right);

	}

}
