#include "Header.h"


void shell_sort_ori(int a[], int n) {

	for (int interval = n / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < n; i += 1) {
			int insert_value = a[i];
			int j = i;
			while (j >= interval && a[j - interval] > insert_value) {
				a[j] = a[j - interval];
				j -= interval;
			}
			a[j] = insert_value;
		}
	}

}

void shell_sort_count(int a[], int n, unsigned long long& count_comparision) {

	for (int interval = n / 2; ++count_comparision, interval > 0; interval /= 2) {
		for (int i = interval; ++count_comparision, i < n; i += 1) {
			int insert_value = a[i];
			int j = i;
			while (++count_comparision && j >= interval && ++count_comparision && a[j - interval] > insert_value) {
				a[j] = a[j - interval];
				j -= interval;
			}
			a[j] = insert_value;
		}
	}

}