#include "Header.h"


void Shellsort(int a[], int n, unsigned long long& count_comparision) {

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