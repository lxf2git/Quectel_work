#include"rev_sort.h"

void init_mod(pMod *p)
{
	int i;
	creat_memory((void**)p,sizeof(sMod));
	for(i=0;i<26;i++)
	{
		init_and(&(*p)->mod[i]);
	}
}
void init_and(pAnd *p)
{
	int i;
	creat_memory((void**)p,sizeof(sAnd));
	for(i=0;i<10;i++)
	{
		init_word(&(*p)->_and[i]);
	}
}
void init_word(pWord *p)
{
	creat_memory((void**)p,sizeof(sWord));
	init_data(&(*p)->data);
//	(*p)->data = NULL;
	(*p)->chword = NULL;
	(*p)->prev = *p;
	(*p)->next = *p;
}
void init_data(pData *p)
{
	creat_memory((void**)p,sizeof(sData));
	(*p)->file_name = NULL;
	(*p)->num = 0;
	(*p)->prev = *p;
	(*p)->next = *p;	
}
void creat_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	bzero(*p,size);
}
