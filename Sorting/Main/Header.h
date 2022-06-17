#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void swap(int& a, int& b);
void bubble_sort_ori(int*& a, int n);
void bubble_sort_count(int*& a, int n,unsigned long long& comp);
void shaker_sort_ori(int a[], int n);
void shaker_sort_count(int a[], int n, unsigned long long& comparisons);
void counting_sort_ori(int*& a, int n);
void counting_sort_count(int*& a, int n,unsigned long long& comp);
void counting_sort2_ori(int*& a, int n, int place);
void counting_sort2_count(int*& a, int n, int place,unsigned long long& comp);
void radix_sort_ori(int*& a, int n);
void radix_sort_count(int*& a, int n,unsigned long long& comp);
void merge_ori(int* a, int l, int m, int r);
void merge_count(int* a, int l, int m, int r,unsigned long long& comp);
void merge_sort_ori(int* a, int l, int r);
void merge_sort_count(int* a, int l, int r, unsigned long long& comp);
void insertion_sort_ori(int a[], int n);
void insertion_sort_count(int a[], int n, unsigned long long& comp);
void selection_sort_ori(int*& a, int n);
void selection_sort_count(int*& a, int n, unsigned long long& comparisons);
bool checkSort(int a[], int n);
void readFile(string fileName, int*& a, int& n);
void chooseSortType(string str, int& sortType);
void choosePrint(double runningtime, unsigned long long& comparisons, int numarg, char** argv);
void chooseSort(int sortType, int a[], int n, double& runningtime, unsigned long long& comparisons);
void writeFile(string nameFile, int* a, int n);
template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
void flash_sort_count(int a[], int n, unsigned long long& comparisons);
void flash_sort_ori(int a[], int n);
void heap_sort_ori(int* a, int n);
void heap_sort_count(int* a, int n, unsigned long long& comparisons);
void heapRebuild_ori(int* a, int pos, int n);
void heapRebuild_count(int* a, int pos, int n, unsigned long long& comparisons);
void heapConstruct_ori(int* a, int n);
void heapConstruct_count(int* a, int n, unsigned long long& comparisons);
void shell_sort_ori(int a[], int n);
void shell_sort_count(int a[], int n, unsigned long long& count_comparision);
void Sort_MedianOf3_ori(int a[], int left, int right, int mid);
int partition_ori(int a[], int left, int right);
void quick_sort_ori(int a[], int n, int left, int right);
void Sort_MedianOf3_count(int a[], int left, int right, int mid, unsigned long long& count_comparision1);
int partition_count(int a[], int left, int right, unsigned long long& count_comparision2);
void quick_sort_count(int a[], int n, int left, int right, unsigned long long& count_comparision3);