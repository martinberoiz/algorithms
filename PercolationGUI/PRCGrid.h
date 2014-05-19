//
//  PRCGrid.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "WeightedQuickUnion.h"

@interface PRCGrid : NSObject {
    int gridSide;
    int gridSize;
    WeightedQuickUnion* wqu;
    unsigned char** grid;
    int nopenings;
    int vp_top, vp_bottom;
}

-(void)openSiteAtRow: (int)row andColumn: (int)col;
-(void)setGridSide: (int)newGridSide;
-(unsigned char **)grid;
-(BOOL)didPercolate;
-(BOOL)isConnectedWithTopForRow:(int)row andColumn:(int)col;

@end
