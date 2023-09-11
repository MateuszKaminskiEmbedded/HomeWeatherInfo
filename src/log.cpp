#include <Arduino.h>
#include "system_config.h"
#include "types.h"
#include "log.h"

void log(LogLevel level, const char* message) {
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

  void log(LogLevel level, const char* message, int value) {
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
      Serial.print(message);
      Serial.println(value);
  }

  void log(LogLevel level, const char* message, float value) {
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
      Serial.print(message);
      Serial.println(value);
  }