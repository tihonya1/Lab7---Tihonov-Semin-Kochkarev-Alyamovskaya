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

int ShellSort(long long*& arr, long long n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return 0;
}

int main()
{
	ofstream file("TestShellSort.txt");
	long long int rezultat_sr = 0;
	for (int i = 0; i < 1000; i++)
	{
		long long el_count = 10000000;
		srand(time(NULL));
		long long* numbers = new long long[10000000];
		generate_random_numbers(numbers);
		auto start = high_resolution_clock::now();

		ShellSort(numbers, el_count);

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