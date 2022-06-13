#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void swap(int& a, int& b);
void bubble_sort(int a[], int n);
void shaker_sort(int a[], int n);
void counting_sort(int*& a, int n);
void counting_sort2(int*& a, int n, int place);
void radix_sort(int*& a, int n);
void merge(int* a, int l, int m, int r);
void merge_sort(int* a, int l, int r);
void insertion_sort(int a[], int n);
void selection_sort(int*& a, int n, unsigned long long& comparisons);
void heapRebuild(int a[], int pos, int n, unsigned long long& comparisons);
void heapConstruct(int a[], int n, unsigned long long& comparisons);
void heapSort(int a[], int n, unsigned long long comparisons);