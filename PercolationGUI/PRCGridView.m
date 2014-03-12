//
//  PRCGridView.m
//  Algorithms
//
//  Created by Martin Beroiz on 3/11/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#import "PRCGridView.h"

@implementation PRCGridView

@synthesize gridSide;

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        grid = NULL;
        gridSide = 0;
        // Initialization code here.
    }
    return self;
}

-(void)setGrid:(unsigned char **)newGrid {
    grid = newGrid;
}

- (void)drawRect:(NSRect)dirtyRect
{

    NSRect boundRect = [self bounds];
    NSRect gridRect;
    if (NSWidth(boundRect) > NSHeight(boundRect)) {
        int xorig = (NSWidth(boundRect) - NSHeight(boundRect))/2;
        gridRect = NSMakeRect(xorig,
                              boundRect.origin.y,
                              NSHeight(boundRect),
                              NSHeight(boundRect));
    } else {
        int yorig = (NSHeight(boundRect) - NSWidth(boundRect))/2;
        gridRect = NSMakeRect(boundRect.origin.x,
                              yorig,
                              NSWidth(boundRect),
                              NSWidth(boundRect));
    }
    
    CGContextRef myContext = [[NSGraphicsContext currentContext] graphicsPort];

    for (int i = 0; i < gridSide; i++) {
        int yi = i*gridRect.size.height/gridSide + gridRect.origin.y;
        int yf = (i+1)*gridRect.size.height/gridSide + gridRect.origin.y;
        for (int j = 0; j < gridSide; j++) {
            if (grid != NULL) {
                if (grid[i][j] == 1) {
                    CGContextSetRGBFillColor (myContext, .1, .1, .8, 1);
                } else {
                    CGContextSetRGBFillColor (myContext, 0.8, 0.8, 0.8, 1);                    
                }
            } else {
                CGContextSetRGBFillColor (myContext, 0.8, 0.8, 0.8, 1);
            }
            int xi = j*gridRect.size.width/gridSide + gridRect.origin.x;
            int xf = (j+1)*gridRect.size.width/gridSide + gridRect.origin.x;
            CGContextFillRect (myContext, CGRectMake (xi, yi, xf - xi, yf - yi));
            CGContextStrokeRect(myContext, CGRectMake (xi, yi, xf - xi, yf - yi));
        }
    }
    
    /*NSBezierPath* aLine = [NSBezierPath bezierPath];
    [aLine moveToPoint:boundRect.origin];
    [aLine lineToPoint:NSMakePoint(boundRect.origin.x + boundRect.size.width, boundRect.origin.y + boundRect.size.height)];
    [aLine stroke];*/

}

@end
