#include<iostream>
#include<stdlib.h>
#include<time.h>

template<typename T>
void initArray(T *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = (10 + rand() % 90) * 0.25;
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
void swapElements(T *a, T *b)
{
	T variable = *a;
	*a = *b;
	*b = variable;
}

template<typename T>
void swapElementsArray(T *array, int length)
{
	for (int i = 0; i < length - 1; i += 2)
	{
		swapElements(&array[i], &array[i + 1]);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH = 11;
	int array[LENGTH];
	initArray(array, LENGTH);
	printArray(array, LENGTH);
	swapElementsArray(array, LENGTH);
	printArray(array, LENGTH);

	std::cout << std::endl;

	double array_d[LENGTH];
	initArray(array_d, LENGTH);
	printArray(array_d, LENGTH);
	swapElementsArray(array_d, LENGTH);
	printArray(array_d, LENGTH);

	return 0;
}