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
    while (i < len1 && j < len2) {
        if (subArray1[i] > subArray2[j]) {
            arrayPointer[ind] = subArray2[j];
            j++;
        } else {
            arrayPointer[ind] = subArray1[i];
            i++;
        }
        ind++;
    }
    
    //If the loop exited with the second array exhausted, put the remaining elements
    //of the first subarray at the end of the arrayPointer. (This is not necessary if the first
    //subarray is exhausted first, since the elements of the 2nd subarray are already copied in arrayPointer.
    if (j == len2) {
        for (int k = i; k < len1; k++) {
            arrayPointer[ind++] = subArray1[k];
        }
    }
}

/*template <class T> void MergeSortStrategy<T>::merge_old(T* arrayPointer, int len1, int len2) {
    
    workVector->clear();
    T* subArray1 = arrayPointer;
    T* subArray2 = arrayPointer + len1;
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (subArray1[i] > subArray2[j]) {
            workVector->push_back(subArray2[j]);
            j++;
        } else {
            workVector->push_back(subArray1[i]);
            i++;
        }
    }
    if (i == len1) {
        for (int k = j; k < len2; k++) {
            workVector->push_back(subArray2[k]);
        }
    }
    if (j == len2) {
        for (int k = i; k < len1; k++) {
            workVector->push_back(subArray1[k]);
        }
    }
    for (int i = 0; i < workVector->size(); i++) arrayPointer[i] = (*workVector)[i];
    
}*/


