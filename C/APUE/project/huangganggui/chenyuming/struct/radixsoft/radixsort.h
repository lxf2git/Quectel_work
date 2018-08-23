#ifndef _RADIXSORT_H_
#define _RADIXSORT_H_

#include "pub.h"
#include "list.h"


#define radix_div_sum(div_tmp, time) for(; time!=1; time--) {  \
											div_tmp = div_tmp*10; \
											}

typedef struct{
	unsigned int data;
	struct list _list;
}sData, *pData;




void radixsort(struct list *);
unsigned int find_max(struct list *);
void distribute(struct list *, struct list *, int);
void sort_list_insert(struct list *, struct list *, int);
void collect(struct list *, struct list*);
int cal_time(unsigned int);
int sort_bit(int, unsigned int);
#endif
