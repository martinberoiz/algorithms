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
        // Initialization code here.
        grid = NULL;
        gridSide = 0;
        viewController = nil;
    }
    return self;
}

-(void)setGrid:(unsigned char **)newGrid {
    grid = newGrid;
}

-(void)setViewController:(id)aController forSelector:(SEL) aSelector {
    viewController = aController;
    isFlooded = aSelector;
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

    CGContextSetRGBFillColor (myContext, .1, .1, .8, 1);
    
    CGFloat shrinkFactor = 0.1;
    CGRect topRect = CGRectMake(gridRect.origin.x,
                                gridRect.origin.y,
                                gridRect.size.width,
                                gridRect.size.height * shrinkFactor / 2.);
    
    CGContextFillRect (myContext, topRect);
    CGContextStrokeRect(myContext, topRect);

    CGRect bottomRect = CGRectMake(gridRect.origin.x,
                                   gridRect.origin.y + NSHeight(gridRect) * (1. - shrinkFactor / 2.),
                                   gridRect.size.width,
                                   gridRect.size.height * shrinkFactor / 2.);
    
    CGContextFillRect (myContext, bottomRect);
    CGContextStrokeRect(myContext, bottomRect);


    //Shrink it a little bit to draw water tower and lake
    CGFloat channelHeight = gridRect.size.height * 0.1;
    gridRect.origin.y += channelHeight / 2.;
    gridRect.size.height -= channelHeight;

    
    for (int i = 0; i < gridSide; i++) {
        int yi = i*gridRect.size.height/gridSide + gridRect.origin.y;
        int yf = (i+1)*gridRect.size.height/gridSide + gridRect.origin.y;
        for (int j = 0; j < gridSide; j++) {
            if (grid != NULL) {
    
                if (grid[i][j] == 1) {
                    
                    BOOL flood = NO;
                    if ([viewController respondsToSelector:isFlooded]) {
                        
                        IMP imp = [viewController methodForSelector:isFlooded];
                        BOOL (*checkIfFlooded)(id, SEL, NSNumber*, NSNumber*) = (void *)imp;
                        flood = checkIfFlooded(viewController,
                                               isFlooded,
                                               [NSNumber numberWithInt:i],
                                               [NSNumber numberWithInt:i]);
                        /*flood = (BOOL)[viewController performSelector: isFlooded
                                                           withObject: [NSNumber numberWithInt:i]
                                                           withObject: [NSNumber numberWithInt:j]
                                       ];*/
                    }
                    if (flood) {
                        CGContextSetRGBFillColor (myContext, .1, .1, .8, 1);
                    } else {
                        CGContextSetRGBFillColor (myContext, .1, .1, .1, 1);
                    }
                    
                } else {
                    CGContextSetRGBFillColor (myContext, 0.8, 0.8, 0.8, 1);                    
                }
            } else {
                CGContextSetRGBFillColor (myContext, 0.8, 0.8, 0.8, 1);
            }
            int xi = j*gridRect.size.width/gridSide + gridRect.origin.x;
            int xf = (j+1)*gridRect.size.width/gridSide + gridRect.origin.x;
            CGContextFillRect (myContext, CGRectMake(xi, yi, xf - xi, yf - yi));
            CGContextStrokeRect(myContext, CGRectMake(xi, yi, xf - xi, yf - yi));
        }
    }
    
}

@end
