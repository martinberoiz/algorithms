//
//  QuickUnion.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef __Algorithms__QuickUnion__
#define __Algorithms__QuickUnion__

#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;

class QuickUnion : public UnionFind {
public:
    QuickUnion(int numberOfNodes);
    ~QuickUnion();

    string methodName() {return string("Quick Union");};
    void connect(int p, int q);
    bool isConnected(int p, int q);
    
private:
    vector<int>& id;
    int root(int p);
};

#endif /* defined(__Algorithms__QuickUnion__) */
