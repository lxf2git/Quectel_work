#ifndef _INIT_H_
#define _INIT_H_

typedef struct manage
{
		 int index;
		 int mem_size;
		 struct manage *prev;
		 struct manage *next;
}smanage,*pmanage;

typedef struct record
{
		struct manage *pdata[10];
		struct record *next;
		struct record *prev;
}sRecord,*pRecord;
#endif
