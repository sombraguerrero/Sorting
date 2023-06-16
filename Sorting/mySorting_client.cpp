#include <fstream>
#include <ctime>
#include <cstdlib>
#include "mySorting.cpp"
#include "mySorting.h"
using namespace std;

int main(int argc, char* argv[]) {
	int a;
	bool ordered;
	if (argc == 3)
	{
		a = atoi(argv[1]);
		ordered = atoi(argv[2]);
	}
	else
	{
		cout << "Enter a size: ";
		cin >> a;
		cout << "Load an ordered list? (1 = Yes, 0 = No): ";
		cin >> ordered;
	}

	ofstream fileOut;
	fileOut.open("sorting.txt");
	Sorting<int> srt1(a);
	srt1.LoadArray(ordered, 0);
	srand((unsigned)time(NULL));

	if (ordered)
		srt1.Shuffle();
	fileOut << "srt1 PRE-QUICK SORT: " << srt1 << endl;
	fileOut << srt1.quickSort() << " comparisons ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "QUICK-SORT: " << srt1 << endl << endl;

	srt1.Shuffle();
	fileOut << "srt1 PRE-HEAP SORT: " << srt1 << endl;
	srt1.heapsort();
	fileOut << srt1.getComparisons()  << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "HEAP SORT: " << srt1 << endl << endl;

	srt1.Shuffle();
	fileOut << "srt1 PRE-SHELL SORT 2: " << srt1 << endl;
	srt1.ShellSort2();
	fileOut << srt1.getComparisons() << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "SHELL-SORT 2: " << srt1 << endl << endl;

	srt1.Shuffle();
	fileOut << "srt1 PRE-SHELL SORT: " << srt1 << endl;
	srt1.ShellSort();
	fileOut << srt1.getComparisons() << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "SHELL-SORT: " << srt1 << endl << endl;

	srt1.Shuffle();
	fileOut << endl << "srt1 PRE-SELECTION SORT: " << srt1 << endl;
	srt1.selectionSort();
	fileOut << srt1.getComparisons() << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "POST-SELECTION SORT: " << srt1 << endl << endl;
	
	srt1.Shuffle();
	fileOut << "srt1 PRE-BUBBLE SORT: " << srt1 << endl;
	srt1.bubbleSort();
	fileOut << srt1.getComparisons() << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "POST-BUBBLE SORT: " << srt1 << endl << endl;

	/**
	Sorting<int> srt2(a);
	srt2.LoadArray(ordered, 1000);
	**/
	srt1.Shuffle();
	fileOut << "srt1 PRE-ENUM SORT: " << srt1 << endl;
	srt1.EnumSort(fileOut);
	fileOut << "POST-ENUM SORT SORT: " << srt1 << endl << endl;
	
	int q = srt1.RandomQuery();
	srt1.binarySearch(q, fileOut);
	srt1.InterpSearch(q, fileOut);
	fileOut.close();
	return EXIT_SUCCESS;
}

