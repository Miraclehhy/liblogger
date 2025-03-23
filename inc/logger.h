#ifndef __LOGGER_H__
#define __LOGGER_H__

#ifndef MAX_LOGGER_LEVEL
#define MAX_LOGGER_LEVEL 5
#endif

#define LOGGER_COLOR_RED "\033[31m"
#define LOGGER_COLOR_GREEN "\033[32m"
#define LOGGER_COLOR_YELLOW "\033[33m"
#define LOGGER_COLOR_BLUE "\033[34m"
#define LOGGER_COLOR_WHITE "\033[37m"

int log_message(const char *zone, const char *level, const char *color, const char *format, ...);

#if MAX_LOGGER_LEVEL > 0
#define LOG_ERROR(...) log_message(NULL, "ERROR", LOGGER_COLOR_RED, __VA_ARGS__)
#define LOGZ_ERROR(zone, ...) log_message(zone, "ERROR", LOGGER_COLOR_RED, __VA_ARGS__)
#else
#define LOG_ERROR(...)
#define LOGZ_ERROR(zone, ...)
#endif

#if MAX_LOGGER_LEVEL > 1
#define LOG_WARN(...) log_message(NULL, "WARN", LOGGER_COLOR_YELLOW, __VA_ARGS__)
#define LOGZ_WARN(zone, ...) log_message(zone, "WARN", LOGGER_COLOR_YELLOW, __VA_ARGS__)
#else
#define LOG_WARN(...)
#define LOGZ_WARN(zone, ...)
#endif

#if MAX_LOGGER_LEVEL > 2
#define LOG_NOTICE(...) log_message(NULL, "NOTICE", LOGGER_COLOR_GREEN, __VA_ARGS__)
#define LOGZ_NOTICE(zone, ...) log_message(zone, "NOTICE", LOGGER_COLOR_GREEN, __VA_ARGS__)
#else
#define LOG_NOTICE(...)
#define LOGZ_NOTICE(zone, ...)
#endif

#if MAX_LOGGER_LEVEL > 3
#define LOG_INFO(...) log_message(NULL, "INFO", LOGGER_COLOR_BLUE, __VA_ARGS__)
#define LOGZ_INFO(zone, ...) log_message(zone, "INFO", LOGGER_COLOR_BLUE, __VA_ARGS__)
#else
#define LOG_INFO(...)
#define LOGZ_INFO(zone, ...)
#endif

#if MAX_LOGGER_LEVEL > 4
#define LOG_DEBUG(...) log_message(NULL, "DEBUG", LOGGER_COLOR_WHITE, __VA_ARGS__)
#define LOGZ_DEBUG(zone, ...) log_message(zone, "DEBUG", LOGGER_COLOR_WHITE, __VA_ARGS__)
#else
#define LOG_DEBUG(...)
#define LOGZ_DEBUG(zone, ...)
#endif

#endif /* __LOGGER_H__ */