//
//  PRCAppDelegate.h
//  PercolationGUI
//
//  Created by Martin Beroiz on 3/10/14.
//  Copyright (c) 2014 CGWA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PRCGrid.h"
#import "PRCGridView.h"

@interface PRCAppDelegate : NSObject <NSApplicationDelegate> {
    PRCGrid *percGrid;
    IBOutlet PRCGridView* theView;
    unsigned char** grid;
    int gridSide;
    int *allSites;
    int lastUsed;
    //NSTimer* percolateTimer; // I probably won't need this reference!
}

@property (assign) IBOutlet NSWindow *window;
@property (weak) NSTimer* percolateTimer;

-(IBAction)initPercolation:(id)sender;
-(void)openASite:(NSTimer*)theTimer;

@end
