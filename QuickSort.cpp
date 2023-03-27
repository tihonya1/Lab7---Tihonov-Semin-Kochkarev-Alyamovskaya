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
void quce_sort(int*& numbers, long int start, long int end)
{
	int mid;
	int starts = start;
	int ends = end;
	mid = numbers[(starts + ends) / 2];
	do
	{
		while (numbers[starts] < mid)
		{
			starts++;
		}
		while (numbers[ends] > mid)
		{
			ends--;
		}
		if (starts <= ends)
		{
			int tp = numbers[starts];
			numbers[starts] = numbers[ends];
			numbers[ends] = tp;
			starts++;
			ends--;
		}
	} 
	while (starts < ends);
	if (start < ends)
	{
		quce_sort(numbers, start, ends);
	}
	if (starts < end)
	{
		quce_sort(numbers, starts, end);
	}
}
void generait_random_numbers(int*& numbers)
{
	for (int i = 0; i < 10000000; i++)
	{
		int pr = rand();
		numbers[i] = pr;
	}
}
int main()
{
	ofstream file;
	file.open("Test.txt");
	long long int rezultat_sr = 0;
	for (int i = 0; i < 1000; i++)
	{
		srand(time(NULL));
		int*numbers = new int [10000000];
		generait_random_numbers(numbers);
		long int start_finc = 0;
		long int end_finc = 9999999;
		auto start = high_resolution_clock::now();
		quce_sort(numbers,start_finc,end_finc);
		auto stop = high_resolution_clock::now();
		file << "Time spent " << duration_cast<milliseconds>(stop - start).count() << "ms";
		file << "\n";
		cout << "Test " << i <<' '<< "Ready";
		cout << "\n";
		rezultat_sr += duration_cast<milliseconds>(stop - start).count();
		delete[] numbers;
	}
	rezultat_sr = rezultat_sr / 1000;
	file << "Average time: "<< rezultat_sr <<" ms";
	file.close();
}