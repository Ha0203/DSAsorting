#include"Header.h"

void shaker_sort(int a[], int n, unsigned long long& comparisons) {
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