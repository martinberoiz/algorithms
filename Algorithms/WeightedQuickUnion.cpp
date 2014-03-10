//
//  WeightedQuickUnion.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#include "WeightedQuickUnion.h"

WeightedQuickUnion::WeightedQuickUnion(int numberOfNodes) :
prnt(*new vector<int>(numberOfNodes)),
size(*new vector<int>(numberOfNodes))
{
    for (int i = 0; i < numberOfNodes; i++) {
        prnt[i] = i;
        size[i] = 1;
    }
}


WeightedQuickUnion::~WeightedQuickUnion() {
    delete &prnt;
}

void WeightedQuickUnion::connect(int p, int q) {
    int rp = root(p);
    int rq = root(q);
    if (size[rp] > size[rq]) {
        prnt[rq] = rp;
        size[rp] += size[rq];
    }
    else {
        prnt[rp] = rq;
        size[rq] += size[rp];
    }
}

bool WeightedQuickUnion::isConnected(int p, int q) {
    return root(p) == root(q);
}

int WeightedQuickUnion::root(int p) {
    while (p != prnt[p]) {p = prnt[p];}
    return p;
}

