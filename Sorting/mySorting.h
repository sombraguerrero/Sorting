#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifndef _SORT_H_
#define _SORT_H_

template <class T>
class Sorting {
private:
    T* data;
    long  size;
    long numberSwap;
    int compCount;

    void clear() {
        if (data != NULL) {
            delete [] data;
            data = NULL;
            size = 0;
        }
    }

    // Private versions of the sort functions: system use
    long selectionSortPrv() { selectionSort(); }

public:
    Sorting(){ size=0; data = NULL; numberSwap=0; }
    Sorting(int n){
        assert(n >= 10);
        size = n;
        data = new T[size];
        numberSwap = compCount = 0;
    }

    ~Sorting() { clear(); }
    long getSize() {return size;}
    int getComparisons() { return compCount; }
    void LoadArray(bool sequential);
    void Shuffle();
    long getNumberSwap(){return numberSwap;}
    void resetCounters() { numberSwap = compCount = 0; }
    void selectionSort();
    void bubbleSort();
    int quickSort(int first, int last);
	int quickSort();
    void binarySearch(int query, ostream &fOut);
    void heapsort();
    void moveDown(int first, int last);
    void ShellSort();
    void ShellSort2();
    void InterpSearch(int query, ostream& fOut);
    int RandomQuery() { return data[rand() % size]; }

    template <class S>
    friend ostream& operator <<(ostream& fOut, const Sorting<S>& srt);
};
#endif

