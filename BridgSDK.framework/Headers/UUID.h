//
//  UUID.h
//  Bridg SDK-test
//
//  Created by Nguyen Vinh on 1/8/16.
//  Copyright © 2016 Nguyen Vinh. All rights reserved.
//

#ifndef UUID_h
#define UUID_h

#define BRIDG_SERVICE_UUID @"0000FAEE-0000-1000-8000-00805F9B34FB"
#define BRIDG_CHARACTERISTIC_UUID @"AA1B332C-8E7F-4982-902F-E7855C60823D"
#define PAYMENT_INFO_CHARACTERISTIC_UUID @"6B99EE46-394B-4260-B996-81C6AAC2F204"
#define PAYMENT_STATUS_CHARACTERISTIC_UUID @"78EA2276-07CB-4B53-BBB6-BAFE0991D2D6"

#endif /* UUID_h */

typedef enum : NSUInteger {
    CharacteristicEnumUnknown = 0,
    CharacteristicEnumBridg,
    CharacteristicEnumPaymentInfo,
    CharacteristicEnumPaymentStatus,
} CharacteristicEnum;
