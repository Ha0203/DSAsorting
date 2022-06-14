#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void swap(int& a, int& b);
void bubble_sort_ori(int a[], int n);
void bubble_sort_com(int*& a, int n,unsigned long long& comp);
void shaker_sort_ori(int a[], int n);
void shaker_sort_count(int a[], int n, unsigned long long& comparisons);
void counting_sort_ori(int*& a, int n);
void counting_sort_com(int*& a, int n,unsigned long long& comp);
void counting_sort2_ori(int*& a, int n, int place);
void counting_sort2_com(int*& a, int n, int place,unsigned long long& comp);
void radix_sort_ori(int*& a, int n);
void radix_sort_com(int*& a, int n,unsigned long long& comp);
void merge_ori(int* a, int l, int m, int r);
void merge_com(int* a, int l, int m, int r,unsigned long long& comp);
void merge_sort_ori(int* a, int l, int r);
void merge_sort_com(int* a, int l, int r, unsigned long long& comp);
void insertion_sort_ori(int a[], int n);
void insertion_sort_com(int a[], int n, unsigned long long& comp);
void selection_sort_ori(int*& a, int n);
void selection_sort_com(int*& a, int n, unsigned long long& comparisons);
void heapRebuild_ori(int a[], int pos, int n);
void heapRebuild_com(int a[], int pos, int n, unsigned long long& comparisons);
void heapConstruct_ori(int a[], int n);
void heapConstruct_com(int a[], int n, unsigned long long& comparisons);
void heapSort_ori(int a[], int n);
void heapSort_com(int a[], int n, unsigned long long comparisons);
void Sort_MedianOf3(int a[], int left, int right, int mid, unsigned long long& count_comparision1);
int partition(int a[], int left, int right, unsigned long long& count_comparision2);
void quicksort(int a[], int n, int left, int right, unsigned long long& count_comparision3);
void Shellsort(int a[], int n, unsigned long long& count_comparision);