
#ifndef ARDUINO_IGNITER_H
#define ARDUINO_IGNITER_H

#include "../Device.h"
#include "../devtypes.h"

namespace Devices
{
	class Igniter : public Device
	{
	private:
		/*  pin */

	public:
		Igniter();
		~Igniter() { exit(); }
		DeviceStatus init();
		DeviceStatus exit();
		DeviceStatus start();
		DeviceStatus stop();
		DeviceStatus thread();
	};
} // namespace Devices

#endif
