//
//  InsertionSortStrategy.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/7/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef __Algorithms__InsertionSortStrategy__
#define __Algorithms__InsertionSortStrategy__

#include <string>
#include "SortStrategy.h"

template <class T> class InsertionSortStrategy : public SortStrategy<T> {
public:
    std::string methodName() {return std::string("Insertion Sort");}
    void sort(T* array, int lendata = 0);
private:
    void insert(T* subarray, int indexToInsert, int indexInsertPosition);
};

#include "InsertionSortStrategy.cpp"

#endif /* defined(__Algorithms__InsertionSortStrategy__) */
