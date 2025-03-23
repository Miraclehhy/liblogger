#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger_def.h"

#define MAX_TIME_STAMP_LEN (20)
#define MAX_TITLE_LEN (32)
#define MAX_LOG_LEN (1024)

static int add_time_stamp(char *buf, size_t len);
static int create_title(const char *zone, const char *level, const char *color, char *buf, size_t len);

static int add_time_stamp(char *buf, size_t len)
{
    (void)buf;
    (void)len;
    return 0;
}

static int add_level(const char *level, const char *color, char *buf, size_t len)
{
    int ret = 0;
    char title[MAX_TITLE_LEN] = {0};

    when_null_status(level, exit, ret = -1);
    when_null_status(buf, exit, ret = -1);

    if (color == NULL)
    {
	    snprintf(title, sizeof(title), "%s[%-6s]", buf, level);
    }
    else
    {
	    snprintf(title, sizeof(title), "%s[%s%-6s%s]", buf, color, level, COLOR_RESET);
    }

    memset(buf, 0, len);
    snprintf(buf, len, "%s", title);

exit:
    return ret;
}

static int add_zone(const char *zone, char *buf, size_t len)
{
    int ret = 0;
    char title[MAX_TITLE_LEN] = {0};

    when_null_status(zone, exit, ret = -1);
    when_null_status(buf, exit, ret = -1);

    snprintf(title, sizeof(title), "%s[%s]", buf, zone);
    memset(buf, 0, len);
    snprintf(buf, len, "%s", title);

exit:
    return ret;
}

static int create_title(const char *zone, const char *level, const char *color, char *buf, size_t len)
{
    int ret = 0;
    char title[MAX_TITLE_LEN] = {0};

    when_null_status(level, exit, ret = -1);
    when_null_status(buf, exit, ret = -1);

    ret = add_level(level, color, title, sizeof(title));
    when_true(ret < 0, exit);

    if (zone != NULL)
    {
	    ret = add_zone(zone, title, sizeof(title));
	    when_true(ret < 0, exit);
    }

    snprintf(buf, len, "%s", title);
exit:
    return ret;
}

int log_message(const char *zone, const char *level, const char *color, const char *format, ...)
{
    va_list args;
    char time_stamp[MAX_TIME_STAMP_LEN] = {0};
    char title[MAX_TITLE_LEN] = {0};
    char log[MAX_LOG_LEN] = {0};
    int ret = -1;

    when_null_status(level, exit, ret = -1);
    when_null_status(format, exit, ret = -1);

    ret = add_time_stamp(time_stamp, sizeof(time_stamp));
    when_true(ret < 0, exit);

    ret = create_title(zone, level, color, title, sizeof(title));
    when_true(ret < 0, exit);

    va_start(args, format);
    vsnprintf(log, sizeof(log), format, args);
    va_end(args);

    if (zone == NULL)
    {
	    printf("%s%s: %s\n", time_stamp, title, log);
    }
    else
    {
	    printf("%s%-25s: %s\n", time_stamp, title, log);
    }

exit:
    return ret;
}
