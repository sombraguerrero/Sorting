#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mySorting.h"
using namespace std;

template <class T>
long Sorting<T>::quickSort() {
	numberSwap = 0;

	return quickSort(0, size-1);
}

template<class T>
void Sorting<T>::moveDown(int first, int last, int &hscomps) {
	int largest = 2 * first + 1;
	while (largest <= last) {
		if (largest < last && // first has two children (at 2*first+1 and
			data[largest] < data[largest + 1]) // 2*first+2) and the second
		{
			largest++; // is larger than the first;
			hscomps++;
		}


		if (data[first] < data[largest]) {   // if necessary,
			swap(data[first], data[largest]);// swap child and parent,
			numberSwap++;
			hscomps++;
			first = largest;                // and move down;
			largest = 2 * first + 1;
		}
		else largest = last + 1;  // to exit the loop: the heap property
	}                           // isn't violated by data[first];
}

template<class T>
void Sorting<T>::heapsort(int& hsc) {
	resetSwap();
	int i;
	hsc = 0;
	for (i = size / 2 - 1; i >= 0; --i)   // create the heap;
		moveDown(i, size - 1, hsc);
	for (i = size - 1; i >= 1; --i) {
		swap(data[0], data[i]); // move the largest item to data[i];
		numberSwap++;
		moveDown(0, i - 1, hsc);  // restore the heap property;
	}
}

template<class T>
long Sorting<T>::quickSort(int first, int last)
{
	resetSwap();
	long numberComp = 0;
	int lower = first+1, upper = last;
	numberSwap++;
	swap(data[first],data[(first+last)/2]);
	T bound = data[first];
	while (lower <= upper) {
		numberComp++;
		while (data[lower] < bound){
			numberComp++;
			lower++;
		}
		numberComp++;
		while (bound < data[upper]){
			numberComp++;
			upper--;
		}
		if (lower < upper) {
			numberSwap++;
			swap(data[lower++],data[upper--]);
		}
		else { lower++; }
	}
	numberSwap++;
	swap(data[upper],data[first]);
	if (first < upper-1)
		numberComp += quickSort (first,upper-1);
	if (upper+1 < last)
		numberComp += quickSort (upper+1,last);

	return numberComp;
}

template <class T>
long Sorting<T>::binarySearch(int query, ostream &fOut) {
	long comp = 0L;
	int mid;
	int first = 0;
	int last = size-1;
	bool found = false;

	while (first <= last && !found) {
		mid = (first+last)/2;
		if (data[mid]==query) {
			found = true;
			break;
		}
		else if (data[mid] < query) {
			first = mid+1;
		}
		else {
			last = mid-1;
		}
		comp++;
	}
	if (found) {
		fOut << "The queried value of " << query << " was found in data[" << mid << "]." << endl;
	}
	else {
		fOut << "The query was NOT found!" << endl;
	}
	return comp;
}

template <class T>
long Sorting<T>::bubbleSort() {
	long numComp = 0;
	resetSwap();

	for (int i=0; i<size-1; i++) {
		for (int j=0; j<size-1-i; j++) {
			numComp++;
			if (data[j] > data[j+1]) {
				numberSwap++;
				swap(data[j], data[j+1]);
			}
		}
	}
	return numComp;

}

template <class T>
int Sorting<T>::ShellSort()
{
	bool isDone = true;
	int gap = size / 2;
	int comps = 0;
	resetSwap();
	while (gap >= 1)
	{
		do
		{
			isDone = true;
			for (int i = 0; i < size - gap; i++)
			{
				comps++;
				if (data[i] > data[i + gap])
				{
					numberSwap++;
					swap(data[i], data[i + gap]);
					isDone = false;
				}
			}
		} while (!isDone);
		gap /= 2;
	}
	return comps;
}

template <class T>
int Sorting<T>::ShellSort2()
{
	int i, j, hCnt, h;
	int increments[20], k;
	int comps = 0;
	resetSwap();
	//  create an appropriate number of increments h
	for (h = 1, i = 0; h < size; i++)
	{
		increments[i] = h;
		h = 3 * h + 1;
	}
	// loop on the number of different increments h
	for (i--; i >= 0; i--)
	{
		h = increments[i];
		// loop on the number of subarrays h-sorted in ith pass
		for (hCnt = h; hCnt < 2 * h; hCnt++)
		{
			// insertion sort for subarray containing every hth element of array data
			for (j = hCnt; j < size; )
			{
				T tmp = data[j];
				numberSwap++;
				k = j;
				while (k - h >= 0 && tmp < data[k - h])
				{
					comps++;
					data[k] = data[k - h];
					k -= h;
				}
				data[k] = tmp;
				j += h;
			}
		}
	}
	return comps;
}

template <class T>
void Sorting<T>::setRandomData(int newSize) {
	allocateMemory(newSize);
	for( int i = 0; i < size; i++ ) {
		data[i] = (T) ( rand()%newSize);
	}
}

template <class T>
void Sorting<T>:: allocateMemory(int newSize){
	assert(newSize > 0);
	if(size == newSize   &&  size != 0  && data != NULL){
		return;
	}

	if (data != NULL){
		delete [] data;
	}
	size = newSize;
	data = new T[size];

}

template <class T>
long Sorting<T>::selectionSort(){
	long comparisons = 0;
	resetSwap();
	for (int i = 0, least, j; i < size-1; i++) {
		for (j = i+1, least = i; j < size; j++){
			comparisons++;
			if (data[j] < data[least]){
				least = j;
			}
		}
		numberSwap++;
		swap(data[least], data[i]);
	}
	return comparisons;
}

template <class T>
ostream& operator <<(ostream& fOut, const Sorting<T>& srt)
{
	fOut.put('[');
	for(int i=0; i<srt.size-1; i++)
	{
		fOut << srt.data[i] << ',';
	}
	fOut << srt.data[srt.size - 1] << ']';
	return fOut;
}

