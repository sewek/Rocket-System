#include "Core.h"  

Core::Core()
{
    Serial.begin(m_default_baudrate);
    this->serialPort = &Serial;
}

Core::Core(Serial_ *serial)
{
    this->serialPort = serial;
}

Core::~Core()
{

}

bool Core::initDevices()
{
    int count = devices/sizeof(devices[0]);

    if (count < 1) {
        /*  No devices  */
        return true;
    }

    /*  Init devices    */
    for (int i = 0; i < count; i++)
    {
        /*  Set device state as Halted */
        devices[i]->State = DeviceState::Halted;

        if (devices[i]->init() != OK) {
            /*  Errors while initing device   */
            continue;
        }
        /*  Device inited correctly */
    }

    /*  Start devices   */
    for (int i = 0; i < count; i++)
    {
        /*  Check auto startup  */
        if (!devices[i]->onStartup)
            continue;

        /*  Set device state as Starting */
        devices[i]->State = DeviceState::Starting;

        if (devices[i]->start() != OK) {
            /*  Errors while initing device   */
            continue;
        }

        /*  Set device state as Running */
        devices[i]->State = DeviceState::Running;
        /*  Device inited correctly */
    }

    return true;
}

bool Core::testDevices()
{
    int count = devices/sizeof(devices[0]);

    for (int i = 0; i < count; i++)
    {
        if (testDevice(i))
        /*  Log passed  */;
        else
        /* Log error */;
    }

    return true;
}

bool Core::testDevice(unsigned int id)
{
    return (devices[id]->test() == OK);
}

bool Core::stopDevice(unsigned int id)
{
    return true;
}

void Core::runMainThread()
{
    
}