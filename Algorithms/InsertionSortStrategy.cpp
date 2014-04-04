//
//  InsertionSortStrategy.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/7/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

template <class T> void InsertionSortStrategy<T>::sort(T* array, int len) {
    for (int i = 1; i < len; i++) {
        //Find the insertion point:
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (array[i] >= array[j]) break;
        }
        j++;
        insert(array, i, j);
    }
    return;
}


template <class T> void InsertionSortStrategy<T>::insert(T* a, int i, int j) {
    T temp = a[i];
    memmove(a + j + 1, a + j, (i - j)*sizeof(T));
    a[j] = temp;
}


/*
for (int ind = 1; ind < len; ind++) {
    for (int i = ind; i > 0; i--) {
        if (array[i] < array[i-1]) {
            swap(array, i, i-1);
        } else break;
    }
}
*/
