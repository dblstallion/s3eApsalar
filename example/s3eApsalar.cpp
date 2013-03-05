#include "ExamplesMain.h"
#include "s3eOSReadString.h"
#include "s3eApsalar.h"
#include "IwDebug.h"
#include "s3eExt.h"

const char *yourApiKey = "<fill this in>";
const char *yourApiSecret = "<fill this in>";

void LogEvent();

//Example Main
void ExampleInit()
{
    AddButton("Log Event", 200, 200, 200, 200, s3eKeyL, LogEvent);

    if (!s3eApsalarAvailable())
    {
        DisplayMessage(s3eExtGetErrorString());
        return;
    }

    s3eApStart(yourApiKey, yourApiSecret);
}

void LogEvent()
{
    s3eApLogEvent("TestEvent");
    DisplayMessage("TestEvent Logged");
}

bool ExampleUpdate()
{
    return true;
}

void ExampleRender()
{
}

void ExampleShutDown()
{
}