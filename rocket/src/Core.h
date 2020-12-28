#ifndef _CORE_H
#define _CORE_H

#include <Arduino.h>

#include "macros.h"
#include "importer.h"

class Core  
{
	private:

		Serial_ *serialPort;

		int m_default_baudrate = 115200;

	public:

		Core();
		Core(Serial_ *serial);
		~Core();

		bool initDevices();
		bool testDevices();
		bool testDevice(unsigned int id);
		bool stopDevice(unsigned int id);
		void runMainThread();

};
#endif
