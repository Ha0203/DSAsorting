#include "Header.h"
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