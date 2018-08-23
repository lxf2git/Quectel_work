#include"init.h"

void create_memory(pStu *p,int size)
{
	*p = (pStu)malloc(size);
	if(*p==NULL){
		printf("malloc error\n");
		exit(-1);
	}
}

void create_memory_p(pList *p,int size)
{
	*p = (pList)malloc(size);
	if(*p==NULL){
		printf("malloc error\n");
		exit(-1);
	}
}

void init_node(pStu *p,int size)
{
	create_memory(p,size);
	(*p)->next = NULL;
}

void init_node_p(pList *p,int size)
{
	create_memory_p(p,size);
}

