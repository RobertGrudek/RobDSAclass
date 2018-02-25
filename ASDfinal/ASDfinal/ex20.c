#include "ex20.h"

int * array_randomise(int size)
{
	int *A = malloc(size * sizeof(*A));
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		A[i] = rand();
	}
	return A;
}
//tworze lokalna kopie wygenerowanej tablicy aby sprawdzac algorytmy sortowania na tej samej
int * array_copy(int A[], int size)
{
	int *aux = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		aux[i] = A[i];
	}
	return aux;
}
void array_print(int A[], int size)
{
	for (int i = 0; i < size;)
	{
		printf("\n");
		for (int j = 0; j < 9; j++)
		{
			printf("%-5d, ", A[i]);
			i++;
		}
	}
	printf("\n");
}

//QUICKSORT:
void qs_start(int A[], int size)
{
	int sub = 0, comp = 0;
	int *a = array_copy(A, size);
	quicksort(a, 0, size - 1, &sub, &comp);
	//array_print(a, size); do podejrzenia wyniku sortowania
	printf("\n||| podstawienia: %d |||", sub);
	printf("\n||| porownania: %d |||", comp);
}
int qs_partition(int A[], int l, int r, int *sub, int *comp)
{
	int pivot = A[r];
	int i = l - 1;
	int aux;
	*sub = *sub + 2; //albo 3?
	for (int j = l; j < r; j++)
	{
		if (A[j] <= pivot)
		{
			i++;
			aux = A[i];
			A[i] = A[j];
			A[j] = aux;
			*sub = *sub + 3;
		}
		*comp = *comp + 2; //po jednym dla for i if
	}
	aux = A[i+1];
	A[i+1] = A[r];
	A[r] = aux;
	*sub = *sub + 3;
	return i + 1;
}
void quicksort(int A[], int l, int r, int *sub, int *comp)
{
	(*comp)++;
	if (l < r)
	{
		int index = qs_partition(A, l, r, sub, comp);
		(*sub)++;
		quicksort(A, l, index - 1, sub, comp);
		quicksort(A, index + 1, r, sub, comp);
	}
}
//koniec
//
//
