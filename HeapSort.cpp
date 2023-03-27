#include <iostream>
#include <cmath>
#include <iomanip>
#include<string>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include <cctype>
#include<cstring>
#include<ctime>
#include<chrono>
#include<random>

using namespace std;
using namespace chrono;



void generate_random_numbers(long long*& numbers)
{
	for (int i = 0; i < 10000000; i++)
	{
		int pr = rand();
		numbers[i] = pr;
	}
}

void heapify(long long*& A, long long n, long long i) {
	long long big = i;
	long long l = 2 * i + 1;
	long long r = 2 * i + 2;
	if (l < n && A[l] > A[big]) big = l;
	if (r < n && A[r] > A[big]) big = r;
	if (big != i) {
		swap(A[i], A[big]);
		heapify(A, n, big);
	}
}

void heapSort(long long*& A, long long& n) {
	for (long long i = n / 2 - 1; i >= 0; i--)
		heapify(A, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap(A[0], A[i]);
		heapify(A, i, 0);
	}
}

int main()
{
	ofstream file("TestHeapSort.txt");
	long long int rezultat_sr = 0;
	for (int i = 0; i < 1000; i++)
	{
		long long el_count = 10000000;
		srand(time(NULL));
		long long* numbers = new long long[10000000];
		generate_random_numbers(numbers);
		auto start = high_resolution_clock::now();
		
		heapSort(numbers, el_count);

		auto stop = high_resolution_clock::now();
		file << i + 1 << ") Time " << duration_cast<milliseconds>(stop - start).count() << "ms\n";
		cout << i << "\n";
		rezultat_sr += duration_cast<milliseconds>(stop - start).count();
		delete[] numbers;
	}
	rezultat_sr = rezultat_sr / 10000000;
	file << "Avarage time " << rezultat_sr << " ms";
	file.close();
}