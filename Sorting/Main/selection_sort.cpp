#include "Header.h"

void selection_sort(int*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[k] > a[j])
				k = j;
		}
		swap(a[k], a[i]);
	}
}
