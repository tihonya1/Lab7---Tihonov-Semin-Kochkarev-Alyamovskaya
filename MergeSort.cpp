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
	std::ofstream out("MergeSort.txt", std::ios::app);
	out << index + 1 << ") " << a << "ms" << std::endl;
	out.close();
}

void generate_random_numbers(long long*& numbers)
{
	srand(time(NULL));
	for (size_t i = 0; i < 10000000; ++i)
	{
		int pr = rand();
		numbers[i] = pr;
	}
}

void merge(long long arr[], size_t start, size_t mid, size_t end) 
{

	size_t len1 = mid - start + 1;
	size_t len2 = end - mid;

	long long* leftArr = new long long[len1];
	long long* rightArr = new long long[len2];

	for (size_t i = 0; i < len1; i++)
		leftArr[i] = arr[start + i];
	for (size_t j = 0; j < len2; j++)
		rightArr[j] = arr[mid + 1 + j];

	size_t i, j, k;
	i = 0;
	j = 0;
	k = start;

	while (i < len1 && j < len2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			++i;
		}
		else {
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}

	while (i < len1) {
		arr[k] = leftArr[i];
		++i;
		++k;
	}

	while (j < len2) {
		arr[k] = rightArr[j];
		++j;
		++k;
	}
	delete[] leftArr;
	delete[] rightArr;
}

void mergeSort(long long arr[], size_t start, size_t end) {
	if (start < end) {

		size_t mid = start + (end - start) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

long double tester(size_t testsCount)
{
	long long* a = new long long[1];
	long long sum = 0;
	long long currentTestTime = 0;
	for (size_t k = 0; k < testsCount; ++k)
	{
		size_t length = 10000000;
		
		long long* arr = new long long[length];
		generate_random_numbers(arr);

		auto t1 = std::chrono::high_resolution_clock::now();
		mergeSort(arr,0, length-1);
		auto t2 = std::chrono::high_resolution_clock::now();

		sum += std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		currentTestTime = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		output(currentTestTime,k);


	}
	long double averageGigaChad = (long double)sum / testsCount;
	return averageGigaChad;
}

int main()
{
	long double average = tester(1000);
	std::ofstream out("InsertionSort.txt", std::ios::app);
	out << "Average time: " << average << " ms" << std::endl;
	out.close();
}