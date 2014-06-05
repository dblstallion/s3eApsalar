/*
 * android-specific implementation of the s3eApsalar extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eApsalar_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_s3eApStart;
static jmethodID g_s3eApRestart;
static jmethodID g_s3eApStarted;
static jmethodID g_s3eApEnd;
static jmethodID g_s3eApLogEvent;
static jmethodID g_s3eApDictCreate;
static jmethodID g_s3eApDictAddString;
static jmethodID g_s3eApDictAddInt;
static jmethodID g_s3eApDictAddFloat;
static jmethodID g_s3eApDictAddDict;
static jmethodID g_s3eApLogEventWithArgs;
static jmethodID g_s3eApSetFBAppId;

s3eResult s3eApsalarInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("s3eApsalar");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eApStart = env->GetMethodID(cls, "s3eApStart", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_s3eApStart)
        goto fail;

    g_s3eApRestart = env->GetMethodID(cls, "s3eApRestart", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_s3eApRestart)
        goto fail;

    g_s3eApStarted = env->GetMethodID(cls, "s3eApStarted", "()Z");
    if (!g_s3eApStarted)
        goto fail;

    g_s3eApEnd = env->GetMethodID(cls, "s3eApEnd", "()V");
    if (!g_s3eApEnd)
        goto fail;

    g_s3eApLogEvent = env->GetMethodID(cls, "s3eApLogEvent", "(Ljava/lang/String;)V");
    if (!g_s3eApLogEvent)
        goto fail;

    g_s3eApDictCreate = env->GetMethodID(cls, "s3eApDictCreate", "()Lorg/json/JSONObject;");
    if (!g_s3eApDictCreate)
        goto fail;

    g_s3eApDictAddString = env->GetMethodID(cls, "s3eApDictAddString", "(Lorg/json/JSONObject;Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_s3eApDictAddString)
        goto fail;

    g_s3eApDictAddInt = env->GetMethodID(cls, "s3eApDictAddInt", "(Lorg/json/JSONObject;Ljava/lang/String;I)V");
    if (!g_s3eApDictAddInt)
        goto fail;

    g_s3eApDictAddFloat = env->GetMethodID(cls, "s3eApDictAddFloat", "(Lorg/json/JSONObject;Ljava/lang/String;F)V");
    if (!g_s3eApDictAddFloat)
        goto fail;

    g_s3eApDictAddDict = env->GetMethodID(cls, "s3eApDictAddDict", "(Lorg/json/JSONObject;Ljava/lang/String;Lorg/json/JSONObject;)V");
    if (!g_s3eApDictAddDict)
        goto fail;

    g_s3eApLogEventWithArgs = env->GetMethodID(cls, "s3eApLogEventWithArgs", "(Ljava/lang/String;Lorg/json/JSONObject;)V");
    if (!g_s3eApLogEventWithArgs)
        goto fail;

	g_s3eApSetFBAppId = env->GetMethodID(cls, "s3eApSetFBAppId", "(Ljava/lang/String;)V");
    if (!g_s3eApSetFBAppId)
        goto fail;


    IwTrace(APSALAR, ("APSALAR init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eApsalar, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void s3eApsalarTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eApStart_platform(const char* apiKey, const char* apiSecret)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring apiKey_jstr = env->NewStringUTF(apiKey);
    jstring apiSecret_jstr = env->NewStringUTF(apiSecret);
    
    env->CallVoidMethod(g_Obj, g_s3eApStart, apiKey_jstr, apiSecret_jstr);
    
	env->DeleteLocalRef(apiKey_jstr);
	env->DeleteLocalRef(apiSecret_jstr);
}

void s3eApRestart_platform(const char* apiKey, const char* apiSecret)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring apiKey_jstr = env->NewStringUTF(apiKey);
    jstring apiSecret_jstr = env->NewStringUTF(apiSecret);
    
    env->CallVoidMethod(g_Obj, g_s3eApRestart, apiKey_jstr, apiSecret_jstr);
    
	env->DeleteLocalRef(apiKey_jstr);
	env->DeleteLocalRef(apiSecret_jstr);
}

bool s3eApStarted_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_s3eApStarted);
}

void s3eApEnd_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eApEnd);
}

void s3eApLogEvent_platform(const char* name)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring name_jstr = env->NewStringUTF(name);
    
    env->CallVoidMethod(g_Obj, g_s3eApLogEvent, name_jstr);
    
	env->DeleteLocalRef(name_jstr);
}

s3eApDict* s3eApDictCreate_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
	jobject dict = env->CallObjectMethod(g_Obj, g_s3eApDictCreate);
    
    jobject globalRef = env->NewGlobalRef(dict);
    
    env->DeleteLocalRef(dict);
	return (s3eApDict*)globalRef;
}

void s3eApDictAddString_platform(s3eApDict* dict, const char* key, const char* value)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring key_jstr = env->NewStringUTF(key);
    jstring value_jstr = env->NewStringUTF(value);
    
    env->CallVoidMethod(g_Obj, g_s3eApDictAddString, (jobject)dict, key_jstr, value_jstr);
    
	env->DeleteLocalRef(key_jstr);
	env->DeleteLocalRef(value_jstr);
}

void s3eApDictAddInt_platform(s3eApDict* dict, const char* key, int value)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring key_jstr = env->NewStringUTF(key);
    
    env->CallVoidMethod(g_Obj, g_s3eApDictAddInt, (jobject)dict, key_jstr, value);
    
	env->DeleteLocalRef(key_jstr);
}

void s3eApDictAddFloat_platform(s3eApDict* dict, const char* key, float value)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring key_jstr = env->NewStringUTF(key);
    
    env->CallVoidMethod(g_Obj, g_s3eApDictAddFloat, (jobject)dict, key_jstr, value);
    
	env->DeleteLocalRef(key_jstr);
}

void s3eApDictAddDict_platform(s3eApDict* dict, const char* key, s3eApDict* value)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring key_jstr = env->NewStringUTF(key);
    jobject value_jobj = (jobject)value;
    
    env->CallVoidMethod(g_Obj, g_s3eApDictAddDict, (jobject)dict, key_jstr, value_jobj);
    
	env->DeleteLocalRef(key_jstr);
	env->DeleteGlobalRef(value_jobj);
}

void s3eApLogEventWithArgs_platform(const char* name, s3eApDict* dict)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring name_jstr = env->NewStringUTF(name);
	jobject dict_jobj = (jobject)dict;
    
    env->CallVoidMethod(g_Obj, g_s3eApLogEventWithArgs, name_jstr, dict_jobj);
    
	env->DeleteLocalRef(name_jstr);
	env->DeleteGlobalRef(dict_jobj);
}

void s3eApSetFBAppId_platform(const char* appId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring appId_jstr = env->NewStringUTF(appId);
    
    env->CallVoidMethod(g_Obj, g_s3eApSetFBAppId, appId_jstr);\
	env->DeleteLocalRef(appId_jstr);
}
