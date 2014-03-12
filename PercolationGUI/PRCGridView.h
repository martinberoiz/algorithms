//
//  PRCGridView.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/11/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface PRCGridView : NSView {
    unsigned char** grid;
    int gridSide;
}

@property (readwrite) int gridSide;
-(void)setGrid:(unsigned char **)newGrid;

@end
