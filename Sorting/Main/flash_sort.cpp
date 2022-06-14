#include "Header.h"
void flash_sort_ori(int a[], int n)
{

	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];

	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;

	double c1 = (double)(m - 1) / (a[max] - minVal);

	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;

	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertion_sort_ori(a, n);
}

void flash_sort_count(int a[], int n, unsigned long long& comparisons)
{
	comparisons = 0;

	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];

	for (int i = 0;++comparisons && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++comparisons && i < n; i++)
	{
		if (++comparisons && a[i] < minVal)
			minVal = a[i];
		if (++comparisons && a[i] > a[max])
			max = i;
	}
	if (++comparisons && a[max] == minVal)
		return;

	double c1 = (double)(m - 1) / (a[max] - minVal);

	for (int i = 0; ++comparisons && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++comparisons && i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;

	while (++comparisons && nmove < n - 1)
	{
		while (++comparisons && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++comparisons && k < 0) break;
		while (++comparisons && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertion_sort_count(a, n, comparisons);
}

/*
	Souce code: https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp
*/