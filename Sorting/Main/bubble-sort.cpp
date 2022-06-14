#include"Header.h"

void bubble_sort_ori(int*& a, int n) 
{
	int k = 0;
	while (k < n - 1) 
	{

		for (int i = 0; i < n - 1 - k; i++) 
		{
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		k++;
	}
}
void bubble_sort_count(int*& a, int n,unsigned long long& comp)
{
	int k = 0;
	while (++comp && k < n - 1)
	{

		for (int i = 0; ++comp && i < n - 1 - k; i++)
		{
			if (++comp && a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		k++;
	}
}