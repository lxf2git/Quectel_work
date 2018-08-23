#include"insert.h"

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_mod(pMod p)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		creat_memory((void **)&p->mod[i],sizeof(sAnd));
		for(j=0;j<M;j++)
		{
			creat_memory((void **)&p->mod[i]->and_[j],sizeof(sWord));
		}
	}
}

void init_word(pWord *p,int size)
{
	creat_memory((void**)p,size);
	init_label(&(*p)->label,sizeof(sLabel));
	(*p)->next=NULL;
}

void init_label(pLabel *p,int size)
{
	creat_memory((void**)p,size);
	(*p)->next=(*p);
	(*p)->file_no=0;
	(*p)->num=0;
}

