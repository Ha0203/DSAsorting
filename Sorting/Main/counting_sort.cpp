#include"Header.h"
void counting_sort_ori(int*& a, int n) 
{
	int min = a[0];
	int max = a[0];
	int* res = new int[n];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int shift;
	if (min >= 0)
		shift = 0;
	else
		shift = -min;
	int* count = new int[max + 1 + shift];
	for (int i = 0; i < max + 1 + shift; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[a[i] + shift]++;
	for (int i = 1; i < max + 1 + shift; i++)
		count[i] += count[i - 1];
	for (int i = 0; i < n; i++) {
		res[--count[a[i] + shift]] = a[i];
	}
	delete[] a;
	delete[] count;
	a = res;
}
void counting_sort_count(int*& a, int n, unsigned long long& comp)
{
	int min = a[0];
	int max = a[0];
	int* res = new int[n];
	for (int i = 0; ++comp && i < n; i++)
	{
		if (++comp && a[i] > max)
			max = a[i];
		if (++comp && a[i] < min)
			min = a[i];
	}
	int shift;
	if (++comp && min >= 0)
		shift = 0;
	else
		shift = -min;
	int* count = new int[max + 1 + shift];
	for (int i = 0; ++comp && i < max + 1 + shift; i++)
		count[i] = 0;
	for (int i = 0; ++comp && i < n; i++)
		count[a[i] + shift]++;
	for (int i = 1; ++comp && i < max + 1 + shift; i++)
		count[i] += count[i - 1];
	for (int i = 0; ++comp && i < n; i++) {
		res[--count[a[i] + shift]] = a[i];
	}
	delete[] a;
	delete[] count;
	a = res;
}