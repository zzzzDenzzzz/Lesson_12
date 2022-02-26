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
void swap(T *a, T *b)
{
	T variable = *a;
	*a = *b;
	*b = variable;
}

template<typename T>
int copyArray(T *array_1, T *array_2, T *array_3, int length_2, int length_3)
{
	int k = 0;
	for (int i = 0; i < length_2; i++)
	{
		int match_count = 0;
		for (int j = 0; j < length_3; j++)
		{
			if (array_2[i] == array_3[j])
			{
				match_count++;
			}
		}
		if (match_count == 0)
		{
			copy(&array_1[k], &array_2[i]);
			k++;
		}
	}

	return k;
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH_A = 20;
	int array_A[LENGTH_A];
	initArray(array_A, LENGTH_A);
	printArray(array_A, LENGTH_A);

	const int LENGTH_B = 14;
	int array_B[LENGTH_B];
	initArray(array_B, LENGTH_B);
	printArray(array_B, LENGTH_B);

	std::cout << std::endl;

	const int LENGTH_C = LENGTH_A + LENGTH_B;
	int array_C[LENGTH_C];
	int length = copyArray(array_C, array_A, array_B, LENGTH_A, LENGTH_B);
	printArray(array_C, length);

	return 0;
}