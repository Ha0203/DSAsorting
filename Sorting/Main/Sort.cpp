#include"Header.h"

void bubble_sort_ori(int*& a, int n)
{
	int k = 0;
	while (k < n - 1)
	{

		for (int i = 0; i < n - 1 - k; i++)
		{
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		k++;
	}
}
void bubble_sort_count(int*& a, int n, unsigned long long& comp)
{
	int k = 0;
	while (++comp && k < n - 1)
	{

		for (int i = 0; ++comp && i < n - 1 - k; i++)
		{
			if (++comp && a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		k++;
	}
}

void counting_sort_ori(int*& a, int n)
{
	int min = a[0];
	int max = a[0];
	int* res = new int[n];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int shift;
	if (min >= 0)
		shift = 0;
	else
		shift = -min;
	int* count = new int[max + 1 + shift];
	for (int i = 0; i < max + 1 + shift; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[a[i] + shift]++;
	for (int i = 1; i < max + 1 + shift; i++)
		count[i] += count[i - 1];
	for (int i = 0; i < n; i++) {
		res[--count[a[i] + shift]] = a[i];
	}
	delete[] a;
	delete[] count;
	a = res;
}
void counting_sort_count(int*& a, int n, unsigned long long& comp)
{
	int min = a[0];
	int max = a[0];
	int* res = new int[n];
	for (int i = 0; ++comp && i < n; i++)
	{
		if (++comp && a[i] > max)
			max = a[i];
		if (++comp && a[i] < min)
			min = a[i];
	}
	int shift;
	if (++comp && min >= 0)
		shift = 0;
	else
		shift = -min;
	int* count = new int[max + 1 + shift];
	for (int i = 0; ++comp && i < max + 1 + shift; i++)
		count[i] = 0;
	for (int i = 0; ++comp && i < n; i++)
		count[a[i] + shift]++;
	for (int i = 1; ++comp && i < max + 1 + shift; i++)
		count[i] += count[i - 1];
	for (int i = 0; ++comp && i < n; i++) {
		res[--count[a[i] + shift]] = a[i];
	}
	delete[] a;
	delete[] count;
	a = res;
}


void flash_sort_ori(int a[], int n)
{

	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];

	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;

	double c1 = (double)(m - 1) / (a[max] - minVal);

	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;

	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertion_sort_ori(a, n);
}

void flash_sort_count(int a[], int n, unsigned long long& comparisons)
{
	comparisons = 0;

	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];

	for (int i = 0; ++comparisons && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++comparisons && i < n; i++)
	{
		if (++comparisons && a[i] < minVal)
			minVal = a[i];
		if (++comparisons && a[i] > a[max])
			max = i;
	}
	if (++comparisons && a[max] == minVal)
		return;

	double c1 = (double)(m - 1) / (a[max] - minVal);

	for (int i = 0; ++comparisons && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++comparisons && i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;

	while (++comparisons && nmove < n - 1)
	{
		while (++comparisons && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++comparisons && k < 0) break;
		while (++comparisons && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertion_sort_count(a, n, comparisons);
}

/*
	Souce code: https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp
*/


using namespace std;

void insertion_sort_ori(int a[], int n)
{
	int guard = 0, j = 0;
	for (int i = 1; i < n; i++)
	{
		guard = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > guard)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = guard;
	}
}
void insertion_sort_count(int a[], int n, unsigned long long& comp)
{
	int guard = 0, j = 0;
	for (int i = 1; ++comp && i < n; i++)
	{
		guard = a[i];
		j = i - 1;
		while (++comp && j >= 0 && ++comp && a[j] > guard)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = guard;
	}
}
// This code is referenced from https://cafedev.vn/thuat-toan-insertion-sort-gioi-thieu-chi-tiet-va-code-vi-du-tren-nhieu-ngon-ngu-lap-trinh/


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
void merge_count(int* a, int l, int m, int r, unsigned long long& comp) {
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
void merge_sort_count(int* a, int l, int r, unsigned long long& comp) {
	if (++comp && l >= r)
		return;
	int m = (l + r) / 2;
	merge_sort_count(a, l, m, comp);
	merge_sort_count(a, m + 1, r, comp);
	merge_count(a, l, m, r, comp);
}


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
	for (int i = n - 1; i >= 0; i--) {
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
	for (int i = n - 1; ++comp && i >= 0; i--) {
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


void selection_sort_ori(int*& a, int n)
{
	int i = 0;
	while (i < n - 1)
	{
		int k = i;
		int j = i + 1;
		while (j < n)
		{
			if (a[k] > a[j])
				k = j;
			j++;
		}
		swap(a[k], a[i]);
		i++;
	}
}
void selection_sort_count(int*& a, int n, unsigned long long& comparisons)
{
	comparisons = 0;
	int i = 0;
	while (++comparisons && i < n - 1)
	{
		int k = i;
		int j = i + 1;
		while (++comparisons && j < n)
		{
			if (++comparisons && a[k] > a[j])
				k = j;
			j++;
		}
		swap(a[k], a[i]);
		i++;
	}
}


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


void heapRebuild_ori(int* a, int pos, int n)
{

	while (2 * pos + 1 < n)
	{
		int j = 2 * pos + 1;
		if (j < n - 1)
			if (a[j] < a[j + 1])
				j = j + 1;
		if (a[pos] >= a[j])
			return;
		swap(a[pos], a[j]);
		pos = j;
	}
}
void heapRebuild_count(int* a, int pos, int n, unsigned long long& comparisons)
{

	while (++comparisons && 2 * pos + 1 < n)
	{
		int j = 2 * pos + 1;
		if (++comparisons && j < n - 1)
			if (++comparisons && a[j] < a[j + 1])
				j = j + 1;
		if (++comparisons && a[pos] >= a[j])
			return;
		swap(a[pos], a[j]);
		pos = j;
	}
}
void heapConstruct_ori(int* a, int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
		heapRebuild_ori(a, i, n);
}
void heapConstruct_count(int* a, int n, unsigned long long& comparisons)
{
	for (int i = (n - 1) / 2; ++comparisons && i >= 0; i--)
		heapRebuild_count(a, i, n, comparisons);
}
void heap_sort_ori(int* a, int n)
{
	heapConstruct_ori(a, n);
	int r = n - 1;
	while (r > 0)
	{
		swap(a[0], a[r]);
		heapRebuild_ori(a, 0, r);
		r--;
	}
}
void heap_sort_count(int* a, int n, unsigned long long& comparisons)
{
	comparisons = 0;
	heapConstruct_count(a, n, comparisons);
	int r = n - 1;
	while (++comparisons && r > 0)
	{
		swap(a[0], a[r]);
		heapRebuild_count(a, 0, r, comparisons);
		r--;
	}
}


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


void Sort_MedianOf3_ori(int a[], int left, int right, int mid) {
	if (a[mid] < a[left])
		swap(a[mid], a[left]);
	if (a[mid] > a[right])
		swap(a[mid], a[right]);
	if (a[mid] < a[left])
		swap(a[mid], a[left]);
}
int partition_ori(int a[], int left, int right) {
	int mid = (left + right) / 2;
	Sort_MedianOf3_ori(a, left, right, mid);
	swap(a[mid], a[right]);
	int pivot = a[right];
	int i = left - 1;
	int j = left;
	while (j <= right - 1)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a[j], a[i]);
		}
		j++;
	}
	swap(a[i + 1], a[right]);
	return (i + 1);
}
void quick_sort_ori(int a[], int n, int left, int right)
{
	if (left < right)
	{
		int pivot_index = partition_ori(a, left, right);

		quick_sort_ori(a, n, left, pivot_index - 1);

		quick_sort_ori(a, n, pivot_index + 1, right);


	}

}

void Sort_MedianOf3_count(int a[], int left, int right, int mid, unsigned long long& count_comparision1) {
	if (++count_comparision1 && a[mid] < a[left])
		swap(a[mid], a[left]);
	if (++count_comparision1 && a[mid] > a[right])
		swap(a[mid], a[right]);
	if (++count_comparision1 && a[mid] < a[left])
		swap(a[mid], a[left]);
}
int partition_count(int a[], int left, int right, unsigned long long& count_comparision2) {
	int mid = (left + right) / 2;
	unsigned long long count_comparision1 = 0;
	Sort_MedianOf3_count(a, left, right, mid, count_comparision1);
	swap(a[mid], a[right]);
	int pivot = a[right];
	int i = left - 1;
	int j = left;
	while (++count_comparision2 && j <= right - 1)
	{
		if (++count_comparision2 && a[j] < pivot)
		{
			i++;
			swap(a[j], a[i]);
		}
		j++;
	}
	swap(a[i + 1], a[right]);
	count_comparision2 += count_comparision1;
	return (i + 1);
}
void quick_sort_count(int a[], int n, int left, int right, unsigned long long& count_comparision3)
{
	unsigned long long count_comparision2 = 0;
	if (++count_comparision3 && left < right)
	{
		int pivot_index = partition_count(a, left, right, count_comparision2);

		quick_sort_count(a, n, left, pivot_index - 1, count_comparision3);

		quick_sort_count(a, n, pivot_index + 1, right, count_comparision3);


	}

	count_comparision3 += count_comparision2;
}
