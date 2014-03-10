//
//  QuickFind.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

/******************************************************************************
 *                                                                            *
 *  This is an implementation of the Quick Find algorithm (eager algorithm).  *
 *                                                                            *
 ******************************************************************************/

#ifndef __Algorithms__QuickFind__
#define __Algorithms__QuickFind__

#include <iostream>
#include <vector>
#include <string>
#include "UnionFind.h"


class QuickFind : public UnionFind {
public:
    QuickFind(int numberOfNodes);
    ~QuickFind();
    
    string methodName() {return string("Quick Find");};
    void connect(int p, int q);
    bool isConnected(int p, int q);
    
private:
    vector<int>& id;
};

#endif /* defined(__Algorithms__QuickFind__) */
