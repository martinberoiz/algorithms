//
//  UnionFind.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#ifndef __Algorithms__UnionFind__
#define __Algorithms__UnionFind__

#include <iostream>
#include <string>
using namespace std;

class UnionFind {
public:
    virtual string methodName() = 0;
    virtual void connect(int p, int q) = 0;
    virtual bool isConnected(int p, int q) = 0;
    
};

#endif /* defined(__Algorithms__UnionFind__) */
