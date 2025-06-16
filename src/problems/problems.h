#ifndef __PROBLEMS_H__
#define __PROBLEMS_H__

#define GRID_20x20 20
#define GRID_21x21 21

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <gmp.h>

#include "../response/response.h"
#include "../utils/utils.h"

extern Response* (*p_list[])(void);

Response* p1();
Response* p2();
Response* p3();
Response* p4();
Response* p5();
Response* p6();
Response* p7();
Response* p8();
Response* p9();
Response* p10();
Response* p11();
Response* p12();
Response* p13();
Response* p14();
Response* p15();
Response* p16();
Response* p17();

#endif // __PROBLEMS_H__
