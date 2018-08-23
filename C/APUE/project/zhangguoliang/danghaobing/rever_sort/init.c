#include"init.h"

void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p==NULL)
	{
			printf("malloc error!\n");
			exit(-1);
	}
}

void init_same_word(pSword *psword)
{
	create_memory((void **)psword,sizeof(sSword));
	(*psword)->next=(*psword);
	(*psword)->prev=(*psword);
	(*psword)->num = 0;
}

void init_word(pWord *pword)
{
		create_memory((void **)pword,sizeof(sWord));
		(*pword)->next = (*pword);
		(*pword)->prev = (*pword);
		init_same_word(&(*pword)->same_words);
}

void init_second(pSec *psecond)
{
	create_memory((void **)psecond,sizeof(sSec));
	int i;
	for(i=0;i<13;i++)
	{
		init_word(&(*psecond)->dword[i]);
	}
}

void init_first(pFirst *pfirst)
{
	create_memory((void **)pfirst,sizeof(sFirst));
	int i;
	for(i=0;i<4;i++)
	{
			init_second(&(*pfirst)->dsecond[i]);
	}
}
