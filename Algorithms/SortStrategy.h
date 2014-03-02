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

class SortStrategy {
public:
    virtual std::string methodName() = 0;
    virtual void sort(double* array, int len = 0) = 0;

};

#endif /* defined(__Algorithms__SortStrategy__) */
