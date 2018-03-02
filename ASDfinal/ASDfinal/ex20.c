#include "ex20.h"
//Porownac wydajnosc sortowania metodami: bubblesort, przez wstawianie, metoda Shell i quick sort.
int * array_randomise(int size)
{
	int *A = malloc(size * sizeof(*A));
	int i;
	//srand((unsigned)time(NULL));

	for (i = 0; i < size; i++)
	{
		A[i] = rand();
		//A[i] = rand() % (9999 + 1 - 0) + 0;
	}
	return A;
}
//tworze lokalna kopie wygenerowanej tablicy aby sprawdzac algorytmy sortowania na tej samej
int * array_copy(int _A[], int size)
{
	int *aux = malloc(size * sizeof(int));
	int i;

	for (i = 0; i < size; i++)
	{
		aux[i] = _A[i];
	}
	return aux;
}
void array_print(int _A[], int size)
{
	for (int i = 0; i < size;)
	{
		printf("\n");
		for (int j = 0; j < 9; j++)
		{
			if (i < size)
			{
				printf("%-5d, ", _A[i]);
			}
			i++;
		}
	}
	printf("\n");
}
//BUBBLE SORT:
void bubblesort(int _A[], int size)
{
	int *A = array_copy(_A, size);
	int i, j, aux;
	int sub = 0, comp = 0;

	for (i = 1; i < size; i++)
	{
		comp++;
		for (j = size - 1; j >= i; j--)
		{
			comp++;
			if (A[j - 1] > A[j])
			{
				aux = A[j - 1];
				A[j - 1] = A[j];
				A[j] = aux;
				comp++;
				sub = sub + 3;
			}
			sub++;
		}
		sub++;
	}
	printf("||| podstawienia: %d |||", sub);
	printf("\n||| porownania: %d |||\n", comp);
	//array_print(A, size); do podejrzenia wyniku sortowania
}
//koniec
//
//INSERTION SORT:
void insertionsort(int _A[], int size)
{
	int *A = array_copy(_A, size);
	int i, j, aux;
	int sub = 0, comp = 0;

	for (i = 1; i < size; i++)
	{
		if (A[i] < A[0])
		{
			aux = A[0];
			A[0] = A[i];
			sub = sub + 2;
		}
		else
		{
			aux = A[i];
			sub++;
		}
		comp = comp + 2;
		for (j = i - 1; aux < A[j]; j--)
		{
			A[j + 1] = A[j];
			comp++;
			sub = sub + 2;
		}
		A[j + 1] = aux;
		sub = sub + 2;
	}
	printf("||| podstawienia: %d |||", sub);
	printf("\n||| porownania: %d |||\n", comp);
}
//koniec
//
//SHELLSORT:
void shellsort(int _A[], int size, int h, int *sub, int *comp) {
	int i;

	for (i = h; i < size; ++i) {
		int value = _A[i];
		(*comp)++;
		(*sub)++;
		int j;
		for (j = i - h; j >= 0 && _A[j] > value; j -= h) {
			_A[j + h] = _A[j];
			(*comp)++;
			(*sub)++;
		}
		_A[j + h] = value;
		(*sub)++;
	}
}     
void shellsort_start(int _A[], int size) {
	int *A = array_copy(_A, size);
	static const int h[] = {
		1, 4, 10, 23, 57, 132, 301, 701, 1750 //sekwencja Marcina Ciury http://sun.aei.polsl.pl/~mciura/
	};
	int sizeIndex;
	int sub = 0, comp = 0;

	for (sizeIndex = sizeof(h) / sizeof(h[0]) - 1; sizeIndex >= 0; --sizeIndex)
		comp++;
		shellsort(A, size, h[sizeIndex], &sub, &comp);

	//array_print(A, size);
	printf("||| podstawienia: %d |||", sub);
	printf("\n||| porownania: %d |||\n", comp);
}
//koniec
//
//QUICKSORT:
void qs_start(int _A[], int size)
{
	int sub = 0, comp = 0;
	int *a = array_copy(_A, size);

	quicksort(a, 0, size - 1, &sub, &comp);
	printf("||| podstawienia: %d |||", sub);
	printf("\n||| porownania: %d |||\n", comp);
}
int qs_partition(int _A[], int l, int r, int *sub, int *comp)
{
	int pivot = _A[r];
	int i = l - 1;
	int j;
	int aux;
	*sub = *sub + 2; 

	for (j = l; j < r; j++)
	{
		if (_A[j] <= pivot)
		{
			i++;
			aux = _A[i];
			_A[i] = _A[j];
			_A[j] = aux;
			*sub = *sub + 3;
		}
		*comp = *comp + 2; //po jednym dla for i if
	}
	aux = _A[i + 1];
	_A[i + 1] = _A[r];
	_A[r] = aux;
	*sub = *sub + 3;
	return i + 1;
}
void quicksort(int _A[], int l, int r, int *sub, int *comp)
{
	(*comp)++;
	if (l < r)
	{
		int index = qs_partition(_A, l, r, sub, comp);
		(*sub)++;
		quicksort(_A, l, index - 1, sub, comp);
		quicksort(_A, index + 1, r, sub, comp);
	}
}
//koniec
