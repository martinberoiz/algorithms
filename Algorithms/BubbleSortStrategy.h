//
//  BubbleSortStrategy.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/1/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef Algorithms_BubbleSortStrategy_h
#define Algorithms_BubbleSortStrategy_h

#include "SortStrategy.h"

class BubbleSortStrategy : public SortStrategy {
public:
    template <typename T> void sort(T* array, int lendata = 0) {
        bool swapflag = true;
        for (int n = lendata; swapflag == true; n--) {
            swapflag = false;
            for (int i = 0; i < n - 1; i++) {
                if (array[i] > array[i + 1]) {
                    swap(array, i, i + 1);
                    swapflag = true;
                }
            }
        }
    }
    
private:
    template <typename T>
    void swap(T* data, int ind1, int ind2) {
        T temp = data[ind1];
        data[ind1] = data[ind2];
        data[ind2] = temp;
    }

};

#endif
