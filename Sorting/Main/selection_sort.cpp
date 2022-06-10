#include "Header.h"

void selection_sort(int*& a, int n,unsigned long long& comparisons)
{
	comparisons = 0;
	int i = 0;
	while (++comparisons && i < n - 1)
	{
		int k = i;
		int j = i + 1;
		while (++comparisons && j < n)
		{
			if (++comparisons && a[k] > a[j])
				k = j;
			j++;
		}
		swap(a[k], a[i]);
		i++;
	}
	/*for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			++comparisons;
			if (a[k] > a[j])
				k = j;
		}
		swap(a[k], a[i]);
	}*/
}
