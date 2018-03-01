#include "ex21.h"
#define LEFT(i)(2*i+1)
#define RIGHT(i)(2*i+2) 
#define HEAPSIZE 16

void Heapify(float *array, int i, int heapSize) {
	int l, r, largest;
	float temp;
	l = LEFT(i);
	r = RIGHT(i);
	if (l < heapSize && array[l] > array[i]) 
	{
		largest = l;
	}
	else 
	{
		largest = i;
	}
	if (r < heapSize && array[r] > array[largest]) 
	{
		largest = r;
	}
	if (largest != i) 
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		Heapify(array, largest, heapSize);
	}


}

void BuildHeap(float *array, int sizeArray) {
	int i;
	for (i = (sizeArray - 1) / 2; i >= 0; i--)
		Heapify(array, i, sizeArray);
}


void HeapSort(float *array, int sizeArray) {
	int i;
	float temp;
	int heapSize = sizeArray;
	BuildHeap(array, sizeArray);
	for (i = sizeArray - 1; i>0; i--) {
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		Heapify(array, 0, --heapSize);
	}
}

void heapsort_run() {
	srand(time(NULL));
	int i, c = 0, run = 1;
	
	while (run)
	{
		///// wlasciwy program:
		float arr[HEAPSIZE];
		boldf("tablica do sortowania:");
		for (i = 0; i < HEAPSIZE; i++) {
			//arr[i] = rand() / (float)RAND_MAX; /*(float)(2 + 1)*/
			arr[i] = (float)rand() / (float)(RAND_MAX/9);
			printf("%f  ", arr[i]);
		}
		printf("\n\n");
		boldf("tablica posortowana:");
		HeapSort(arr, HEAPSIZE);
		for (i = 0; i < HEAPSIZE; i++) {
			printf("%f  ", arr[i]);
		}
		/////

		printf("\n\n");
		boldf("Zakonczono sortowanie przez kopcowanie");
		printf("\n Wcisnij 'z' aby powrocic do menu glownego lub 'r' aby powtorzyc sortowanie\n na nowej tablicy");
		c = _getch();
		switch (c) {
		case 'r':
			system("cls");
			break;
		case 'z':
			run = 0;
			_getch();
			system("cls");
			break;
		default:
			boldf("Wybrano nieprawidlowa opcje, sprobuj ponownie");
			_getch();
			system("cls");
			break;
		}
	}
}