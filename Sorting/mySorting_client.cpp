#include <fstream>
#include <ctime>
#include <cstdlib>
#include "mySorting.cpp"
#include "mySorting.h"
using namespace std;

int main(int argc, char* argv[]) {
	int a;
	if (argc == 2)
	{
		a = atoi(argv[1]);
	}
	else
	{
		cout << "Enter a size: ";
		cin >> a;
	}

	ofstream fileOut;
	fileOut.open("sorting.txt");
	Sorting<int> srt1(a);
	srand((unsigned)time(NULL));
	unsigned initVal = srt1.getSize();

	srt1.setRandomData(initVal);
	fileOut << "srt1 PRE-QUICK SORT: " << srt1 << endl;
	fileOut << srt1.quickSort() << " comparisons ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "QUICK-SORT: " << srt1 << endl << endl;

	srt1.setRandomData(initVal);
	fileOut << "srt1 PRE-HEAP SORT: " << srt1 << endl;
	srt1.heapsort();
	fileOut << srt1.getComparisons()  << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "HEAP SORT: " << srt1 << endl << endl;

	srt1.setRandomData(initVal);
	fileOut << "srt1 PRE-SHELL SORT 2: " << srt1 << endl;
	srt1.ShellSort2();
	fileOut << srt1.getComparisons() << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "SHELL-SORT 2: " << srt1 << endl << endl;

	srt1.setRandomData(initVal);
	fileOut << "srt1 PRE-SHELL SORT: " << srt1 << endl;
	srt1.ShellSort();
	fileOut << srt1.getComparisons() << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "SHELL-SORT: " << srt1 << endl << endl;

	srt1.setRandomData(initVal);
	fileOut << endl << "srt1 PRE-SELECTION SORT: " << srt1 << endl;
	srt1.selectionSort();
	fileOut << srt1.getComparisons() << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "POST-SELECTION SORT: " << srt1 << endl << endl;
	
	srt1.setRandomData(initVal);
	fileOut << "srt1 PRE-BUBBLE SORT: " << srt1 << endl;
	srt1.bubbleSort();
	fileOut << srt1.getComparisons() << " comparisons; ";
	fileOut << srt1.getNumberSwap() << " swaps." << endl;
	fileOut << "POST-BUBBLE SORT: " << srt1 << endl << endl;
	
	srt1.binarySearch(rand() % initVal, fileOut);
	fileOut << srt1.getComparisons() << " comparisons performed in the search." << endl;

	fileOut.close();

	return EXIT_SUCCESS;
}

