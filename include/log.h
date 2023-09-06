#ifndef LOG_LIBRARY_H
#define LOG_LIBRARY_H

#include <Arduino.h>

/*************************************************************************************
 * @TODO add time stamp to logs
 * and sending queue (optional) 
 *************************************************************************************/

enum LogLevel {
  DEBUG,
  INFO,
  WARNING,
  ERROR
};

class LogLibrary {
public:
  LogLibrary(LogLevel level) : logLevel(level) {}

  void log(LogLevel level, const char* message) {
    if (level >= logLevel) {
      switch (level) {
        case DEBUG:
          Serial.print("[DEBUG] ");
          break;
        case INFO:
          Serial.print("[INFO] ");
          break;
        case WARNING:
          Serial.print("[WARNING] ");
          break;
        case ERROR:
          Serial.print("[ERROR] ");
          break;
      }
      Serial.println(message);
    }
  }

private:
  LogLevel logLevel;
};

#endif
