
#ifndef _DEVTYPES_H
#define _DEVTYPES_H

typedef enum m_device_type {
    Unknown                     =   -1,
    Basic                       =   0,
        IO                      =   1,
        Igniter                 =   2,
        Parachute               =   3,
        /* Other basic devices... */
        Other                   =   9,

    Communicator                =   20,
        /* Just communicator */

    Sensor                      =   30,
        Accelerometer           =   31,
        Gyroscore               =   32,
        Magnetometer            =   33,
        IMU                     =   34,
        Barometer               =   35,
        Thermometer             =   36,
        Vibration               =   37,
        Light                   =   38,
        Air                     =   39,
        GPS                     =   40
} DeviceType;

typedef enum m_device_state {
    Unknown                     =   -1,
    Halted                      =   0,
    Starting                    =   1,
    Running                     =   2,
    Stopping                    =   3,
    Stopped                     =   4
} DeviceState;

typedef enum m_device_status {
    Unknown                     =   -1,
    OK                          =   0,
    Error                       =   1
} DeviceStatus;

#endif