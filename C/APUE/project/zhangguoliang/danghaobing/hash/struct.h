#ifndef _STRUCT_H_
#define _STRUCT_H_

struct data
{
		int data;
		struct data *prev;
		struct data *next;
};

struct and
{
	struct data *and[8];
};

typedef struct mode
{
		struct and *mod[5];
}sMode,*pMode;

#endif
