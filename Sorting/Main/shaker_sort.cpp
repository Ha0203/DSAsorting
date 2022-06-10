#include "Header.h"
using namespace std;

void shaker_sort(int a[], int n)
{
	int left = 0, right = n - 1;
	int guard = right;
	while (left < right)
	{
		for (int i = right; i > left; i--)
			if (a[i] < a[i - 1])
			{
				int temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
				guard = i;
			}
		left = guard;
		for (int i = left; i < right; i++)
			if (a[i] > a[i + 1])
			{
				int temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
				guard = i;
			}
		right = guard;
	}
}

// This code is referenced from https://clbketnoitre.wordpress.com/2019/02/25/thuat-toan-sap-xep-shakersort/