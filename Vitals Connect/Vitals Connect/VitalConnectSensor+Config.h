/**
 @file
 VitalConnectSensor+Config.h
 
 Copyright 2014 Vital Connect Inc. All rights reserved.
 
 This Software is the copyrighted work of Vital Connect, Inc. Use of the Software is governed by the terms of the end user license agreement,  which accompanies or is included with the Software ("License Agreement"). An end user will be unable to install or use any Software that is accompanied by or includes the License Agreement, unless he or she first agrees to the License Agreement terms.
 
 The Software is made available solely for use by end users according to the License Agreement. Any reproduction or redistribution of the Software not in accordance with the License Agreement is expressly prohibited by law.
 
 WITHOUT LIMITING THE FOREGOING, COPYING OR REPRODUCTION OF THE SOFTWARE OR REDISTRIBUTION IS EXPRESSLY PROHIBITED, UNLESS SUCH REPRODUCTION OR REDISTRIBUTION IS EXPRESSLY PERMITTED BY THE LICENSE AGREEMENT ACCOMPANYING SUCH SOFTWARE.
 
 THE SOFTWARE IS WARRANTED, IF AT ALL, ONLY ACCORDING TO THE TERMS OF THE LICENSE AGREEMENT. EXCEPT AS WARRANTED IN THE LICENSE AGREEMENT, VITAL CONNECT, INC HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS WITH REGARD TO THE SOFTWARE, INCLUDING ALL WARRANTIES AND CONDITIONS OF MERCHANTABILITY, WHETHER EXPRESS, IMPLIED OR STATUTORY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT.
 
 */

#import "VitalConnect.h"

/**
 * An interface that allows configuration operations to be performed directly on a Vital Connect sensor device
 */
@interface VitalConnectSensor (Config)

/** 
 * The state of the easy fall option - TRUE means easy fall is enabled, FALSE means easy fall is disabled
 */
@property BOOL easyFall;

/**
 * The state of the simulate data option - TRUE means simulate data is enabled, FALSE means simulate data is disabled
 */
@property BOOL simulateData;

/**
 * The state of the invert ECG option - TRUE means invert ECG is enabled, FALSE means invert ECG is disabled
 */
@property BOOL invertECG;

/**
 * The state of the high Quality ECG option - TRUE means high-quality ECG is enabled, FALSE means high-quality ECG is disabled
 */
@property BOOL highQualityECG;

/**
 * The state of the ECG enabled option - TRUE means ECG is enabled, FALSE means ECG is disabled
 */
@property BOOL ecgEnabled;

/**
 * The state of the accelerometer data option - TRUE means accelerometer data is enabled, FALSE means accelerometer data is disabled
 */
@property BOOL memsEnabled;

/**
 * The state of the stored data enable option - TRUE means stored data is enabled, FALSE means stored data is disabled
 */
@property BOOL storedDataStreaming;


/**
 * Tells whether the easy fall state is synchronized with the sensor - TRUE means the option is synchronized with the sensor, FALSE means the option is
 * not synchronized or in the process of being synchronized with the sensor
 */
@property (readonly) BOOL isEasyFallStateSynced;

/**
 * Tells whether the simulated data state is synchronized with the sensor - TRUE means the option is synchronized with the sensor, FALSE means the option is
 * not synchronized or in the process of being synchronized with the sensor
 */
@property (readonly) BOOL isSimulateDataStateSynced;


/**
 * Tells whether the all control options are synchronized with the sensor - TRUE means the options are synchronized with the sensor, FALSE means the options are
 * not synchronized or in the process of being synchronized with the sensor
 */
@property (readonly) BOOL allControlStatesSynced;

/**
 * Tells whether the invert ECG state is synchronized with the sensor - TRUE means the option is synchronized with the sensor, FALSE means the option is
 * not synchronized or in the process of being synchronized with the sensor
 */
@property (readonly) BOOL isInvertECGStateSynced;

/**
 * Tells whether the high-quality ECG state is synchronized with the sensor - TRUE means the option is synchronized with the sensor, FALSE means the option is
 * not synchronized or in the process of being synchronized with the sensor
 */
@property (readonly) BOOL isHighQualityECGStateSynced;

/**
 * Tells whether the stored data state is synchronized with the sensor - TRUE means the option is synchronized with the sensor, FALSE means the option is
 * not synchronized or in the process of being synchronized with the sensor
 */
@property (readonly) BOOL isStoredDataStreamingStateSynced;


/**
 * reserved for Vital Connect use
 */
@property (assign) int calibrationAngleTheta;

/**
 * reserved for Vital Connect use
 */
@property (assign) int calibrationAnglePhi;

/**
 * reserved for Vital Connect use
 */
@property (assign) int calibrationX;

/**
 * reserved for Vital Connect use
 */
@property (assign) int calibrationY;

/**
 * reserved for Vital Connect use
 */
@property (assign) int calibrationZ;


/**
 * Send a configuration file down to the sensor.  This method is reserved for Vital Connect use only.
 * @param filename The configuration file to send to the sensor.
 * @return YES if configuration written successfully, NO if not.
 */
-(BOOL) pushConfigFile:(NSString*)filename;

/**
 * Send a configuration dictionary down to the sensor.  This method is reserved for Vital Connect use only.
 * @param config The configuration object to send to the sensor.
 * @return YES if configuration written successfully, NO if not.
 */

-(BOOL) pushConfig:(id)config;

/**
 * Reset the posture calibration on the sensor device
 */
-(void) syncCalibrationState;

/**
 * Reset the pedometer (step count) on the device
 */
-(void) resetPedometer;

/**
 * Reset the energy expenditure on the device
 */
-(void) resetEnergyExpenditure;

/** 
 * Reset the total activity count on the device
 */
-(void) resetTotalActivity;

/**
 * Reset sensor memory.
 */
-(void) resetSensorMemory;

/**
 * Reset the sensor's event memory
 */
-(void) resetEventMemory;

@end
