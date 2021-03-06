//
//  PRCGridView.h
//  Algorithms
//
//  Created by Martin Beroiz on 3/11/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class PRCAppDelegate;

@interface PRCGridView : NSView {
    unsigned char** grid;
    int gridSide;
    __unsafe_unretained id viewController;
    SEL isFlooded;
}

@property (readwrite) int gridSide;
-(void)setGrid:(unsigned char **)newGrid;
-(void)setViewController:(id)aController forSelector:(SEL) aSelector;

@end
