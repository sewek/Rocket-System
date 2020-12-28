
#ifndef _IMPORTER_H
#define _IMPORTER_H

#include "macros.h"
#include "devices/devices.h"

#ifndef BOARD
	#error Board type has not been defined!
#elif EQUAL(BOARD, ARDUINO_NANO)
	#include "boards/arduino_nano.h"
#endif

#endif
