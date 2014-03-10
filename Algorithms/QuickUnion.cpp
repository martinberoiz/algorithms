//
//  QuickUnion.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#include "QuickUnion.h"

QuickUnion::QuickUnion(int numberOfNodes) : id(*new vector<int>(numberOfNodes)) {
    for (int i = 0; i < numberOfNodes; i++) {
        id[i] = i;
    }
}

QuickUnion::~QuickUnion() {
    delete &id;
}

void QuickUnion::connect(int p, int q) {
    id[root(p)] = root(q);
}

bool QuickUnion::isConnected(int p, int q) {
    return root(p) == root(q);
}

int QuickUnion::root(int p) {
    while (p != id[p]) {p = id[p];}
    return p;
}

