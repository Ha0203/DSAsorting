#include "Header.h"

void selection_sort(int*& a, int n, long long& comparisons)
{
	comparisons = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			++comparisons;
			if (a[k] > a[j])
				k = j;
		}
		swap(a[k], a[i]);
	}
}
