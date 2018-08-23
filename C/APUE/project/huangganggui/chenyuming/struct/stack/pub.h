#ifndef _PUB_H_
#define _PUB_H_

//#define unsigned int size_t
#define PRINTBG printf("[%s]debug.\n", __FUNCTION__);


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

size_t convert_two(pStack, int);
size_t convert_eight(pStack, int);
size_t convert_sixteen(pStack, int);
size_t (*convert_numsys[3])(pStack, int);

#define init_fun  \
	convert_numsys[0] = convert_two;  \
	convert_numsys[1] = convert_eight;  \
	convert_numsys[2] = convert_sixteen


#endif
