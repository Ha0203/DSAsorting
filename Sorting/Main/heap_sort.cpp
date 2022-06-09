#include "Header.h"

void heapRebuild(int a[], int pos, int n, unsigned long long& comparisons)
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
void heapConstruct(int a[], int n, unsigned long long& comparisons)
{
	for (int i = (n - 1) / 2;++comparisons && i >= 0; i--)
		heapRebuild(a, i, n, comparisons);
}
void heapSort(int a[], int n,unsigned long long comparisons)
{
	comparisons = 0;
	heapConstruct(a, n, comparisons);
	int r = n - 1;
	while (++comparisons && r > 0)
	{
		swap(a[0], a[r]);
		heapRebuild(a, 0, r, comparisons);
		r--;
	}
}