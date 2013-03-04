/*
Generic implementation of the s3eApsalar extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eApsalar_internal.h"
s3eResult s3eApsalarInit()
{
    //Add any generic initialisation code here
    return s3eApsalarInit_platform();
}

void s3eApsalarTerminate()
{
    //Add any generic termination code here
    s3eApsalarTerminate_platform();
}

void s3eApStart(const char *apiKey, const char *apiSecret)
{
	s3eApStart_platform(*apiKey, *apiSecret);
}

void s3eApRestart(const char *apiKey, const char *apiSecret)
{
	s3eApRestart_platform(*apiKey, *apiSecret);
}

bool s3eApStarted()
{
	return s3eApStarted_platform();
}

void s3eApEnd()
{
	s3eApEnd_platform();
}

void s3eApLogEvent(const char *name)
{
	s3eApLogEvent_platform(*name);
}
