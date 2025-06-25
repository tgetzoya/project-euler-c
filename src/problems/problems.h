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

Response* p1(void);
Response* p2(void);
Response* p3(void);
Response* p4(void);
Response* p5(void);
Response* p6(void);
Response* p7(void);
Response* p8(void);
Response* p9(void);
Response* p10(void);
Response* p11(void);
Response* p12(void);
Response* p13(void);
Response* p14(void);
Response* p15(void);
Response* p16(void);
Response* p17(void);
Response* p18(void);
Response* p19(void);
Response* p20(void);

Response* p67(void);

#endif // __PROBLEMS_H__
