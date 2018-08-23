#ifndef _PUB_H_
#define _PUB_H_

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define PRBG printf("[%s]debug.\n", __FUNCTION__);
#define PRINT(data) printf("[%s]%d\n", __FUNCTION__, data);
#define PRINTCHAR(data) printf("[%s]%c\n", __FUNCTION__, data);
#define PRINTSTR(data) printf("[%s]%s\n", __FUNCTION__, data);

typedef struct{
	unsigned int size;
	void *start_add;
	void *end_add;
	struct list _list;
}sData, *pData;

typedef struct{
	struct list *address;
	struct list _list;
}sRecordNode, *pRecordNode;

typedef struct{
	unsigned int record_index;
	struct list _list;
	struct list record_list;
}sRecordHead, *pRecordHead;

struct syslist{
	struct list *apply_list;
	struct list *free_list;
	struct list *record_list;
};

extern unsigned int sum_size;
extern unsigned int record_index;

#include "memory.h"
#endif
