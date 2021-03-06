//
//  RTKReceiptParser.h
//  ReceiptKit
//
//  Created by Richard Stelling on 26/09/2013.
//  Copyright (c) 2013 Empirical Magic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RTKPurchaseInformation, RTKReceiptParser;

typedef void(^RTKParserCompletionBlock)(RTKReceiptParser *parser, NSError *error);

@interface RTKReceiptParser : NSObject

@property (readonly, nonatomic) RTKPurchaseInformation *purchaseInfo;

- (instancetype)initWithReceipt:(NSData *)receiptData certificate:(NSData *)certificateData __attribute__((availability(ios,deprecated=1.0,message="Use -initWithReceiptData:certificateData: instead")));
- (instancetype)initWithReceiptData:(NSData *)receiptData certificateData:(NSData *)certificateData;
- (instancetype)initWithReceiptURL:(NSURL *)receiptFile certificateURL:(NSURL *)certificateFile; //Uses -dataWithContentsOfURL: and calls -initWithReceiptData:certificateData:
- (instancetype)initWithCertificateURL:(NSURL *)certificateFile; //Uses -appStoreReceiptURL can calls -initWithReceiptURL:certificateURL:

//Block based asynchronous calls
+ (void)receiptParserWithCertificateURL:(NSURL *)certificateFile completion:(RTKParserCompletionBlock)completionBlock;

/// Do not read the values of `bundleIdentifier` or `bundleVersion` directly
/// from the Info.plist, as it is too eay to alter. Instead, hard code the
/// bundle identifier and version, preferably in an obfuscated way.
- (BOOL)isReceiptValidForCurrentDevice:(NSString *)bundleIdentifier;

///This is used to verify a receipt form an external app
- (BOOL)isReceiptValidForVendorIdentifier:(NSData *)vendorID bundleIdentifier:(NSString *)bundleIdentifier;

@end
