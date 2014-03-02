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
#include <vector>

using namespace std;

template <typename T> void printArray(T* array, int len);
template <typename T> void sorttest(T* array, int len, SortStrategy* strat);


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
    
    //int data_int[] = {4, 3, 7, 6, 1, 2, 10, 8, 5, 9};
    //int lendata_int = 10;

    printf("Original unsorted array: \n");
    printArray(data_dbl, lendata_dbl);
    printf("\n\n");
    

    vector<SortStrategy*>* allstrats = new vector<SortStrategy*>();
    SelectionSortStrategy* sel = new SelectionSortStrategy();
    allstrats->push_back(sel);
    BubbleSortStrategy* bbl = new BubbleSortStrategy();
    allstrats->push_back(bbl);
    
    for (vector<SortStrategy*>::iterator aStrat = allstrats->begin();
         aStrat != allstrats->end();
         ++aStrat)
    {
        double* data_dbl_copy = (double*)malloc(lendata_dbl*sizeof(*data_dbl));
        memcpy(data_dbl_copy, data_dbl, lendata_dbl*sizeof(*data_dbl));
        sorttest(data_dbl_copy, lendata_dbl, *aStrat);
        //sorttest(data_int, lendata_int, *aStrat);
    }
    
     return 0;
}

template <typename T> void sorttest(T* array, int len, SortStrategy* aStrat)
{
    aStrat->sort(array, 10);
    
    cout << "After sorting with " << aStrat->methodName() << endl;
    printArray(array, len);
    printf("\n");
}


template <typename T> void printArray(T* array, int len)
{
    for (int i = 0; i < len - 1; i++) {cout << array[i] << ", ";}
    cout << array[len - 1] << endl;
}

