#include "Header.h"
using namespace std;

void read_file(int*& a, int& n, char* file_name)
{
	ifstream fi(file_name);
	fi >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		fi >> a[i];
	}
	fi.close();
}
void command_1(int argc, char* argv[])
{
	int* a, int n;
	read_file(a, n, argv[3]);
	unsigned long long comparisons;
	if (argv[1] == "-a")
	{
		cout << "ALGORITHM MODE" << endl;
		cout << "Input file: " << argv[3] << endl;
		cout << "Input size: " << endl;
		cout << "---------------------------" << endl;

		char c = argv[2][2];
		
		if (argv[2] == "selection-sort")
			selection_sort_com(a, n, comparisons);
		else if (argv[2] == "insertion-sort")
			insertion_sort_com(a, n, comparisons);
		else if (argv[2] == "bubble-sort")
			bubble_sort_com(a, n, comparisons);
		else if (argv[2] == "shaker-sort")
			shaker_sort_count(a, n, comparisons);
		else if (argv[2] == "shell-sort")
			shell_sort(a, n, comparisons);

	}
}
int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		cout << "Invalid!" << endl;
	}
	else
	{
		if (argc == 5)
		{

		}
	}
}