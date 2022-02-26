#include<iostream>
#include<stdlib.h>
#include<time.h>

template<typename T>
void initArray(T *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		*(array + i) = (10 + rand() % 90) * 0.25;
	}
}

template<typename T>
void printArray(T *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << *(array + i) << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void swap(T *a, T *b)
{
	T variable = *a;
	*a = *b;
	*b = variable;
}

template<typename T>
void sortArray(T *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j > 0 && *(array + (j - 1)) > *(array + j); j--)
		{
			swap(&(*(array + (j - 1))), &(*(array + j)));
		}
	}
}

template<typename T>
void copyArray(T *array_1, T *array_2, T *array_3, int length_1, int length_2, int length_3)
{
	int i = 0;
	for (int j = 0; j < length_2; i++, j++)
	{
		if (i < length_1)
		{
			*(array_1 + i) = *(array_2 + j);
		}
	}
	for (int j = 0; j < length_3; i++, j++)
	{
		if (i < length_1)
		{
			*(array_1 + i) = *(array_3 + j);
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH_1 = 7;
	int array_1[LENGTH_1];
	initArray(array_1, LENGTH_1);
	printArray(array_1, LENGTH_1);
	sortArray(array_1, LENGTH_1);
	printArray(array_1, LENGTH_1);

	std::cout << std::endl;

	const int LENGTH_2 = 8;
	int array_2[LENGTH_2];
	initArray(array_2, LENGTH_2);
	printArray(array_2, LENGTH_2);
	sortArray(array_2, LENGTH_2);
	printArray(array_2, LENGTH_2);

	std::cout << std::endl;

	const int LENGTH_3 = LENGTH_1 + LENGTH_2;
	int array_3[LENGTH_3];
	copyArray(array_3, array_1, array_2, LENGTH_3, LENGTH_1, LENGTH_2);
	printArray(array_3, LENGTH_3);
	sortArray(array_3, LENGTH_3);
	printArray(array_3, LENGTH_3);

	return 0;
}