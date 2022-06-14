
void Sort_MedianOf3(int a[], int left, int right, int mid, unsigned long long& count_comparision1) {
	if (++count_comparision1 && a[mid] < a[left])
		swap(&a[mid], &a[left]);
	if (++count_comparision1 && a[mid] > a[right])
		swap(&a[mid], &a[right]);
	if (++count_comparision1 && a[mid] < a[left])
		swap(&a[mid], &a[left]);
}
int partition(int a[], int left, int right, unsigned long long& count_comparision2) {
	int mid = (left + right) / 2;
	unsigned long long count_comparision1 = 0;
	Sort_MedianOf3(a, left, right, mid, count_comparision1);
	swap(&a[mid], &a[right]);
	int pivot = a[right];
	int i = left - 1;
	int j = left;
	while (++count_comparision2 && j <= right - 1)
	{
		if (++count_comparision2 && a[j] < pivot)
		{
			i++;
			swap(&a[j], &a[i]);
		}
		j++;
	}
	swap(&a[i + 1], &a[right]);
	count_comparision2 += count_comparision1;
	return (i + 1);
}
void quicksort(int a[], int n, int left, int right, unsigned long long& count_comparision3)
{
	unsigned long long count_comparision2 = 0;
	if (++count_comparision3 && left < right)
	{
		int pivot_index = partition(a, left, right, count_comparision2);

		quicksort(a, n, left, pivot_index - 1, count_comparision3);

		quicksort(a, n, pivot_index + 1, right, count_comparision3);


	}

	count_comparision3 += count_comparision2;
}
