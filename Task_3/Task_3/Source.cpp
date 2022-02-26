#include<iostream>
#include<stdlib.h>
#include<time.h>

template<typename T>
void initArray(T *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = (25 + rand() % 90) * 0.25;
	}
}

template<typename T>
void printArray(T *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void copy(T *a, T *b)
{
	*a = *b;
}

template<typename T>
void copyArray(T *array_1, T *array_2, T *array_3, int length_1, int length_2, int length_3)
{
	int i = 0;
	for (int j = 0; j < length_2; j++, i++)
	{
		copy(&array_1[i], &array_2[j]);
	}
	for (int j = 0; j < length_3; j++, i++)
	{
		copy(&array_1[i], &array_3[j]);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH_A = 10;
	int array_A[LENGTH_A];
	initArray(array_A, LENGTH_A);
	printArray(array_A, LENGTH_A);

	const int LENGTH_B = 11;
	int array_B[LENGTH_B];
	initArray(array_B, LENGTH_B);
	printArray(array_B, LENGTH_B);

	std::cout << std::endl;

	const int LENGTH_C = LENGTH_A + LENGTH_B;
	int array_C[LENGTH_C];
	copyArray(array_C, array_A, array_B, LENGTH_C, LENGTH_A, LENGTH_B);
	printArray(array_C, LENGTH_C);
}