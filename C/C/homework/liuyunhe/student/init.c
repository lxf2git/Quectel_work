#include"init.h"

void init_Node(pStu *p,int size)
{
		*p=malloc(size);
		(*p)->next=NULL;
}


//**********
void Deatory_deat(pStu *pdel)
{
		if(*pdel!=NULL)
		{
				free(*pdel);
				*pdel=NULL;
		}
}

void Destory_list(pStu *pHead)
{
		pStu pdel=NULL;
		while((*pHead)->next!=NULL)
		{
				pdel=(*pHead)->next;
				(*pHead)->next=(*pHead)->next->next;
				pdel->next=NULL;
				Deatory_deat(&pdel);
		}
}
