//
//  MergeSortStrategy.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/29/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef __Algorithms__MergeSortStrategy__
#define __Algorithms__MergeSortStrategy__

#include <iostream>
#include "SortStrategy.h"
#include <string>
#include <vector>

template <class T> class MergeSortStrategy : public SortStrategy<T> {
public:
    MergeSortStrategy();
    ~MergeSortStrategy();
    void sort(T* array, int len);
    std::string methodName() {return std::string("Merge Sort");}
    void topDownSort(T* array, int len);

private:
    void merge(T* arrayPointer, int len1, int len2);
    std::vector<T>* workVector;
    T* workArray;
};

#include "MergeSortStrategy.cpp"

#endif /* defined(__Algorithms__MergeSortStrategy__) */
