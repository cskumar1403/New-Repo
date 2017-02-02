//
//  RealTimePlot.m
//  CorePlotGallery
//

#import "RealTimePlot-temp.h"

const NSUInteger kMaxDataPoints1 = 51;
NSString *kPlotIdentifier1       = @"Data Source Plot";

@implementation RealTimePlotTemp


-(id)init
{
    if ( (self = [super init]) ) {
        plotData  = [[NSMutableArray alloc] initWithCapacity:kMaxDataPoints1];
     }

    return self;
}


-(NSMutableArray*)getData{
    return plotData;
}

-(void)killGraph
{
    [plotData removeAllObjects];
    currentIndex = 0;
    CPTPlot *thePlot   = [graph plotWithIdentifier:kPlotIdentifier1];
    if ( thePlot ) {
        [thePlot reloadData];
    }
}

-(void)startGraph
{
    [plotData removeAllObjects];
    currentIndex = 0;
    CPTPlot *thePlot   = [graph plotWithIdentifier:kPlotIdentifier1];
    if ( thePlot ) {
        [thePlot reloadData];
    }
}


-(void)renderInView:(CPTGraphHostingView *)hostingView
{
    hostingView.collapsesLayers = NO;
    currentIndex = 0;

    graph = [[CPTXYGraph alloc] initWithFrame:CGRectZero];
    hostingView.hostedGraph = graph;
    //[graph applyTheme:[CPTTheme themeNamed:kCPTPlainWhiteTheme]];

    graph.plotAreaFrame.paddingTop    = 0.0;
    graph.plotAreaFrame.paddingRight  = 0.0;
    graph.plotAreaFrame.paddingBottom = 0.0;
    graph.plotAreaFrame.paddingLeft   = 35.0;
    graph.plotAreaFrame.borderLineStyle = nil;
    
    // Grid line style
    CPTMutableLineStyle *majorGridLineStyle = [CPTMutableLineStyle lineStyle];
    majorGridLineStyle.lineWidth = 0.75;
    majorGridLineStyle.lineColor = [[CPTColor colorWithGenericGray:0.2] colorWithAlphaComponent:0.75];

    CPTMutableLineStyle *minorGridLineStyle = [CPTMutableLineStyle lineStyle];
    minorGridLineStyle.lineWidth = 0.25;
    minorGridLineStyle.lineColor = [[CPTColor whiteColor] colorWithAlphaComponent:0.1];


    // Axes
    // X axis
    CPTXYAxisSet *axisSet = (CPTXYAxisSet *)graph.axisSet;
    CPTXYAxis *x          = axisSet.xAxis;
    x.labelingPolicy              = CPTAxisLabelingPolicyAutomatic;
    x.orthogonalCoordinateDecimal = CPTDecimalFromUnsignedInteger(0);
    x.majorGridLineStyle          = majorGridLineStyle;
    x.minorGridLineStyle          = minorGridLineStyle;
    x.minorTicksPerInterval       = 4;
    NSNumberFormatter *labelFormatter = [[NSNumberFormatter alloc] init];
    labelFormatter.numberStyle = NSNumberFormatterNoStyle;
    x.labelFormatter           = labelFormatter;

    // Y axis
    CPTXYAxis *y = axisSet.yAxis;
    y.labelingPolicy              = CPTAxisLabelingPolicyAutomatic;
    y.orthogonalCoordinateDecimal = CPTDecimalFromUnsignedInteger(0);
    y.majorGridLineStyle          = majorGridLineStyle;
    y.minorGridLineStyle          = minorGridLineStyle;
    y.minorTicksPerInterval       = 1;
    y.labelOffset                 = 5.0;
    //y.title                       = @"BPM";
    y.axisConstraints             = [CPTConstraints constraintWithLowerOffset:0.0];
	labelFormatter = [[NSNumberFormatter alloc] init];
	labelFormatter.numberStyle = NSNumberFormatterDecimalStyle;
    labelFormatter.minimumFractionDigits = 0;
    labelFormatter.maximumFractionDigits = 2;
    y.labelFormatter		   = labelFormatter;

    // Create the plot
    CPTScatterPlot *dataSourceLinePlot = [[CPTScatterPlot alloc] initWithFrame: CGRectNull];
    dataSourceLinePlot.identifier     = kPlotIdentifier1;
    dataSourceLinePlot.cachePrecision = CPTPlotCachePrecisionDouble;

    CPTMutableLineStyle *lineStyle = [dataSourceLinePlot.dataLineStyle mutableCopy];
    //lineStyle.lineWidth              = 3.0;
    lineStyle.lineWidth              = 2.0;
    //lineStyle.lineColor              = [CPTColor greenColor];
    lineStyle.lineColor              = [CPTColor blackColor];
    dataSourceLinePlot.dataLineStyle = lineStyle;

    dataSourceLinePlot.dataSource = self;
    [graph addPlot:dataSourceLinePlot];

    // Plot space
    CPTXYPlotSpace *plotSpace = (CPTXYPlotSpace *)graph.defaultPlotSpace;
    plotSpace.xRange = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromUnsignedInteger(0) length:CPTDecimalFromUnsignedInteger(kMaxDataPoints1 - 1)];
    plotSpace.yRange = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromUnsignedInteger(0) length:CPTDecimalFromUnsignedInteger(100)];
    
    plotSpace.globalXRange = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromUnsignedInteger(0) length:CPTDecimalFromUnsignedInteger(100)];
    plotSpace.allowsUserInteraction = YES;

	if ( [[hostingView.layer sublayers] indexOfObject:graph] == NSNotFound ) {
		[hostingView.layer addSublayer:graph];
	}
}


#pragma mark -
#pragma mark Timer callback

-(void)newData:(NSNumber *)number atIndex:(NSNumber *)index
{
   CPTPlot *thePlot   = [graph plotWithIdentifier:kPlotIdentifier1];

    if ( thePlot ) {
        if ( plotData.count >= kMaxDataPoints1 ) {
            [plotData removeObjectAtIndex:0];
            [thePlot deleteDataInIndexRange:NSMakeRange(0, 1)];
        }

        CPTXYPlotSpace *plotSpace = (CPTXYPlotSpace *)graph.defaultPlotSpace;
        NSUInteger location       = (currentIndex >= kMaxDataPoints1 ? currentIndex - kMaxDataPoints1 + 1 : 0);
        plotSpace.xRange = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromUnsignedInteger(location)
                                                        length:CPTDecimalFromUnsignedInteger(kMaxDataPoints1 - 1)];

        currentIndex++;
        [plotData addObject:number];
        [thePlot insertDataAtIndex:plotData.count - 1 numberOfRecords:1];
    }
}

#pragma mark -
#pragma mark Plot Data Source Methods

-(NSUInteger)numberOfRecordsForPlot:(CPTPlot *)plot
{
    return [plotData count];
}

-(NSNumber *)numberForPlot:(CPTPlot *)plot field:(NSUInteger)fieldEnum recordIndex:(NSUInteger)index
{
    NSNumber *num = nil;

    switch ( fieldEnum ) {
        case CPTScatterPlotFieldX:
            num = [NSNumber numberWithUnsignedInteger:index + currentIndex - plotData.count];
            break;

        case CPTScatterPlotFieldY:
            num = [plotData objectAtIndex:index];
            break;

        default:
            break;
    }

    return num;
}

@end
