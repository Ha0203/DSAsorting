#include"Header.h"

void merge_ori(int* a, int l, int m, int r) {
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
void merge_com(int* a, int l, int m, int r, unsigned long long& comp) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int* a1 = new int[n1];
	int* a2 = new int[n2];
	int i = 0, j = 0, k = l;
	for (int i = 0; ++comp && i < n1; i++)
		a1[i] = a[l + i];
	for (int i = 0; ++comp && i < n2; i++)
		a2[i] = a[m + i + 1];
	while (++comp && i < n1 && ++comp && j < n2) {
		if (++comp && a1[i] < a2[j]) {
			a[k++] = a1[i];
			i++;
		}
		else {
			a[k++] = a2[j];
			j++;
		}
	}
	if (++comp && i < n1) {
		while (++comp && i < n1) {
			a[k++] = a1[i];
			i++;
		}
	}
	else if (++comp && j < n2) {
		while (++comp && j < n2) {
			a[k++] = a2[j];
			j++;
		}
	}
	delete[] a1, a2;
}
void merge_sort_ori(int* a, int l, int r) {
	if (l >= r)
		return;
	int m = (l + r) / 2;
	merge_sort_ori(a, l, m);
	merge_sort_ori(a, m + 1, r);
	merge_ori(a, l, m, r);
}
void merge_sort_com(int* a, int l, int r, unsigned long long& comp) {
	if (++comp && l >= r)
		return;
	int m = (l + r) / 2;
	merge_sort_com(a, l, m, comp);
	merge_sort_com(a, m + 1, r, comp);
	merge_com(a, l, m, r, comp);
}