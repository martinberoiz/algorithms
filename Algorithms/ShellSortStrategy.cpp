//
//  ShellSortStrategy.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/21/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//



template <class T> void ShellSortStrategy<T>::sort(T* array, int len) {
    hInsertSort(5, array, len);
    hInsertSort(3, array, len);
    hInsertSort(1, array, len);
}


template <class T> void ShellSortStrategy<T>::hInsertSort(int h, T* array, int len) {

    for (int ind = h; ind < len; ind++) {
        for (int i = ind; i > 0; i -= h) {
            if (array[i] < array[i - h]) {
                swap(array, i, i - h);
            } else break;
        }
    }
    
}

template <class T> void ShellSortStrategy<T>::swap(T* data, int ind1, int ind2) {
    T temp = data[ind1];
    data[ind1] = data[ind2];
    data[ind2] = temp;
}