#include"Header.h"

void merge(int* a, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int* a1 = new int[n1];
	int* a2 = new int[n2];
	int i = 0, j = 0, k = l;
	for (int i = 0; i < n1; i++)
		a1[i] = a[l + i];
	for (int i = 0; i < n2; i++)
		a2[i] = a[m + i + 1];
	while (i < n1 && j < n2) {
		if (a1[i] < a2[j]) {
			a[k++] = a1[i];
			i++;
		}
		else {
			a[k++] = a2[j];
			j++;
		}
	}
	if (i < n1) {
		while (i < n1) {
			a[k++] = a1[i];
			i++;
		}
	}
	else if (j < n2) {
		while (j < n2) {
			a[k++] = a2[j];
			j++;
		}
	}
	delete[] a1, a2;
}
void merge_sort(int* a, int l, int r) {
	if (l >= r)
		return;
	int m = (l + r) / 2;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, m, r);
}