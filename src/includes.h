#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils/utils.h"
#include "response/response.h"
#include "problems/problems.h"

Response* (*p_list[])(void) = { p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17 };

#endif // __INCLUDES_H__
