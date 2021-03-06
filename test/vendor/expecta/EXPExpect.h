#import <Foundation/Foundation.h>

typedef id (^EXPIdBlock)();
typedef BOOL (^EXPBoolBlock)();
typedef NSString *(^EXPStringBlock)();

@interface EXPExpect : NSObject

@property(nonatomic, copy) EXPIdBlock actualBlock;
@property(nonatomic, readonly) id actual;
@property(nonatomic, weak) id testCase;
@property(nonatomic) int lineNumber;
@property(nonatomic) char *fileName;
@property(nonatomic) BOOL negative;
@property(nonatomic) BOOL asynchronous;

@property(nonatomic, readonly) EXPExpect *Not;
@property(nonatomic, readonly) EXPExpect *isGoing;
@property(nonatomic, readonly) EXPExpect *isNotGoing;

@property(nonatomic, copy) EXPBoolBlock prerequisiteBlock;
@property(nonatomic, copy) EXPBoolBlock matchBlock;
@property(nonatomic, copy) EXPStringBlock failureMessageForToBlock;
@property(nonatomic, copy) EXPStringBlock failureMessageForNotToBlock;

- (id)initWithActualBlock:(id)actualBlock testCase:(id)testCase lineNumber:(int)lineNumber fileName:(char *)fileName;
+ (EXPExpect *)expectWithActualBlock:(id)actualBlock testCase:(id)testCase lineNumber:(int)lineNumber fileName:(char *)fileName;

- (void)applyMatcher:(NSObject **)actual;

@end
