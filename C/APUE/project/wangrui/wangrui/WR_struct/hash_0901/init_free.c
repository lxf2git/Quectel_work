#include"hash.h"

void creat_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}
void init_node(pData *pnode)
{
	creat_memory((void **)pnode,sizeof(sData));
	(*pnode)->prev = *pnode;
	(*pnode)->next = *pnode;
}
void creat_org_chain(pData phead)
{
	int i;
	pData pnew=NULL;
	for(i=0;i<N;i++)
	{
		init_node(&pnew);
		scanf("%d",&pnew->data);
		insert_back(phead,pnew);
	}
}
void init_mod(pMod *pmod)
{
	int i,j;
	creat_memory((void**)pmod,sizeof(sMod));
	for(i=0;i<5;i++)
	{
		creat_memory((void**)&((*pmod)->mod[i]),sizeof(sAnd));
		for(j=0;j<8;j++)
		{
			init_node(&((*pmod)->mod[i]->_and[j]));
		}
	}
}

void insert_back(pData phead,pData pnew)
{
	phead->prev->next = pnew;
	pnew->prev = phead->prev;
	pnew->next = phead;
	phead->prev = pnew;
}
