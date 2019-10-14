//
//  ZBQueue.h
//  Zebra
//
//  Created by Wilson Styres on 1/29/19.
//  Copyright © 2019 Wilson Styres. All rights reserved.
//

@class ZBPackage;
@class ZBQueuedPackage;

#import <Foundation/Foundation.h>
#import <Queue/ZBQueueType.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZBQueue : NSObject
@property (nonatomic, strong) NSMutableArray<NSString *> *queuedPackagesList;
+ (id)sharedQueue;
+ (int)count;
- (void)addPackage:(ZBPackage *)package toQueue:(ZBQueueType)queue;
- (void)addPackages:(NSArray <ZBPackage *> *)packages toQueue:(ZBQueueType)queue;
- (void)addDependency:(ZBPackage *)package;
- (void)removePackage:(ZBPackage *)package;
- (void)removePackage:(ZBPackage *)package inQueue:(ZBQueueType)queue;
- (NSArray *)tasksToPerform:(NSArray <NSDictionary <NSString*, NSString *> *> *)debs;
- (NSMutableArray *)queueFromType:(ZBQueueType)queue;
- (ZBQueueType)queueTypeFromKey:(NSString *)key;
- (NSString *)keyFromQueueType:(ZBQueueType)queue;
- (NSArray *)actionsToPerform;
- (NSString *)displayableNameForQueueType:(ZBQueueType)queue useIcon:(BOOL)useIcon;
- (int)numberOfPackagesInQueueKey:(NSString *)queue;
- (int)numberOfPackagesInQueue:(ZBQueueType)queue;
- (BOOL)needsToDownloadPackages;
- (NSArray *)packagesToDownload;
- (BOOL)containsPackage:(ZBPackage *)package inQueue:(ZBQueueType)queue;
- (NSArray <NSArray <ZBPackage *> *> *)topDownQueue;
- (BOOL)hasIssues;
- (void)clear;
- (NSMutableArray *)dependencyQueue; // delete this later
@end

NS_ASSUME_NONNULL_END
