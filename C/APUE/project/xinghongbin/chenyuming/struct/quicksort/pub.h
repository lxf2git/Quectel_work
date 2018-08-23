#ifndef _PUB_H_
#define _PUB_H_

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "quicksort.h"

#define PRINTBG printf("[%s]debug.\n", __FUNCTION__);
#define PRINT(data) printf("[%s]%d\n", __FUNCTION__, data);

typedef struct{
	int data;
	struct list _list;
}sData, *pData;

static list_declare(data_head);

#endif
