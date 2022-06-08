#include"Header.h"

void bublesort(int a[], int n) {
	int k = 0;
	while (k < n - 1) {

		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		k++;
	}
}