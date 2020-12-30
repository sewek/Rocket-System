#include <Arduino.h>
#include "Core.h"

using namespace System;

int main(void)
{
    Core app;

    app.devicesLoad();
    app.devicesStartUp();
    app.devicesTest();

    while(1);

    app.devicesStop();
    app.devicesUnload();

    return 0;
}