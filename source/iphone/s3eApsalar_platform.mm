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
	[Apsalar startSession:[NSString initWithUTF8String:apiKey] withKey:[NSString initWithUTF8String:apiSecret]];
}

void s3eApRestart_platform(const char *apiKey, const char *apiSecret)
{
	[Apsalar reStartSession:[NSString initWithUTF8String:apiKey] withKey:[NSString initWithUTF8String:apiSecret]];
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
	[Apsalar event:[NSString initWithUTF8String:name]];
}
