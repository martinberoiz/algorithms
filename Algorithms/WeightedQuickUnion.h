//
//  WeightedQuickUnion.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef __Algorithms__WeightedQuickUnion__
#define __Algorithms__WeightedQuickUnion__

#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;

class WeightedQuickUnion : public UnionFind {
public:
    WeightedQuickUnion(int numberOfNodes);
    ~WeightedQuickUnion();
    
    string methodName() {return string("Weighted Quick Union");};
    void connect(int p, int q);
    bool isConnected(int p, int q);
    
private:
    vector<int>& prnt;  //vector of parents in tree.
    vector<int>& size;  //size of the tree (for roots only)
    int root(int p);
};

#endif /* defined(__Algorithms__WeightedQuickUnion__) */
