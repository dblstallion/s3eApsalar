/*
 * iphone-specific implementation of the s3eApsalar extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eApsalar_internal.h"
#include "IwDebug.h"

#import "Apsalar.h"

s3eResult s3eApsalarInit_platform()
{
    [Apsalar setBatchesEvents:YES];
    [Apsalar setBatchInterval:10];
    
    IwTrace(APSALAR_VERBOSE, ("Apsalar ID: %s", [[Apsalar apsalarID] UTF8String]));
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eApsalarTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eApStart_platform(const char *apiKey, const char *apiSecret)
{
    NSString *nsAPIKey = [[NSString alloc] initWithUTF8String:apiKey];
    NSString *nsAPISecret = [[NSString alloc] initWithUTF8String:apiSecret];
	[Apsalar startSession:nsAPIKey withKey:nsAPISecret];
    [nsAPISecret release];
    [nsAPIKey release];
}

void s3eApRestart_platform(const char *apiKey, const char *apiSecret)
{
    NSString *nsAPIKey = [[NSString alloc] initWithUTF8String:apiKey];
    NSString *nsAPISecret = [[NSString alloc] initWithUTF8String:apiSecret];
	[Apsalar reStartSession:nsAPIKey withKey:nsAPISecret];
    [nsAPISecret release];
    [nsAPIKey release];
}

bool s3eApStarted_platform()
{
    return [Apsalar sessionStarted];
}

void s3eApEnd_platform()
{
	[Apsalar endSession];
}

void s3eApLogEvent_platform(const char *name)
{
    NSString *nsName = [[NSString alloc] initWithUTF8String:name];
	[Apsalar event:nsName];
    [nsName release];
}

s3eApDict* s3eApDictCreate_platform()
{
	return (s3eApDict*)[[NSMutableDictionary alloc] init];
}

void s3eApDictAddString_platform(s3eApDict* dict, const char* key, const char* value)
{
	NSMutableDictionary *d = (NSMutableDictionary *)dict;
    NSString *nsKey = [[NSString alloc] initWithUTF8String:key];
    NSString *nsValue = [[NSString alloc] initWithUTF8String:value];
	[d setObject:nsValue forKey:nsKey];
    [nsValue release];
    [nsKey release];
}

void s3eApDictAddInt_platform(s3eApDict* dict, const char* key, int value)
{
	NSMutableDictionary *d = (NSMutableDictionary *)dict;
    NSString *nsKey = [[NSString alloc] initWithUTF8String:key];
    NSNumber *nsValue = [[NSNumber alloc] initWithInt:value];
	[d setObject:nsValue forKey:nsKey];
    [nsValue release];
    [nsKey release];
}

void s3eApDictAddFloat_platform(s3eApDict* dict, const char* key, float value)
{
	NSMutableDictionary *d = (NSMutableDictionary *)dict;
    NSString *nsKey = [[NSString alloc] initWithUTF8String:key];
    NSNumber *nsValue = [[NSNumber alloc] initWithFloat:value];
	[d setObject:nsValue forKey:nsKey];
    [nsValue release];
    [nsKey release];
}

void s3eApDictAddDict_platform(s3eApDict* dict, const char* key, s3eApDict* value)
{
	NSMutableDictionary *d = (NSMutableDictionary *)dict;
	NSMutableDictionary *v = (NSMutableDictionary *)value;
    NSString *nsKey = [[NSString alloc] initWithUTF8String:key];
	[d setObject:v forKey:nsKey];
    [nsKey release];
    [v release];
}

void s3eApLogEventWithArgs_platform(const char *name, s3eApDict* dict)
{
	NSMutableDictionary *args = (NSMutableDictionary *)dict;
    NSString *nsName = [[NSString alloc] initWithUTF8String:name];
	[Apsalar event:nsName withArgs:args];
    [nsName release];
    [args release];
}