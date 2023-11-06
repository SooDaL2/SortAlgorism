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

void bubbleSort() {		// 앞에서부터 서로 이웃한 두 값을 비교해나가면서 뒤에서부터 순서대로 정렬

	int i, j;

	for (i = 0; i < MAX_ARRAY; i++) {
		for (j = 0; j < (MAX_ARRAY - 1) - i; j++) {
			if (ary[j] > ary[j + 1]) {
				exchange(j, j + 1);
			}
		}
	}

}

void selectSort() {		// 최소값을 찾아 그 값과 index(위치)로 앞에서부터 순서대로 정렬

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

void insertSort() {		// 기준 index를 하나씩 늘려가며 기준 index 앞의 값들과 비교하여 순서대로 정렬

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

	int tempAry[MAX_ARRAY] = { 0 };	// 비교를 위한 새로운 Ary
	int Lindex, Rindex, Cindex, i;
	Cindex = left;		// tempAry에 대한 Cursor Index
	Lindex = left;		// merge할 ary의 왼쪽 Index
	Rindex = mid + 1;	// merge할 ary의 오른쪽 Index

	while ((Lindex <= mid) && (Rindex <= right)) {	// 현재 나눠진 배열의 크기만큼 대소 비교
		if (ary[Lindex] < ary[Rindex]) {
			tempAry[Cindex++] = ary[Lindex++];
		}
		else {
			tempAry[Cindex++] = ary[Rindex++];
		}
	}

	if (Lindex > mid) {	// 한쪽 배열이 대소 비교에 다 사용됐다면 반대쪽 나머지 배열 입력
		while (Rindex <= right) {
			tempAry[Cindex++] = ary[Rindex++];
		}
	}
	else {
		while (Lindex <= mid) {
			tempAry[Cindex++] = ary[Lindex++];
		}
	}

	// 배열 복사
	for (i = left; i <= right; i++) {
		ary[i] = tempAry[i];
	}

}

void mergeSort(int left, int right) {

	int mid;

	if (left == right) {	// 더 이상 나눌 배열이 없을 경우 함수 종료
		return;
	}

	mid = (left + right) / 2;	// 배열을 절반으로 나눔

	mergeSort(left, mid);		// 왼쪽
	mergeSort(mid + 1, right);	// 오른쪽

	merge(left, mid, right);	// 합병, 정렬

}

int quick(int left, int right) {

	int pivot, low, high;
	int i, j;

	/*
	// do ~ while 문

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
	// while 문
	
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

	
	// for 문
	
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
