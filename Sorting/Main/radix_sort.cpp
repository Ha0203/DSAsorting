#include"Header.h"

void counting_sort2_ori(int*& a, int n, int place) 
{
	int max = 9;
	int* res = new int[n];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	int* count = new int[max + 1];
	for (int i = 0; i < max + 1; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[(a[i] / place) % 10]++;
	for (int i = 1; i < max + 1; i++)
		count[i] += count[i - 1];
	for (int i = 0; i < n; i++) {
		res[--count[(a[i] / place) % 10]] = a[i];
	}
	delete[] a;
	delete[] count;
	a = res;
}
void counting_sort2_count(int*& a, int n, int place, unsigned long long& comp)
{
	int max = 9;
	int* res = new int[n];
	for (int i = 0; ++comp && i < n; i++) {
		if (++comp && a[i] > max)
			max = a[i];
	}
	int* count = new int[max + 1];
	for (int i = 0; ++comp && i < max + 1; i++)
		count[i] = 0;
	for (int i = 0; ++comp && i < n; i++)
		count[(a[i] / place) % 10]++;
	for (int i = 1; ++comp && i < max + 1; i++)
		count[i] += count[i - 1];
	for (int i = 0; ++comp && i < n; i++) {
		res[--count[(a[i] / place) % 10]] = a[i];
	}
	delete[] a;
	delete[] count;
	a = res;
}
void radix_sort_ori(int*& a, int n) {
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	for (int place = 1; max / place > 0; place *= 10)
		counting_sort2_ori(a, n, place);
}
void radix_sort_count(int*& a, int n, unsigned long long& comp) {
	int max = a[0];
	for (int i = 0; ++comp && i < n; i++) {
		if (++comp && a[i] > max)
			max = a[i];
	}
	for (int place = 1; ++comp && max / place > 0; place *= 10)
		counting_sort2_count(a, n, place, comp);
}