//
//  BubbleSortStrategy.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/1/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#include "BubbleSortStrategy.h"

template <class T> void BubbleSortStrategy<T>::sort(T* array, int len) {
    bool swapflag = true;
    for (int n = len; swapflag == true; n--) {
        swapflag = false;
        for (int i = 0; i < n - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(array, i, i + 1);
                swapflag = true;
            }
        }
    }
}
