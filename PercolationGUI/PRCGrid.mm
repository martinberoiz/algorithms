//
//  PRCGrid.m
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#import "PRCGrid.h"

@implementation PRCGrid

-(id)init {
    grid = NULL;
    nopenings = 0;
    vp_top = vp_bottom = 0;
    return self;
}

-(void)setGridSide: (int)newGridSide {
    if (newGridSide == gridSide) return;
    gridSide = newGridSide;
    gridSize = gridSide * gridSide;
    if (wqu) delete wqu;
    wqu = new WeightedQuickUnion(gridSize + 2);

    if (grid != NULL) {
        if (grid[0] != NULL) free(grid[0]);
        free(grid);
    }
    grid = (unsigned char**)malloc(gridSide*sizeof(*grid));
    grid[0] = (unsigned char*)calloc(gridSide*gridSide, sizeof(**grid));
    for (int i = 1; i < gridSide; i++) grid[i] = grid[i - 1] + gridSide;
    
    //Connect here top and bottom virtual points
    //virtual endpoints will be gridsz and gridsz + 1
    vp_top = gridSize;
    vp_bottom = gridSize + 1;
    for (int i = 0; i < gridSide; i++) {
        wqu->connect(vp_top, i);
    }
    for (int i = gridSide*(gridSide - 1); i < gridSize; i++) {
        wqu->connect(vp_bottom, i);
    }

};

-(void)openSiteAtRow: (int)row andColumn: (int)col {
    
    if (grid[row][col] == 1) return;
    grid[row][col] = 1;
    
    int site = row*gridSide + col;
    
    //Now add all new 4 possible connections
    if (row != 0 && grid[row - 1][col] == 1) {
        wqu->connect(site, site - gridSide);
    }
    if (row != gridSide - 1 && grid[row + 1][col] == 1) {
        wqu->connect(site, site + gridSide);
    }
    if (col != 0 && grid[row][col - 1] == 1) {
        wqu->connect(site, site - 1);
    }
    if (col != gridSide - 1 && grid[row][col + 1] == 1) {
        wqu->connect(site, site + 1);
    }
    nopenings++;

}

-(BOOL)didPercolate {
    return wqu->isConnected(vp_top, vp_bottom);
}

-(BOOL)isConnectedWithTopForRow:(int)row andColumn:(int)col {
    int site = row * gridSide + col;
    if (site < gridSize && site >= 0) {
        return wqu->isConnected(site, vp_top);
    }
    return NO;
}

-(unsigned char **)grid {
    return grid;
}

@end
