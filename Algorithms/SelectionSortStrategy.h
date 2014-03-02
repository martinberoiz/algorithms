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

class SelectionSortStrategy : public SortStrategy {
public:
    
    std::string methodName() {return "Selection Sort";}
    //int methodName() {return 1;}

    void sort(double* array, int lendata = 0); /*{
        for (int i = 0; i < lendata - 1; i++) {
            int min_ind = findMinIndex(array + i, lendata - i);
            swap(array, i, min_ind + i);
        }
    };*/

private:
    template <typename T>
    void swap(T* array, int ind1, int ind2) {
        if (ind1 == ind2) return;
        T temp = array[ind1];
        array[ind1] = array[ind2];
        array[ind2] = temp;
    }
    
    template <typename T>
    int findMinIndex(T* array, int len) {
        T min = array[0];
        int min_ind = 0;
        for (int i = 1; i < len; i++) {
            if (array[i] <= min) {
                min = array[i];
                min_ind = i;
            }
        }
        return min_ind;
    }
};

#endif /* defined(__Algorithms__SelectionSortStrategy__) */
