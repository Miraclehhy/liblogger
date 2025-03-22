#ifndef __LOGGER_H__
#define __LOGGER_H__

#ifndef MAX_LOGGER_LEVEL
#define MAX_LOGGER_LEVEL 5
#endif

#define LOG(level, ...) LOG_##level(__VA_ARG__)

#if MAX_LOGGER_LEVEL > 0
#define LOG_ERROR(...) log_error(__VA_ARG__)
#else
#define LOG_ERROR(...)
#endif

#if MAX_LOGGER_LEVEL > 1
#define LOG_WARN(...) log_warn(__VA_ARG__)
#else
#define LOG_WARN(...)
#endif

#if MAX_LOGGER_LEVEL > 2
#define LOG_NOTICE(...) log_notice(__VA_ARG__)
#else
#define LOG_NOTICE(...)
#endif

#if MAX_LOGGER_LEVEL > 3
#define LOG_INFO(...) log_info(__VA_ARG__)
#else
#define LOG_INFO(...)
#endif

#if MAX_LOGGER_LEVEL > 4
#define LOG_DEBUG(...) log_debug(__VA_ARG__)
#else
#define LOG_DEBUG(...)
#endif

#endif /* __LOGGER_H__ */