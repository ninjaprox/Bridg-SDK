//
//  BridgSDKCentral.h
//  Bridg SDK-test
//
//  Created by Nguyen Vinh on 1/8/16.
//  Copyright © 2016 Nguyen Vinh. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "UUID.h"

@class BridgSDKCentral;

@protocol BridgSDKCentralDelegate <NSObject>

- (void)central:(BridgSDKCentral *)central didReceiveMessage:(NSString *)message onCharacteristic:(CharacteristicEnum)characteristicEnum;
- (void)central:(BridgSDKCentral *)central readyToCommunicate:(BOOL)ready;

#pragma mark - Debug

@optional

- (void)central:(BridgSDKCentral *)central log:(NSString *)log;

@end

@interface BridgSDKCentral : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate>

@property (copy, nonatomic) NSString *identity;
@property (copy, nonatomic) NSString *peripheralIdentity;
@property (weak, nonatomic) NSObject<BridgSDKCentralDelegate> *delegate;

- (void)enableDiscoverable;
- (void)disableDiscoverable;
- (void)sendMessage:(NSString *)message onCharacteristic:(CharacteristicEnum)characteristicEnum;

@end
