//
//  ufTest.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#include <stdio.h>
#include "UnionFind.h"
#include "QuickFind.h"
#include "QuickUnion.h"

using namespace std;

bool testUnionFind(UnionFind &uf);

int main() {
    
    QuickFind qf(10);
    testUnionFind(qf);
    
    QuickUnion qu(10);
    testUnionFind(qu);
    
    return 0;
}


bool testUnionFind(UnionFind &uf) {
    uf.connect(4, 3);
    uf.connect(3, 8);
    uf.connect(6, 5);
    uf.connect(9, 4);
    uf.connect(2, 1);
    
    bool pass = true;
    pass = (uf.isConnected(8, 9) == true);
    pass = pass && (uf.isConnected(5, 4) == false);
    
    uf.connect(5, 0);
    uf.connect(7, 2);
    uf.connect(6, 1);
    uf.connect(7, 3);
    
    pass = pass && (uf.isConnected(0, 9));

    printf("Test%spassed.\n", pass ? " ": " not ");

    return pass;
}

