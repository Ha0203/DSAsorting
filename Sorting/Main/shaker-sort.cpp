#include"Header.h"

void shaker_sort(int a[], int n) {
	int left = 0, right = n - 1;
	while (right - left > 1) {
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (a[i] < a[i - 1])
				swap(a[i], a[i - 1]);
		}
		left++;
	}
}