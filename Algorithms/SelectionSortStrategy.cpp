//
//  SelectionSortStrategy.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/1/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//


#include "SelectionSortStrategy.h"


void SelectionSortStrategy::sort(double* array, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min_ind = findMinIndex(array + i, len - i);
        swap(array, i, min_ind + i);
    }
}

