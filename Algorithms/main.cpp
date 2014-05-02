//
//  main.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 2/28/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#include <iostream>
#include "SortStrategy.h"
#include "SelectionSortStrategy.h"
#include "BubbleSortStrategy.h"
#include "InsertionSortStrategy.h"
#include "ShellSortStrategy.h"
#include "MergeSortStrategy.h"
#include <vector>

using namespace std;

template <typename T> void printArray(T* array, int len);
template <typename T> bool sorttest(T* array, int len, SortStrategy<T>* strat);
template <typename T> void iterateOverStrats(T* data, int lendata);


int main(int argc, const char * argv[])
{
    double data_dbl[10];
    int lendata_dbl = 10;
    
    //fill in with random numbers
    srand(11);
    data_dbl[0] = (double)rand();
    double randmax = data_dbl[0];
    for (int i = 1; i < lendata_dbl; i++)
    {
        data_dbl[i] = (double)rand();
        if (data_dbl[i] > randmax) randmax = data_dbl[i];
        data_dbl[i] *= 10.;
    }
    for (int i = 0; i < lendata_dbl; i++) data_dbl[i] /= randmax;
    
    
    iterateOverStrats(data_dbl, lendata_dbl);
    
    printf("\n--------------------\n");
    printf("Now with int's...\n\n");
    int data_int[] = {4, 3, 7, 6, 1, 2, 10, 8, 5, 9};
    int lendata_int = 10;
    
    iterateOverStrats(data_int, lendata_int);
    
    return 0;
}

template <typename T>
bool sorttest(T* array, int len, SortStrategy<T>* aStrat)
{
    aStrat->sort(array, len);
    
    cout << "After sorting with " << aStrat->methodName() << endl;
    printArray(array, len);
    
    return aStrat->isSorted(array, len);
    
}


template <typename T>
void printArray(T* array, int len)
{
    cout << "[";
    for (int i = 0; i < len - 1; i++) {cout << array[i] << ", ";}
    cout << array[len - 1] << "]" << endl;
}


template <typename T>
void iterateOverStrats(T* array, int len)
{
    printf("Original unsorted array: \n");
    printArray(array, len);
    printf("\n\n");
    
    vector< SortStrategy<T>* >* allStrats = new vector< SortStrategy<T>* >();
    SelectionSortStrategy<T>* sel = new SelectionSortStrategy<T>();
    allStrats->push_back(sel);
    BubbleSortStrategy<T>* bbl = new BubbleSortStrategy<T>();
    allStrats->push_back(bbl);
    InsertionSortStrategy<T>* insrt = new InsertionSortStrategy<T>();
    allStrats->push_back(insrt);
    ShellSortStrategy<T>* shl = new ShellSortStrategy<T>();
    allStrats->push_back(shl);
    MergeSortStrategy<T>* mrg = new MergeSortStrategy<T>();
    allStrats->push_back(mrg);
    
    for (typename vector<SortStrategy<T>*>::iterator aStrat = allStrats->begin();
         aStrat != allStrats->end();
         ++aStrat)
    {
        T* data_copy = (T*)malloc(len*sizeof(*array));
        memcpy(data_copy, array, len*sizeof(*array));
        bool pass = sorttest(data_copy, len, *aStrat);
        printf("Test%spassed.\n\n", pass ? " ": " not ");
    }
    delete sel;
    delete bbl;
    delete insrt;
    delete shl;
    delete mrg;
    delete allStrats;

}
