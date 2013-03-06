/*
 * iphone-specific implementation of the s3eApsalar extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eApsalar_internal.h"

#import "Apsalar.h"

struct s3eApDict {}; // Empty struct used as a marker for a dictionary

s3eResult s3eApsalarInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eApsalarTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eApStart_platform(const char *apiKey, const char *apiSecret)
{
	[Apsalar startSession:[NSString stringWithUTF8String:apiKey] withKey:[NSString stringWithUTF8String:apiSecret]];
}

void s3eApRestart_platform(const char *apiKey, const char *apiSecret)
{
	[Apsalar reStartSession:[NSString stringWithUTF8String:apiKey] withKey:[NSString stringWithUTF8String:apiSecret]];
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
	[Apsalar event:[NSString stringWithUTF8String:name]];
}

s3eApDict* s3eApDictCreate_platform()
{
	return (s3eApDict*)[NSMutableDictionary dictionary];
}

void s3eApDictAddString_platform(s3eApDict* dict, const char* key, const char* value)
{
	NSMutableDictionary *d = (NSMutableDictionary *)dict;
	[d setObject:[NSString stringWithUTF8String:value] forKey:[NSString stringWithUTF8String:key]];
}

void s3eApDictAddInt_platform(s3eApDict* dict, const char* key, int value)
{
	NSMutableDictionary *d = (NSMutableDictionary *)dict;
	[d setObject:[NSNumber numberWithInt:value] forKey:[NSString stringWithUTF8String:key]];
}

void s3eApDictAddFloat_platform(s3eApDict* dict, const char* key, float value)
{
	NSMutableDictionary *d = (NSMutableDictionary *)dict;
	[d setObject:[NSNumber numberWithFloat:value] forKey:[NSString stringWithUTF8String:key]];
}

void s3eApDictAddDict_platform(s3eApDict* dict, const char* key, s3eApDict* value)
{
	NSMutableDictionary *d = (NSMutableDictionary *)dict;
	NSMutableDictionary *v = (NSMutableDictionary *)value;
	[d setObject:v forKey:[NSString stringWithUTF8String:key]];
}

void s3eApLogEventWithArgs_platform(const char *name, s3eApDict* dict)
{
	NSMutableDictionary *args = (NSMutableDictionary *)dict;
	[Apsalar event:[NSString stringWithUTF8String:name] withArgs:args];
}