#include "Header.h"
#include<iostream>
#include<string>
#include<cctype>
#include<fstream>
#include<chrono>
using namespace std;


int main(int argc, char** argv)
{
	double runningtime = 0;
	unsigned long long comparisons = 0;
	int* a;
	if ((string)argv[1] == "-a") {
		//ALGORITHM MODE
		cout << "ALGORITHM MODE" << endl;
		int sortType = 0;
		int n = 0;
		chooseSortType((string)argv[2], sortType);
		if (isdigit(argv[3][0]) == 1) {
			cout << "Input size: " << argv[3] << endl;
			n = atoi(argv[3]);
			a = new int[n];
			int dataType = -1;
			if (argc == 6) {
				//Command 2
				if ((string)argv[4] == "-rand") {
					cout << "Input order:  Randomize" << endl;
					dataType = 0;
				}
				else if ((string)argv[4] == "-nsorted") {
					cout << "Input order:  Nearly Sorted" << endl;
					dataType = 3;
				}
				else if ((string)argv[4] == "-sorted") {
					cout << "Input order:  Sorted" << endl;
					dataType = 1;
				}
				else if ((string)argv[4] == "-rev") {
					cout << "Input order:  Reversed" << endl;
					dataType = 2;
				}
				else {
					cout << "Command not found!" << endl;
					return 0;
				}
				cout << "----------------------------" << endl;
				GenerateData(a, n, dataType);
				writeFile("input.txt", a, n);
				chooseSort(sortType, a, n, runningtime, comparisons);
				choosePrint(runningtime, comparisons, 5, argv);
				writeFile("output.txt", a, n);
			}
			else {
				//Command 3
				int* a1 = new int[n];
				int* a2 = new int[n];
				int* a3 = new int[n];
				GenerateData(a, n, 0);
				writeFile("input_1.txt", a, n);
				GenerateData(a1, n, 3);
				writeFile("input_2.txt", a1, n);
				GenerateData(a2, n, 1);
				writeFile("input_3.txt", a2, n);
				GenerateData(a3, n, 2);
				writeFile("input_4.txt", a3, n);

				cout << endl;
				cout << "Input order:  Randomize" << endl;
				cout << "----------------------------" << endl;
				chooseSort(sortType, a, n, runningtime, comparisons);
				choosePrint(runningtime, comparisons, 4, argv);

				runningtime = 0;
				comparisons = 0;
				cout << endl;
				cout << "Input order: Nearly Sorted" << endl;
				cout << "----------------------------" << endl;
				chooseSort(sortType, a1, n, runningtime, comparisons);
				choosePrint(runningtime, comparisons, 4, argv);

				runningtime = 0;
				comparisons = 0;
				cout << endl;
				cout << "Input order:  Sorted" << endl;
				cout << "----------------------------" << endl;
				chooseSort(sortType, a2, n, runningtime, comparisons);
				choosePrint(runningtime, comparisons, 4, argv);

				runningtime = 0;
				comparisons = 0;
				cout << endl;
				cout << "Input order:  Reversed" << endl;
				cout << "----------------------------" << endl;
				chooseSort(sortType, a3, n, runningtime, comparisons);
				choosePrint(runningtime, comparisons, 4, argv);
				delete[] a1, a2, a3;
			}
		}
		else {
			//Command 1
			cout << "Input file: " << argv[3] << endl;
			readFile(argv[3], a, n);
			if (n == -1)
				return 0;
			cout << "Input size: " << n << endl;
			cout << "----------------------------" << endl;
			chooseSort(sortType, a, n, runningtime, comparisons);
			choosePrint(runningtime, comparisons, 4, argv);
			writeFile("output.txt", a, n);
		}
	}
	else if ((string)argv[1] == "-c") {
		cout << "COMPARE MODE" << endl;
		int* a; int* b; int n; int dataType;
		double runningtimea = 0; double runningtimeb = 0;
		unsigned long long comparisonsa = 0; unsigned long long comparisonsb = 0;
		int sortTypea, sortTypeb;
		if ((string)argv[2] == "selection-sort") {
			cout << "Algorithm: Selection Sort | ";
			sortTypea = 1;
		}
		else if ((string)argv[2] == "insertion-sort") {
			cout << "Algorithm: Insertion Sort | ";
			sortTypea = 2;
		}
		else if ((string)argv[2] == "bubble-sort") {
			cout << "Algorithm: Bubble Sort | ";
			sortTypea = 3;
		}
		else if ((string)argv[2] == "shaker-sort") {
			cout << "Algorithm: Shaker Sort | ";
			sortTypea = 4;
		}
		else if ((string)argv[2] == "shell-sort") {
			cout << "Algorithm: Shell Sort | ";
			sortTypea = 5;
		}
		else if ((string)argv[2] == "heap-sort") {
			cout << "Algorithm: Heap Sort | ";
			sortTypea = 6;
		}
		else if ((string)argv[2] == "merge-sort") {
			cout << "Algorithm: Merge Sort | ";
			sortTypea = 7;
		}
		else if ((string)argv[2] == "quick-sort") {
			cout << "Algorithm: Quick Sort | ";
			sortTypea = 8;
		}
		else if ((string)argv[2] == "counting-sort") {
			cout << "Algorithm: Counting Sort | ";
			sortTypea = 9;
		}
		else if ((string)argv[2] == "radix-sort") {
			cout << "Algorithm: Radix Sort | ";
			sortTypea = 10;
		}
		else if ((string)argv[2] == "flash-sort") {
			cout << "Algorithm: Flash Sort | ";
			sortTypea = 11;
		}
		else {
			cout << "Algorithm not found!" << endl;
			return 0;
		}

		if ((string)argv[3] == "selection-sort") {
			cout << "Selection Sort" << endl;
			sortTypeb = 1;
		}
		else if ((string)argv[3] == "insertion-sort") {
			cout << "Insertion Sort" << endl;
			sortTypeb = 2;
		}
		else if ((string)argv[3] == "bubble-sort") {
			cout << "Bubble Sort" << endl;
			sortTypeb = 3;
		}
		else if ((string)argv[3] == "shaker-sort") {
			cout << "Shaker Sort" << endl;
			sortTypeb = 4;
		}
		else if ((string)argv[3] == "shell-sort") {
			cout << "Shell Sort" << endl;
			sortTypeb = 5;
		}
		else if ((string)argv[3] == "heap-sort") {
			cout << "Heap Sort" << endl;
			sortTypeb = 6;
		}
		else if ((string)argv[3] == "merge-sort") {
			cout << "Merge Sort" << endl;
			sortTypeb = 7;
		}
		else if ((string)argv[3] == "quick-sort") {
			cout << "Quick Sort" << endl;
			sortTypeb = 8;
		}
		else if ((string)argv[3] == "counting-sort") {
			cout << "Counting Sort" << endl;
			sortTypeb = 9;
		}
		else if ((string)argv[3] == "radix-sort") {
			cout << "Radix Sort" << endl;
			sortTypeb = 10;
		}
		else if ((string)argv[3] == "flash-sort") {
			cout << "Flash Sort" << endl;
			sortTypeb = 11;
		}
		else {
			cout << "Algorithm not found!" << endl;
			return 0;
		}
		if (argc == 5) {
			//Command 4
			cout << "Input file: " << argv[4] << endl;
			readFile(argv[4], a, n);
			readFile(argv[4], b, n);
			cout << "Input size: " << n << endl;
			cout << "----------------------------" << endl;
			chooseSort(sortTypea, a, n, runningtimea, comparisonsa);
			chooseSort(sortTypeb, b, n, runningtimeb, comparisonsb);
			cout << "Running time: " << runningtimea << " | " << runningtimeb << endl;
			cout << "Comparisons: " << comparisonsa << " | " << comparisonsb << endl;
		}
		else {
			//Command 5
			n = stoi(argv[4]);
			a = new int[n];
			b = new int[n];
			cout << "Input size: " << n << endl;
			if ((string)argv[5] == "-rand") {
				cout << "Input order:  Randomize" << endl;
				dataType = 0;
			}
			else if ((string)argv[5] == "-nsorted") {
				cout << "Input order:  Nearly Sorted" << endl;
				dataType = 3;
			}
			else if ((string)argv[5] == "-sorted") {
				cout << "Input order:  Sorted" << endl;
				dataType = 1;
			}
			else if ((string)argv[5] == "-rev") {
				cout << "Input order:  Reversed" << endl;
				dataType = 2;
			}
			else {
				cout << "Command not found!" << endl;
				return 0;
			}
			GenerateData(a, n, dataType);
			writeFile("input.txt", a, n);
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			cout << "----------------------------" << endl;
			chooseSort(sortTypea, a, n, runningtimea, comparisonsa);
			chooseSort(sortTypeb, b, n, runningtimeb, comparisonsb);
			cout << "Running time: " << runningtimea << " | " << runningtimeb << endl;
			cout << "Comparisons: " << comparisonsa << " | " << comparisonsb << endl;
		}
	}
	else {
		cout << "Command not found!" << endl;
		return 0;
	}
	return 0;
}