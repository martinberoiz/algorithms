//
//  percolation.cpp
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#include <stdio.h>
#include "WeightedQuickUnion.h"
#include <cstring>

int drawOneRandomSite(int* grid, int gside, int& lastUsed);

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--version")) {
            printf("Version 0.1.1\n");
            return 0;
        }
    }

    int gside = 100;
    int gridsz = gside * gside;
    WeightedQuickUnion wqu(gridsz + 2);

    //virtual endpoints will be gridsz and gridsz + 1
    int vp1 = gridsz;
    int vp2 = gridsz + 1;
    for (int i = 0; i < gside; i++) {
        wqu.connect(vp1, i);
    }
    for (int i = gside*(gside - 1); i < gridsz; i++) {
        wqu.connect(vp2, i);
    }
    
    char** grid = (char**)malloc(gside*sizeof(*grid));
    grid[0] = (char*)calloc(gside*gside, sizeof(**grid));
    for (int i = 1; i < gside; i++) grid[i] = grid[i - 1] + gside;

    //get one random site:
    int* allsites = (int *)malloc(gridsz*sizeof(*allsites));
    for (int i = 0; i < gridsz; i++) allsites[i] = i;
    int lastUsed = 0;
    
    int nopenings = 0;
    while (!wqu.isConnected(vp1, vp2)) {
        //open a new gridpoint
        int site = drawOneRandomSite(allsites, gside, lastUsed);
        int row = site / gside;
        int col = site % gside;
        grid[row][col] = 1;
        
        //Now add all new 4 possible connections
        if (row != 0 && grid[row - 1][col] == 1) {
            wqu.connect(site, site - gside);
        }
        if (row != gside - 1 && grid[row + 1][col] == 1) {
            wqu.connect(site, site + gside);
        }
        if (col != 0 && grid[row][col - 1] == 1) {
            wqu.connect(site, site - 1);
        }
        if (col != gside - 1 && grid[row][col + 1] == 1) {
            wqu.connect(site, site + 1);
        }
        nopenings++;
    }
    
    printf("The system percolated with %d open sites.\n", nopenings);
    
    return 0;
    
}


int drawOneRandomSite(int* grid, int gside, int& lastUsed) {
    
    int indx = (rand() % (gside - (lastUsed % gside) + 1)) + lastUsed;

    int temp = grid[lastUsed];
    grid[lastUsed] = grid[indx];
    grid[indx] = temp;
    lastUsed++;
    
    return grid[lastUsed - 1];
}


