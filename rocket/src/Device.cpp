#include "Device.h"  

Device::Device()
{

}

Device::Device(bool onstartup)
{
    onStartup = onstartup;
}

Device::~Device()
{

}

DeviceStatus Device::thread()
{
    return OK;
}

DeviceStatus Device::test()
{
    return OK;
}