#include"Header.h"

void Sort_MedianOf3_ori(int a[], int left, int right, int mid) {
	if (a[mid] < a[left])
		swap(a[mid], a[left]);
	if (a[mid] > a[right])
		swap(a[mid], a[right]);
	if (a[mid] < a[left])
		swap(a[mid], a[left]);
}
int partition_count(int a[], int left, int right) {
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
		int pivot_index = partition_count(a, left, right);

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
