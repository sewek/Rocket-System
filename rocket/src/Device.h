
#ifndef _DEVICE_H
#define _DEVICE_H

#include "devtypes.h"

class Device  
{
	private:

	public:

		char *Name;
		char *Command;
		DeviceType Type			=	DeviceType::Unknown;
		DeviceState State		=	DeviceState::Unknown;
		bool onStartup			=	true;

		Device();
		Device(bool onstartup);
		virtual ~Device();

		virtual DeviceStatus init();
		virtual DeviceStatus exit();

		virtual DeviceStatus start();
		virtual DeviceStatus stop();

		virtual DeviceStatus thread();

		virtual DeviceStatus test();

};
#endif
