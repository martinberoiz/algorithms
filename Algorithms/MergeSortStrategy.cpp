//
//  MergeSortStrategy.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/29/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//
#include <vector>

template <class T> MergeSortStrategy<T>::MergeSortStrategy() {
    workArray = new std::vector<T>();
}

template <class T> MergeSortStrategy<T>::~MergeSortStrategy() {
    if (workArray) delete workArray;
}


template <class T> void MergeSortStrategy<T>::sort(T* array, int len) {
    workArray->reserve(len);
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

    workArray->clear();
    T* subArray1 = arrayPointer;
    T* subArray2 = arrayPointer + len1;
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (subArray1[i] > subArray2[j]) {
            workArray->push_back(subArray2[j]);
            j++;
        } else {
            workArray->push_back(subArray1[i]);
            i++;
        }
    }
    if (i == len1) {
        for (int k = j; k < len2; k++) {
            workArray->push_back(subArray2[k]);
        }
    }
    if (j == len2) {
        for (int k = i; k < len1; k++) {
            workArray->push_back(subArray1[k]);
        }
    }
    for (int i = 0; i < workArray->size(); i++) arrayPointer[i] = (*workArray)[i];
    
}



