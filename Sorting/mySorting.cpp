#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mySorting.h"
using namespace std;

template <class T>
int Sorting<T>::quickSort() {
	return quickSort(0, size-1);
}

template<class T>
void Sorting<T>::moveDown(int first, int last) {
	int largest = 2 * first + 1;
	while (largest <= last) {
		if (largest < last && // first has two children (at 2*first+1 and
			data[largest] < data[largest + 1]) // 2*first+2) and the second
		{
			largest++; // is larger than the first;
			compCount++;
		}


		if (data[first] < data[largest]) {   // if necessary,
			swap(data[first], data[largest]);// swap child and parent,
			numberSwap++;
			compCount++;
			first = largest;                // and move down;
			largest = 2 * first + 1;
		}
		else largest = last + 1;  // to exit the loop: the heap property
	}                           // isn't violated by data[first];
}

template<class T>
void Sorting<T>::heapsort() {
	resetCounters();
	int i;
	for (i = size / 2 - 1; i >= 0; --i)   // create the heap;
		moveDown(i, size - 1);
	for (i = size - 1; i >= 1; --i) {
		swap(data[0], data[i]); // move the largest item to data[i];
		numberSwap++;
		moveDown(0, i - 1);  // restore the heap property;
	}
}

template<class T>
int Sorting<T>::quickSort(int first, int last)
{
	resetCounters();
	int lower = first+1, upper = last;
	numberSwap++;
	swap(data[first],data[(first+last)/2]);
	T bound = data[first];
	while (lower <= upper) {
		compCount++;
		while (data[lower] < bound){
			compCount++;
			lower++;
		}
		compCount++;
		while (bound < data[upper]){
			compCount++;
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
		compCount += quickSort (first,upper-1);
	if (upper+1 < last)
		compCount += quickSort (upper+1,last);
	return compCount;
}

template <class T>
void Sorting<T>::binarySearch(int query, ostream &fOut) {
	resetCounters();
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
		compCount++;
	}
	if (found) {
		fOut << "The queried value of " << query << " was found in data[" << mid << "]." << endl;
	}
	else {
		fOut << "The query was NOT found!" << endl;
	}
}

template <class T>
void Sorting<T>::bubbleSort() {
	resetCounters();

	for (int i=0; i<size-1; i++) {
		for (int j=0; j<size-1-i; j++) {
			compCount++;
			if (data[j] > data[j+1]) {
				numberSwap++;
				swap(data[j], data[j+1]);
			}
		}
	};

}

template <class T>
void Sorting<T>::ShellSort()
{
	bool isDone = true;
	int gap = size / 2;
	resetCounters();
	while (gap >= 1)
	{
		do
		{
			isDone = true;
			for (int i = 0; i < size - gap; i++)
			{
				compCount++;
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
}

template <class T>
void Sorting<T>::ShellSort2()
{
	int i, j, hCnt, h;
	int increments[20], k;
	resetCounters();
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
					compCount++;
					data[k] = data[k - h];
					k -= h;
				}
				data[k] = tmp;
				j += h;
			}
		}
	}
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
void Sorting<T>::selectionSort(){
	resetCounters();
	for (int i = 0, least, j; i < size-1; i++) {
		for (j = i+1, least = i; j < size; j++){
			compCount++;
			if (data[j] < data[least]){
				least = j;
			}
		}
		numberSwap++;
		swap(data[least], data[i]);
	}
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

