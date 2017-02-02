//
//  RealTimePlot.h
//  CorePlotGallery
//

#import "CorePlot-CocoaTouch.h"

@interface RealTimePlot : NSObject<CPTPlotDataSource>
{
    @private
    NSMutableArray *plotData;
    NSUInteger currentIndex;
    CPTGraph *graph;
}

-(void)newData:(NSNumber *)number atIndex:(NSNumber *)index;
-(void)renderInView:(CPTGraphHostingView *)hostingView;
-(void)killGraph;
-(void)startGraph;
-(NSMutableArray*)getData;
@end
