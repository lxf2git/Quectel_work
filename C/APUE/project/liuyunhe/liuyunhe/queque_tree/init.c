#include"init.h"

void init_root(pTree *root)
{
		*root = malloc(sizeof(sTree));
		if((*root)==NULL)
		{
				printf("sorry NULL \n");
				exit(-1);
		}
		(*root)->tr_lc=NULL;
		(*root)->tr_rc=NULL;
}

void init_pStack(pStack *pf)
{
		*pf=malloc(sizeof(sStack));
		if((*pf)==NULL)
		{
				printf("sorry NULL \n");
				exit(-1);
		}
		(*pf)->prev=(*pf);
		(*pf)->next=(*pf);
}
