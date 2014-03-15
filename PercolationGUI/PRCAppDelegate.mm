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
    
    isAnimating = NO;
    animationSpeed = 10;
    
    //Set self for the view controller
    [theView setViewController:self forSelector:@selector(isFloodedForRow:andColumn:)];
    
    shouldRestart = YES;
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
    shouldRestart = YES;
    
    [startButton setTitle:@"Start Percolation"];

    
}

-(void)setAnimationSpeed:(double)newSpeed {
    if (animationSpeed == newSpeed) return;
    animationSpeed = newSpeed;
    if (isAnimating) {
        [percolateTimer invalidate];
        percolateTimer = [NSTimer scheduledTimerWithTimeInterval: 1./animationSpeed
                                                          target: self
                                                        selector: @selector(openASite:)
                                                        userInfo: nil
                                                         repeats: YES];
    }
}

-(void)initPercolation:(id)sender {
    
    if (isAnimating) {
        
        [startButton setTitle:@"Resume Percolation"];
        [percolateTimer invalidate];
        isAnimating = NO;
        shouldRestart = NO;
        
    } else {
        
        [startButton setTitle:@"Pause Percolation"];
        if (shouldRestart) {
            percGrid = [[PRCGrid alloc] init];
            [percGrid setGridSide:gridSide];
            grid = [percGrid grid];
            [theView setGrid:grid];
            [theView setNeedsDisplay:YES];
            //Set up the random grid sites
            int gridsz = gridSide * gridSide;
            if (allSites != NULL) free(allSites);
            allSites = (int *)malloc(gridsz*sizeof(*allSites));
            for (int i = 0; i < gridsz; i++) allSites[i] = i;
            lastUsed = 0;
            shouldRestart = NO;
        }
        
        //Initiate the animation:
        isAnimating = YES;
        [percolateTimer invalidate];
        percolateTimer = [NSTimer scheduledTimerWithTimeInterval: 1./animationSpeed
                                                          target: self
                                                        selector: @selector(openASite:)
                                                        userInfo: nil
                                                         repeats: YES];
    }
    
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
        isAnimating = NO;
        [startButton setTitle:@"Restart Percolation"];
        shouldRestart = YES;
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

-(BOOL)isFloodedForRow:(NSNumber*)row andColumn:(NSNumber*)col {
    return [percGrid isConnectedWithTopForRow:[row intValue] andColumn:[col intValue]];
}

-(BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication {
	return YES;
}

@end
