#ifndef __LOGGER_H__
#define __LOGGER_H__

#ifndef MAX_LOGGER_LEVEL
#define MAX_LOGGER_LEVEL 5
#endif

int log_error(const char *zone, const char *format, ...);
int log_warn(const char *zone, const char *format, ...);
int log_notice(const char *zone, const char *format, ...);
int log_info(const char *zone, const char *format, ...);
int log_debug(const char *zone, const char *format, ...);

#if MAX_LOGGER_LEVEL > 0
#define LOG_ERROR(...) log_error(NULL, __VA_ARGS__)
#define LOGZ_ERROR(zone, ...) log_error(zone, __VA_ARGS__)
#else
#define LOG_ERROR(...)
#define LOGZ_ERROR(zone, ...)
#endif

#if MAX_LOGGER_LEVEL > 1
#define LOG_WARN(...) log_warn(NULL, __VA_ARGS__)
#define LOGZ_WARN(zone, ...) log_warn(zone, __VA_ARGS__)
#else
#define LOG_WARN(...)
#define LOGZ_WARN(zone, ...)
#endif

#if MAX_LOGGER_LEVEL > 2
#define LOG_NOTICE(...) log_notice(NULL, __VA_ARGS__)
#define LOGZ_NOTICE(zone, ...) log_notice(zone, __VA_ARGS__)
#else
#define LOG_NOTICE(...)
#define LOGZ_NOTICE(zone, ...)
#endif

#if MAX_LOGGER_LEVEL > 3
#define LOG_INFO(...) log_info(NULL, __VA_ARGS__)
#define LOGZ_INFO(zone, ...) log_info(zone, __VA_ARGS__)
#else
#define LOG_INFO(...)
#define LOGZ_INFO(zone, ...)
#endif

#if MAX_LOGGER_LEVEL > 4
#define LOG_DEBUG(...) log_debug(NULL, __VA_ARGS__)
#define LOGZ_DEBUG(zone, ...) log_debug(zone, __VA_ARGS__)
#else
#define LOG_DEBUG(...)
#define LOGZ_DEBUG(zone, ...)
#endif

#endif /* __LOGGER_H__ */