#include"Header.h"
#include<chrono>
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void readFile(string fileName, int*& a, int& n) {
	fstream file;
	file.open(fileName, ios::in);
	if (file.fail()) {
		cout << "Can't open the input file" << endl;
		n = -1;
		return;
	}
	file >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		file >> a[i];
	file.close();
}

bool checkSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1])
			return 0;
	}
	return 1;
}
void chooseSort(int sortType, int a[], int n, double& runningtime, unsigned long long& comparisons) {
	switch (sortType) {
	case 1: {
		auto start = std::chrono::high_resolution_clock::now();
		selection_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		selection_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}
	case 2: {
		auto start = std::chrono::high_resolution_clock::now();
		insertion_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		insertion_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}
	case 3: {
		auto start = std::chrono::high_resolution_clock::now();
		bubble_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		bubble_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}
	case 4: {
		auto start = std::chrono::high_resolution_clock::now();
		shaker_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		shaker_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}
	case 5: /*{
		auto start = std::chrono::high_resolution_clock::now();
		shell_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		shell_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}*/
		
	case 6: /*{
		auto start = std::chrono::high_resolution_clock::now();
		heap_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		heap_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}*/
		
	case 7: {
		auto start = std::chrono::high_resolution_clock::now();
		merge_sort_ori(a, 0, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		merge_sort_count(a, 0, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}
		
	case 8: /*{
		auto start = std::chrono::high_resolution_clock::now();
		quick_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		quick_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}*/
		
	case 9: {
		auto start = std::chrono::high_resolution_clock::now();
		counting_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		counting_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}
		
	case 10: {
		auto start = std::chrono::high_resolution_clock::now();
		radix_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		radix_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}
		
	case 11: {
		auto start = std::chrono::high_resolution_clock::now();
		flash_sort_ori(a, n);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		runningtime = duration.count();
		flash_sort_count(a, n, comparisons);
		if (checkSort(a, n) == 0)
			cout << "Sort Fail" << endl;
		break;
	}
		
	}
}
void choosePrint(double runningtime, unsigned long long& comparisons, int numarg, char** argv) {
	if ((string)argv[numarg] == "-both") {
		cout << "Running time: " << runningtime << " ms" << endl;
		cout << "Comparisons: " << comparisons << endl;
	}
	else if ((string)argv[numarg] == "-time")
		cout << "Running time: " << runningtime << " ms" << endl;
	else if ((string)argv[numarg] == "-comp")
		cout << "Comparisons: " << comparisons << endl;
	else {
		cout << "Command not found!" << endl;
		return;
	}
}
void chooseSortType(string str, int& sortType) {
	if (str == "selection-sort") {
		cout << "Algorithm: Selection Sort" << endl;
		sortType = 1;
	}
	else if (str == "insertion-sort") {
		cout << "Algorithm: Insertion Sort" << endl;
		sortType = 2;
	}
	else if (str == "bubble-sort") {
		cout << "Algorithm: Bubble Sort" << endl;
		sortType = 3;
	}
	else if (str == "shaker-sort") {
		cout << "Algorithm: Shaker Sort" << endl;
		sortType = 4;
	}
	else if (str == "shell-sort") {
		cout << "Algorithm: Shell Sort" << endl;
		sortType = 5;
	}
	else if (str == "heap-sort") {
		cout << "Algorithm: Heap Sort" << endl;
		sortType = 6;
	}
	else if (str == "merge-sort") {
		cout << "Algorithm: Merge Sort" << endl;
		sortType = 7;
	}
	else if (str == "quick-sort") {
		cout << "Algorithm: Quick Sort" << endl;
		sortType = 8;
	}
	else if (str == "counting-sort") {
		cout << "Algorithm: Counting Sort" << endl;
		sortType = 9;
	}
	else if (str == "radix-sort") {
		cout << "Algorithm: Radix Sort" << endl;
		sortType = 10;
	}
	else if (str == "flash-sort") {
		cout << "Algorithm: Flash Sort" << endl;
		sortType = 11;
	}
	else {
		cout << "Algorithm not found!" << endl;
		return;
	}
}
void writeFile(string nameFile, int* a, int n) {
	fstream file;
	file.open(nameFile, ios::out);
	file << n << endl;
	for (int i = 0; i < n; i++)
		file << a[i] << " ";
	file.close();
}