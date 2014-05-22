//
//  SelectionSortStrategy.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/1/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef __Algorithms__SelectionSortStrategy__
#define __Algorithms__SelectionSortStrategy__

#include <iostream>
#include "SortStrategy.h"
#include <string>

template <class T> class SelectionSortStrategy : public SortStrategy<T> {
public:
    std::string methodName() {return std::string("Selection Sort");}
    void sort(T* array, int lendata = 0);

private:
    void swap(T* array, int ind1, int ind2);
    int findMinIndex(T* array, int len);
};

#include "SelectionSortStrategy.cpp"

#endif /* defined(__Algorithms__SelectionSortStrategy__) */


