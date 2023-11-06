#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// 정렬 정의
#define		MAX_ARRAY		10
#define		MAX_RAND		100
#define		TEST			7			// min = 0, max = 1, bubble = 2, select = 3, insert = 4, merge = 5
										// quick = 6, stack = 7

// func 배열
int ary[];

// lib 배열, 정수
int tempAry[];
int top;
int bottom;

// lib 함수
void randAry();
void printAry();
void exchange(int i, int j);
int checkAry();
int push(int value);
int pop();
void stack();

// func 함수
void Min();
void Max();
void bubbleSort();
void selectSort();
void insertSort();
void merge(int left, int mid, int right);
void mergeSort(int left, int right);
int quick(int left, int right);
void quickSort(int left, int right);

#endif