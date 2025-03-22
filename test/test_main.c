#include <stdio.h>

#include "logger.h"

int main(int argc, char *argv[])
{
    printf("======test start=====\n");
    LOG(ERROR, "log error test");
    LOG(WARN, "log error test");
    LOG(NOTICE, "log error test");
    LOG(INFO, "log error test");
    LOG(DEBUG, "log error test");
    printf("======test end========\n");

    return 0;
}