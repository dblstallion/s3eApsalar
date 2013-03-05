#include "ExamplesMain.h"
#include "s3eOSReadString.h"
#include "s3eApsalar.h"
#include "IwDebug.h"
#include "s3eExt.h"

const char *yourApiKey = "s3eApsalar";
const char *yourApiSecret = "6TWtvU2K";

void LogEvent();

//Example Main
void ExampleInit()
{
    s3eDebugOutputString("Booting s3eApsalar example");

    if (!s3eApsalarAvailable())
    {
        s3eDebugOutputString(s3eExtGetErrorString());
        return;
    }

    s3eDebugOutputString("Successfully loaded s3eApsalar extension");

    s3eDebugOutputString("Starting Apsalar session");
    s3eApStart(yourApiKey, yourApiSecret);

    s3eDebugOutputString("Apsalar session started");

    s3eApLogEvent("TestEvent");
    s3eDebugOutputString("TestEvent logged");
}

bool ExampleUpdate()
{
    s3eDebugOutputString("Updating");
    return true;
}

void ExampleRender()
{
    s3eDebugOutputString("Rendering");
}

void ExampleShutDown()
{
}