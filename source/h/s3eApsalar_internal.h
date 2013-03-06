/*
 * Internal header for the s3eApsalar extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3EAPSALAR_INTERNAL_H
#define S3EAPSALAR_INTERNAL_H

#include "s3eTypes.h"
#include "s3eApsalar.h"
#include "s3eApsalar_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eApsalarInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eApsalarInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eApsalarTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eApsalarTerminate_platform();
void s3eApStart_platform(const char* apiKey, const char* apiSecret);

void s3eApRestart_platform(const char* apiKey, const char* apiSecret);

bool s3eApStarted_platform();

void s3eApEnd_platform();

void s3eApLogEvent_platform(const char* name);

s3eApDict* s3eApDictCreate_platform();

void s3eApDictAddString_platform(s3eApDict* dict, const char* key, const char* value);

void s3eApDictAddInt_platform(s3eApDict* dict, const char* key, int value);

void s3eApDictAddFloat_platform(s3eApDict* dict, const char* key, float value);

void s3eApDictAddDict_platform(s3eApDict* dict, const char* key, s3eApDict* value);

void s3eApLogEventWithArgs_platform(const char* name, s3eApDict* dict);


#endif /* !S3EAPSALAR_INTERNAL_H */