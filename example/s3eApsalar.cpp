#include "s3eOSReadString.h"
#include "s3eApsalar.h"
#include "IwDebug.h"
#include "IwGx.h"
#include "s3eExt.h"
#include "s3ePointer.h"

const char *yourApiKey = "s3eApsalar";
const char *yourApiSecret = "6TWtvU2K";

void initApsalar()
{
    if (!s3eApsalarAvailable())
    {
        s3eDebugOutputString(s3eExtGetErrorString());
        return;
    }

    s3eDebugOutputString("Successfully loaded s3eApsalar extension");

    s3eApStart(yourApiKey, yourApiSecret);
    s3eDebugOutputString("Apsalar session started");
}

void logEvent()
{
    s3eApLogEvent("TestEvent");
    s3eDebugOutputString("TestEvent logged");
}

void shutdownApsalar()
{
    s3eApEnd();
    s3eDebugOutputString("Apsalar Shutdown");
}

void touchEvent(s3ePointerTouchEvent *event)
{
    if(event->m_Pressed)
    {
        logEvent();
    }
}

// Example showing how to use the s3eApsalar extension
int main()
{
    s3eDebugOutputString("Booting s3eApsalar example");

    s3ePointerRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)touchEvent, NULL);

    IwGxInit();

    IwGxSetColClear(0, 0, 0, 0xff);

    initApsalar();

    while(!s3eDeviceCheckQuitRequest())
    {
        IwGxClear();

        IwGxPrintString(100, 100, "s3eApsalar");

        IwGxPrintString(100, 300, "Touch to fire event");

        IwGxFlush();
        IwGxSwapBuffers();
        s3eDeviceYield(0);
    }

    shutdownApsalar();

    IwGxTerminate();

    return 0;
}