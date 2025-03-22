#include <stdio.h>

#include "logger.h"

#define ME "TEST"

int main(int argc, char *argv[])
{
    printf("======test start=====\n");

    LOG_ERROR("log %s test", "error");
    LOG_WARN("log %s test", "warn");
    LOG_NOTICE("log %s test", "notice");
    LOG_INFO("log %s test", "info");
    LOG_DEBUG("log %s test", "debug");

    LOGZ_ERROR(ME, "log %s test", "error");
    LOGZ_WARN(ME, "log %s test", "warn");
    LOGZ_NOTICE(ME, "log %s test", "notice");
    LOGZ_INFO(ME, "log %s test", "info");
    LOGZ_DEBUG(ME, "log %s test", "debug");    

    printf("======test end========\n");

    return 0;
}