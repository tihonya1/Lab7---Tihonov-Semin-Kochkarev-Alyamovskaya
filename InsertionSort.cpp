#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <chrono>
#include <random>


void output(long long a, size_t index)
{
	std::ofstream out("InsertionSort.txt", std::ios::app);
	out << index+1 << ") " << a << "ms" << std::endl;
	out.close();
}

void generate_random_numbers(long long*& numbers)
{
	srand(time(NULL));
	for (size_t i = 0; i < 250000; ++i)
	{
		int pr = rand();
		numbers[i] = pr;
	}
}

void insertionSort(long long a[], int n)	
{

	int i, j;
	int t;
	for (i = 1; i < n; i++)
	{
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = t;
	}
}

long double tester(size_t testsCount)
{
	long long sum = 0;
	long long currentTestTime = 0;
	for (size_t k = 0; k < testsCount; ++k)
	{
		size_t length = 250000;
		auto t1 = std::chrono::high_resolution_clock::now();
		long long* arr = new long long[length];
		generate_random_numbers(arr);
		insertionSort(arr, length);
		auto t2 = std::chrono::high_resolution_clock::now();

		sum += std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		currentTestTime = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		output(currentTestTime, k);

	}
	long double averageGigaChad = (long double) sum / testsCount;
	return averageGigaChad;
}

int main()
{
	long double average = tester(1000);
	std::ofstream out("InsertionSort.txt", std::ios::app);
	out << "Average time: " << average << " ms" << std::endl;
	out.close();
}