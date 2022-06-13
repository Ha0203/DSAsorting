#include"Header.h"

void shaker_sort_ori(int a[], int n) {
	int left = 0, right = n - 1;
	while (right - left >= 1) {
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

void shaker_sort_count(int a[], int n, unsigned long long& comparisons) {
	int left = 0, right = n - 1;
	while (++comparisons && right - left >= 1) {
		for (int i = left; ++comparisons && i < right; i++) {
			if (++comparisons && a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		right--;
		for (int i = right; ++comparisons && i > left; i--)
		{
			if (++comparisons && a[i] < a[i - 1])
				swap(a[i], a[i - 1]);
		}
		left++;
	}
}