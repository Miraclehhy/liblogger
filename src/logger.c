#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "logger_def.h"

#define MAX_TITLE_LEN (128)

int log_error(const char *zone, const char *format, ...)
{
    va_list args;
    char title[MAX_TITLE_LEN] = {0};

    va_start(args, format);

    if (zone == NULL)
    {
        snprintf(title, sizeof(title), "["COLOR_RED"ERROR"COLOR_RESET"]");
    }
    else
    {
        snprintf(title, sizeof(title), "["COLOR_RED"ERROR"COLOR_RESET"][%s]", zone);
    }

    printf("%-20s:", title);

    vprintf(format, args);
    printf("\n");

    va_end(args);
    return 0;
}

int log_warn(const char *zone, const char *format, ...)
{
    va_list args;

    va_start(args, format);

    if (zone == NULL)
    {
        printf("[%-15s]:", COLOR_YELLOW"WARN"COLOR_RESET);
    }
    else
    {
        printf("[%-15s]%-10s:", COLOR_YELLOW"WARN"COLOR_RESET, zone);
    }
    
    vprintf(format, args);
    printf("\n");

    va_end(args);
    return 0;
}

int log_notice(const char *zone, const char *format, ...)
{
    va_list args;

    va_start(args, format);

    if (zone == NULL)
    {
        printf("[%-15s]:", COLOR_GREEN"NOTICE"COLOR_RESET);
    }
    else
    {
        printf("[%-15s]%-10s:", COLOR_GREEN"NOTICE"COLOR_RESET, zone);
    }

    vprintf(format, args);
    printf("\n");

    va_end(args);
    return 0;
}

int log_info(const char *zone, const char *format, ...)
{
    va_list args;

    va_start(args, format);

    if (zone == NULL)
    {
        printf("[%-15s]:", COLOR_BLUE"INFO"COLOR_RESET);
    }
    else
    {
        printf("[%-15s]%-10s:", COLOR_BLUE"INFO"COLOR_RESET, zone);
    }

    vprintf(format, args);
    printf("\n");

    va_end(args);
    return 0;
}

int log_debug(const char *zone, const char *format, ...)
{
    va_list args;

    va_start(args, format);

    if (zone == NULL)
    {
        printf("[%-15s]:", COLOR_WHITE"DEBUG"COLOR_RESET);
    }
    else
    {
        printf("[%-15s]%-10s:", COLOR_WHITE"DEBUG"COLOR_RESET, zone);
    }

    vprintf(format, args);
    printf("\n");

    va_end(args);
    return 0;
}

