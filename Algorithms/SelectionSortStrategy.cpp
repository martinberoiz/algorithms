//
//  SelectionSortStrategy.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/1/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//



template<class T> void SelectionSortStrategy<T>::sort(T* array, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min_ind = findMinIndex(array + i, len - i);
        swap(array, i, min_ind + i);
    }
}

template<class T> void SelectionSortStrategy<T>::swap(T* array, int ind1, int ind2) {
    if (ind1 == ind2) return;
    T temp = array[ind1];
    array[ind1] = array[ind2];
    array[ind2] = temp;
}

template<class T> int SelectionSortStrategy<T>::findMinIndex(T* array, int len) {
    T min = array[0];
    int min_ind = 0;
    for (int i = 1; i < len; i++) {
        if (array[i] <= min) {
            min = array[i];
            min_ind = i;
        }
    }
    return min_ind;
}
