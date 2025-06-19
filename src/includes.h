#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils/utils.h"
#include "response/response.h"
#include "problems/problems.h"

#include <cjson/cJSON.h>

#if defined(_WIN32) || defined(_WIN64)
    #define OS "Windows"
#elif defined(__APPLE__) && defined(__MACH__)
    #if defined(__arm64__) || defined(__aarch64__)
        #define OS "MacOS-Aarch64"
    #elif defined(__x86_64__)
        #define OS "MacOS-Intel"
    #else
        #define OS "MacOS-NoIdea"
    #endif
#elif defined(__FreeBSD__)
    #define OS "FreeBSD"
#elif defined(__linux__)
    #define OS "Linux"
#elif defined(__unix__)
    #define OS "Unix"
#endif

#define STRINGIFY_HELPER(x) #x
#define STRINGIFY(x) STRINGIFY_HELPER(x)

Response* (*p_list[])(void) = { p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18 };

#endif // __INCLUDES_H__
