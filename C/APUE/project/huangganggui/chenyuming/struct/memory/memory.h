#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "pub.h"

void init_memory_list(struct list *);
void PrintData(struct list *);
void ApplyMemory(struct syslist *);
void Fun_apply(struct syslist *, unsigned int);
void Fun_apply_low(struct syslist *, unsigned int, struct list *);
void Fun_apply_high(struct syslist *, unsigned int);
void InsertFreeList();
struct list *find_max_size(struct list *);
struct list *find_equal_size(struct list *, unsigned int);
void FreeMemory(struct syslist *);
void free_fun(struct syslist *, pRecordHead);

//void (*Memory_Fun[2])(struct syslist *syslist) = {ApplyMemory, FreeMemory};
#endif
