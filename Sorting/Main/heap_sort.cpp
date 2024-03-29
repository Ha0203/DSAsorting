#include "Header.h"

void heapRebuild_ori(int* a, int pos, int n)
{

	while (2 * pos + 1 < n)
	{
		int j = 2 * pos + 1;
		if (j < n - 1)
			if (a[j] < a[j + 1])
				j = j + 1;
		if (a[pos] >= a[j])
			return;
		swap(a[pos], a[j]);
		pos = j;
	}
}
void heapRebuild_count(int* a, int pos, int n, unsigned long long& comparisons)
{

	while (++comparisons && 2 * pos + 1 < n)
	{
		int j = 2 * pos + 1;
		if (++comparisons && j < n - 1)
			if (++comparisons && a[j] < a[j + 1])
				j = j + 1;
		if (++comparisons && a[pos] >= a[j])
			return;
		swap(a[pos], a[j]);
		pos = j;
	}
}
void heapConstruct_ori(int* a, int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
		heapRebuild_ori(a, i, n);
}
void heapConstruct_count(int* a, int n, unsigned long long& comparisons)
{
	for (int i = (n - 1) / 2;++comparisons && i >= 0; i--)
		heapRebuild_count(a, i, n, comparisons);
}
void heap_sort_ori(int* a, int n)
{
	heapConstruct_ori(a, n);
	int r = n - 1;
	while (r > 0)
	{
		swap(a[0], a[r]);
		heapRebuild_ori(a, 0, r);
		r--;
	}
}
void heap_sort_count(int* a, int n,unsigned long long& comparisons)
{
	comparisons = 0;
	heapConstruct_count(a, n, comparisons);
	int r = n - 1;
	while (++comparisons && r > 0)
	{
		swap(a[0], a[r]);
		heapRebuild_count(a, 0, r, comparisons);
		r--;
	}
}