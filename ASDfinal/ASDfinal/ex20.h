#pragma once
#include "libincludes.h"

void array_print(int A[], int);
int * array_copy(int A[], int);
int * array_randomise(int);

void qs_start(int A[], int size);
int qs_partition(int A[], int l, int r, int *sub, int *comp);
void quicksort(int A[], int l, int r, int *sub, int *comp);

void bubblesort(int A[], int size);

void insertionsort(int A[], int size);

void shellsort_start(int A[], int size);
void shellsort(int A[], int size, int h, int *sub, int *comp);