#ifndef LOG_LIBRARY_H
#define LOG_LIBRARY_H

enum LogLevel {
  DEBUG,
  INFO,
  WARNING,
  ERROR
};

void log(LogLevel level, const char *message);
void log(LogLevel level, const char *message, int value);
void log(LogLevel level, const char *message, float value);

#endif /*LOG_LIBRARY_H*/