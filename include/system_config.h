#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include "types.h"

#define BAUD_RATE_UART 115200

#define SYSTEM_LOG      (STD_ON)    // Logs ON/OFF
#define SERIAL_PORT     (STD_ON)    // UART
#define I2CBUS_PORT1    (STD_ON)    // I2C

#if (SERIAL_PORT == STD_ON)
#define SERIAL_BAUDRATE (BAUD_RATE_UART)
#endif


#endif /*SYSTEMCONFIG_H*/