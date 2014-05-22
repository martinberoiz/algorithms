//
//  SortStrategy.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/1/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef __Algorithms__SortStrategy__
#define __Algorithms__SortStrategy__

#include <iostream>
#include <string>

template <class T> class SortStrategy {
public:
    virtual std::string methodName() = 0;
    virtual void sort(T* array, int len = 0) = 0;
    bool isSorted(T* array, int len) {
        for (int i = 0; i < len - 1; i++) {
            if (array[i] > array[i + 1]) return false;
        }
        return true;
    }
};

#endif /* defined(__Algorithms__SortStrategy__) */
