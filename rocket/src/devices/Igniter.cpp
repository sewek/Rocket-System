#include "Igniter.h"


DeviceStatus Devices::Igniter::init()
{
    /*  Register device as Igniter */
    Type = DeviceType::Igniter;

    /*  Set device state as Halted */
    State = DeviceState::Halted;

    /*  Set device name */
    Name = "Igniter";

    /*  Set command */
    Command = "igniter";

    /*  Reserv pin 
                Set pin to output
                Set to LOW */

    return OK;
}

DeviceStatus Devices::Igniter::exit()
{
    /*  Release pin */

    /*  Set device state as Halted */
    State = DeviceState::Halted;

    return OK;
}

DeviceStatus Devices::Igniter::start()
{
    /*  Set device state as Starting */
    State = DeviceState::Starting;

    /*  Register pin interruption */

    /*  Set device state as Running */
    State = DeviceState::Running;

    return OK;
}

DeviceStatus Devices::Igniter::stop()
{
    /*  Set device state as Stopping */
    State = DeviceState::Stopping;

    /*  UnRegister pin interruption */

    /*  Set device state as Stopped */
    State = DeviceState::Stopped;

    return OK;
}

DeviceStatus Devices::Igniter::thread()
{
    if (State != DeviceState::Running)
    {
        /*  Send panic! */
        return Error;
    }

    /*  Main loop   */

    return OK;
}