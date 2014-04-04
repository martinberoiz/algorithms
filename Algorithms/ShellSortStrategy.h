//
//  ShellSortStrategy.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/21/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef __Algorithms__ShellSortStrategy__
#define __Algorithms__ShellSortStrategy__

#include <iostream>
#include "SortStrategy.h"

template <class T> class ShellSortStrategy : public SortStrategy<T> {
public:
    std::string methodName() {return std::string("Shell Sort");}
    void sort(T* array, int len = 0);

private:
    void hInsertSort(int h, T* array, int len);
    void swap(T* data, int ind1, int ind2);

};

#include "ShellSortStrategy.cpp"

#endif /* defined(__Algorithms__ShellSortStrategy__) */
