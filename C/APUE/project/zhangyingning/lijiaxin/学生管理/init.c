#include"init.h"
void get_memory(void **q,int size)//在堆上开空间函数
{
        *q = malloc(size);
        if(*q == NULL)
        {   
                printf("malloc error\n");
                exit(-1);
        }   
}
void my_free(void **q)//释放空间函数
{
        if(*q!=NULL)
        {
                free(*q);
                *q = NULL;
        }
}
void init_S(pStu *pHead)//开空间并附初值
{
		get_memory((void **)pHead,sizeof(sStu));
		(*pHead)->next = NULL;
}
void init(pList *ppp)//主函数的入口
{
		get_memory((void **)ppp,sizeof(sList));
		init_S(&(*ppp)->head);
	//	get_memory((void **)&(ppp->head),sizeof(sStu));
		(*ppp)->head->next = NULL;
}
