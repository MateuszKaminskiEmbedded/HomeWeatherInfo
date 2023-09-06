#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include "types.h"

#define SYSTEM_LOG      (STD_ON)
#define SERIAL          (STD_ON)

#define SERIAL_PORT      (STD_ON)

#if (SERIAL_PORT == STD_ON)
#define SERIAL_BAUDRATE (115200)
#endif


#endif /*SYSTEMCONFIG_H*/