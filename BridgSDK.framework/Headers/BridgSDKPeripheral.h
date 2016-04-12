//
//  BridgSDKPeripheral.h
//  Bridg SDK-test
//
//  Created by Nguyen Vinh on 1/8/16.
//  Copyright © 2016 Nguyen Vinh. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import "UUID.h"

@class BridgSDKPeripheral;

@interface Device : NSObject

@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *identity;
@property (strong, nonatomic) NSDate *lastSeen;

- (instancetype)initWithName:(NSString *)name identity:(NSString *)identity;

@end

@protocol BridgSDKPeripheralDelegate <NSObject>

- (void)peripheral:(BridgSDKPeripheral *)peripheral didUpdateDevices:(NSArray<Device *> *)devices;
- (void)peripheral:(BridgSDKPeripheral *)peripheral didReceiveMessage:(NSString *)message onCharacteristic:(CharacteristicEnum)characteristicEnum;
- (void)peripheral:(BridgSDKPeripheral *)peripheral readyToCommunicate:(BOOL)ready;

#pragma mark - Debug

@optional

- (void)peripheral:(BridgSDKPeripheral *)peripheral log:(NSString *)log;

@end

@interface BridgSDKPeripheral : NSObject <CBPeripheralManagerDelegate>

@property (copy, nonatomic) NSString *identity;
@property (weak, nonatomic) NSObject<BridgSDKPeripheralDelegate> *delegate;

- (void)startDiscovering;
- (void)stopDiscovering;
- (void)connectDeviceWithIdentity:(NSString *)identity;
- (void)sendMessage:(NSString *)message onCharacteristic:(CharacteristicEnum)characteristicEnum;
- (void)preparePaymentInfoMessage:(NSString *)message;

@end
