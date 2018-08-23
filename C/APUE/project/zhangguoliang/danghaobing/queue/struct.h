#ifndef _STRUCT_H_
#define _STRUCT_H_
#define SIZE 30
#define FULL -1
#define EMPTY -2
#define SUC 0
typedef struct tree
{
	char data;
	struct tree *lc;
	struct tree *rc;
}sTree,*pTree;

typedef struct s_queue
{
		pTree arr[SIZE];
		int pw;//指向队尾的下一个元素
		int pr;//指向队头元素
}sQueue,*pQueue;


#endif
