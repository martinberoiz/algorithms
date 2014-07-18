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
#include <string>

// Standard Bubble Sort sorting algorithm using swap method
template <class T> class BubbleSortStrategy : public SortStrategy<T> {
public:
    std::string methodName() {return std::string("Bubble Sort");}
    void sort(T* array, int len = 0);

private:
    void swap(T* data, int ind1, int ind2) {
        T temp = data[ind1];
        data[ind1] = data[ind2];
        data[ind2] = temp;
    }

};

#include "BubbleSortStrategy.cpp"

#endif
