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
        numberSwap = 0;
    }

    ~Sorting() { clear(); }
    long getSize() {return size;}
    void setRandomData(int newSize);
    long getNumberSwap(){return numberSwap;}
    void resetSwap() { numberSwap = 0; }
    void allocateMemory(int newSize);
    long selectionSort();
    long bubbleSort();
    long quickSort(int first, int last);
	long quickSort();
    long binarySearch(int query, ostream &fOut);
    void heapsort(int &hsp);
    void moveDown(int first, int last, int& hscomps);
    int ShellSort();
    int ShellSort2();

    template <class S>
    friend ostream& operator <<(ostream& fOut, const Sorting<S>& srt);
};
#endif

