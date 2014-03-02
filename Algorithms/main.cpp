//
//  main.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 2/28/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#include <iostream>
#include "SelectionSortStrategy.h"
#include "BubbleSortStrategy.h"

template <typename T>
void swap(T* data, int ind1, int ind2);

template <typename T>
int findMinIndex(T* data, int len);

template <typename T>
void bruteForceSort(T* data, int lendata);

int main(int argc, const char * argv[])
{
    double data[10];
    int lendata = 10;
    
    //fill in with random numbers
    srand(11);
    for (int i = 0; i < lendata; i++) data[i] = (double)rand();
    double randmax = data[0];
    for (int i = 1; i < lendata; i++) {
        if (data[i] > randmax) randmax = data[i];
    }
    for (int i = 0; i < lendata; i++) data[i] *= 10.;
    for (int i = 0; i < lendata; i++) data[i] /= randmax;
    
    
    printf("Before sorting: \n");
    for (int i = 0; i < lendata; i++) printf("%g, ", data[i]);
    printf("\n");

    //now sort:
    SelectionSortStrategy* sel = new SelectionSortStrategy();
    sel->sort(data, lendata);
    
    //bruteForceSort(data, lendata);
    
    printf("After sorting: \n");
    for (int i = 0; i < lendata; i++) printf("%g, ", data[i]);
    printf("\n");
    
    
    int intdata[] = {4, 3, 7, 6, 1, 2, 10, 8, 5, 9};
    bruteForceSort(intdata, 10);
    
    printf("After sorting: \n");
    for (int i = 0; i < 10; i++) printf("%d, ", intdata[i]);
    printf("\n");

}

template <typename T>
void bruteForceSort(T* data, int lendata) {
    for (int i = 0; i < lendata; i++) {
        int min_ind = findMinIndex(data + i, lendata - i);
        swap(data, i, min_ind + i);
    }
}

template <typename T>
void swap(T* data, int ind1, int ind2) {
    if (ind1 == ind2) return;
    T temp = data[ind1];
    data[ind1] = data[ind2];
    data[ind2] = temp;
}


template <typename T>
int findMinIndex(T* data, int len) {
    T min = data[0];
    int min_ind = 0;
    for (int i = 1; i < len; i++) {
        if (data[i] <= min) {
            min = data[i];
            min_ind = i;
        }
    }
    return min_ind;
}
