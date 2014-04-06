//
//  MergeSortStrategy.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/29/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//
#include <vector>

template <class T> MergeSortStrategy<T>::MergeSortStrategy() {
    workArray = NULL;
}

template <class T> MergeSortStrategy<T>::~MergeSortStrategy() {
    if (workArray) free(workArray);
}


template <class T> void MergeSortStrategy<T>::sort(T* array, int len) {
    workArray = (T*)malloc(len*sizeof(T));
    topDownSort(array, len);
}

template <class T> void MergeSortStrategy<T>::topDownSort(T* array, int len) {
    
    if (len < 2) return;
    topDownSort(array, len/2);
    topDownSort(array + len/2, len/2 + len%2);
    merge(array, len/2, len/2 + len%2);
    return;
}

template <class T> void MergeSortStrategy<T>::merge(T* arrayPointer, int len1, int len2) {
    
    memcpy(workArray, arrayPointer, (len1 + len2) * sizeof(T));
    
    T* subArray1 = workArray;
    T* subArray2 = workArray + len1;
    int i = 0, j = 0, ind = 0;
    while (ind < len1 + len2) {
        if (i == len1) {
            arrayPointer[ind] = subArray2[j]; //This is actually not necessary
            j++;
        } else if(j == len2) {
            arrayPointer[ind] = subArray1[i];
            i++;
        } else if (subArray1[i] > subArray2[j]) {
            arrayPointer[ind] = subArray2[j];
            j++;
        } else {
            arrayPointer[ind] = subArray1[i];
            i++;
        }
        ind++;
    }
    
}

