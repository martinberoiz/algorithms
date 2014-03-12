//
//  PRCAppDelegate.m
//  PercolationGUI
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#import "PRCAppDelegate.h"
#import "PRCGrid.h"

@implementation PRCAppDelegate

@synthesize percolateTimer;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
    [self willChangeValueForKey:@"gridSide"];
    gridSide = 10;
    [self didChangeValueForKey:@"gridSide"];
    grid = NULL;
    [theView setGrid:grid];
    [theView setGridSide:gridSide];
    [theView setNeedsDisplay:YES];
    
    allSites = NULL;
}

-(void)setGridSide:(int)newGridSide {
    if (gridSide == newGridSide) return;
    gridSide = newGridSide;
    grid = NULL;
    [theView setGrid:NULL];
    [theView setGridSide:gridSide];
    [theView setNeedsDisplay:YES];
    
    [percolateTimer invalidate];
    percolateTimer = nil;
}

-(void)initPercolation:(id)sender {
    percGrid = [[PRCGrid alloc] init];
    [percGrid setGridSide:gridSide];
    grid = [percGrid grid];
    [theView setGrid:grid];
    [theView setNeedsDisplay:YES];
    
    //Initiate the timer:
    [percolateTimer invalidate];
    NSTimer* timer = [NSTimer scheduledTimerWithTimeInterval: 0.1
                                                      target: self
                                                    selector: @selector(openASite:)
                                                    userInfo: nil
                                                     repeats: YES];
    percolateTimer = timer;
    
    //Set up the random grid sites
    int gridsz = gridSide * gridSide;
    if (allSites != NULL) free(allSites);
    allSites = (int *)malloc(gridsz*sizeof(*allSites));
    for (int i = 0; i < gridsz; i++) allSites[i] = i;
    lastUsed = 0;
    
}

-(void)openASite:(NSTimer*)theTimer {
    
    int site = [self drawOneRandomSite];
    int row = site / gridSide;
    int col = site % gridSide;
    
    [percGrid openSiteAtRow:row andColumn:col];
    [theView setNeedsDisplay:YES];
    
    if ([percGrid didPercolate]) {
        [percolateTimer invalidate];
        percolateTimer = nil;
    }
}


-(int)drawOneRandomSite {
    
    int gridsz = gridSide * gridSide;
    int indx = (rand() % (gridsz - (lastUsed % gridsz))) + lastUsed;
    
    int temp = allSites[lastUsed];
    allSites[lastUsed] = allSites[indx];
    allSites[indx] = temp;
    int retindx = allSites[lastUsed];
    lastUsed++;
    
    return retindx;
}


-(BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication {
	return YES;
}

@end
