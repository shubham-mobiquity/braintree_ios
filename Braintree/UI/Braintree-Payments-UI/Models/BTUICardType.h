#import <Foundation/Foundation.h>

#define BTUICardBrandAMEX NSLocalizedStringWithDefaultValue(@"CARD_TYPE_AMERICAN_EXPRESS", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"American Express", @"American Express card brand")
#define BTUICardBrandDinersClub NSLocalizedStringWithDefaultValue(@"CARD_TYPE_DINERS_CLUB", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"Diners Club", @"Diners Club card brand")
#define BTUICardBrandDiscover NSLocalizedStringWithDefaultValue(@"CARD_TYPE_DISCOVER", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"Discover", @"Discover card brand")
#define BTUICardBrandMasterCard NSLocalizedStringWithDefaultValue(@"CARD_TYPE_MASTER_CARD", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"MasterCard", @"MasterCard card brand")
#define BTUICardBrandVisa NSLocalizedStringWithDefaultValue(@"CARD_TYPE_VISA", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"Visa", @"Visa card brand")
#define BTUICardBrandJCB NSLocalizedStringWithDefaultValue(@"CARD_TYPE_JCB", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"JCB", @"JCB card brand")
#define BTUICardBrandMaestro NSLocalizedStringWithDefaultValue(@"CARD_TYPE_MAESTRO", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"Maestro", @"Maestro card brand")
#define BTUICardBrandUnionPay NSLocalizedStringWithDefaultValue(@"CARD_TYPE_UNION_PAY", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"UnionPay", @"UnionPay card brand")
#define BTUICardBrandLaser NSLocalizedStringWithDefaultValue(@"CARD_TYPE_LASER", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"Laser", @"Laser card brand")
#define BTUICardBrandSolo NSLocalizedStringWithDefaultValue(@"CARD_TYPE_SOLO", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"Solo", @"Solo card brand")
#define BTUICardBrandSwitch NSLocalizedStringWithDefaultValue(@"CARD_TYPE_SWITCH", @"UI", [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"Braintree-UI-Localization" ofType:@"bundle"]], @"Switch", @"Switch card brand")

/// Immutable card type
@interface BTUICardType : NSObject

/// Obtain the `BTCardType` for the given brand, or nil if none is found
+ (instancetype)cardTypeForBrand:(NSString *)brand;

/// Obtain the `BTCardType` for the given number, or nil if none is found
+ (instancetype)cardTypeForNumber:(NSString *)number;

/// Return all possible card types for a number
+ (NSArray *)possibleCardTypesForNumber:(NSString *)number;

/// Check if a number is valid
- (BOOL)validNumber:(NSString *)number;

/// Check if a number is complete
- (BOOL)completeNumber:(NSString *)number;

/// Check if the CVV is valid for a `BTCardType`
- (BOOL)validCvv:(NSString *)cvv;

/// Format a number based on type
/// Does NOT validate
- (NSAttributedString *)formatNumber:(NSString *)input;
- (NSAttributedString *)formatNumber:(NSString *)input kerning:(CGFloat)kerning;

+ (NSUInteger)maxNumberLength;

@property (nonatomic, copy, readonly) NSString *brand;
@property (nonatomic, strong, readonly) NSArray *validNumberPrefixes;
@property (nonatomic, strong, readonly) NSIndexSet  *validNumberLengths;
@property (nonatomic, assign, readonly) NSUInteger validCvvLength;

@property (nonatomic, strong, readonly) NSArray  *formatSpaces;
@property (nonatomic, assign, readonly) NSUInteger maxNumberLength;

@end
