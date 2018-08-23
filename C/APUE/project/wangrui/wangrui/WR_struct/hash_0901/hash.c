#include"hash.h"

void creat_hash_list(pData phead)
{
	int i,j;
//	pAnd pand = NULL;
	pMod pmod = NULL;
//	creat_memory((void **)&pand,sizeof(sAnd));
//	creat_memory((void **)&pand,sizeof(sMod));
	init_mod(&pmod);
	pData ptmp=NULL;
//	printf("while will in\n");
	while(phead->next!=phead)
	{
		ptmp = phead->next;
		j = ptmp->data>>3&7;
		i = ptmp->data%5;
		phead->next = ptmp->next;
		ptmp->next->prev = phead;
		ptmp->next = ptmp;
		ptmp->prev = ptmp;
		insert_back(pmod->mod[i]->_and[j],ptmp);
	}
//	printf("while out\n");
//	show_chain(pmod->mod[4]->_and[1]);
//	printf("a\n");
	search_data(pmod);
}

void search_data(pMod pmod)
{
	int num,i,j;
	pData ptmp = NULL;
	printf("search data\n");
	scanf("%d",&num);
	j = num>>3&7;
	i = num%5;
	ptmp = pmod->mod[i]->_and[j];
	if(ptmp->next == NULL)
	{
		printf("no data\n");
	}
	else
	{
		printf("ret:\n");
		show_chain(ptmp);
	}
}
