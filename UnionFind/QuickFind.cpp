//
//  QuickFind.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#include "QuickFind.h"

QuickFind::QuickFind(int numberOfNodes) : id(*new vector<int>(numberOfNodes)) {
    for (int i = 0; i < numberOfNodes; i++) {
        id[i] = i;
    }
}

QuickFind::~QuickFind() {
    delete &id;
}

void QuickFind::connect(int p, int q) {
    if (isConnected(p, q)) return;
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < id.size(); i++) {
        if (id[i] == pid) id[i] = qid;
    }
}

bool QuickFind::isConnected(int p, int q) {
    if (p < id.size() && q < id.size()) {
        return id[p] == id[q];
    }
    return false;
}

