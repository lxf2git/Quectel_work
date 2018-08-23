#include"main.h"
void create_memory(void **p,int size)
{
		*p=malloc(size);
		if(*p==NULL)
		{
				printf("create memory error!\n");
				exit(-1);
		}
}
void free_memory(void **p)
{
		if(*p!=NULL)
		{
				free(*p);
				*p=NULL;
		}
}
void create_col(pMod hash,int hash_row)
{
		pLetter pcol=NULL;
		create_memory((void**)&pcol,sizeof(sLetter));
		hash->mod[hash_row]=pcol;
}
void create_word_list(pMod hash,int hash_row,int hash_col)
{
		pWord pword=NULL;
		init_word_list(&pword);
		hash->mod[hash_row]->letter[hash_col]=pword;
}
void init_label_list(pLabel *p)
{
		create_memory((void **)p,sizeof(sLabel));
		(*p)->file_no=0;
		(*p)->num=0;
		(*p)->next=NULL;
}
void init_word_list(pWord *pnew)
{
		create_memory((void **)pnew,sizeof(sWord));
		init_label_list(&(*pnew)->label);
		(*pnew)->prev=*pnew;
		(*pnew)->next=*pnew;
		(*pnew)->word=NULL;
}
void init_hash(pMod hash)
{
		int i,j;
		for(i=0;i<ROW;i++)
		{
				create_col(hash,i);
				for(j=0;j<COL;j++)
				{
						create_word_list(hash,i,j);
				}
		}
}

void insert_word(pWord phead,pWord pnew)
{
		phead->prev->next=pnew;
		pnew->prev=phead->prev;
		phead->prev=pnew;
		pnew->next=phead;
}
void insert_label(pLabel phead,pLabel pnew)
{
		pLabel p=phead;
		while(p->next!=NULL)
		{
				p=p->next;
		}
		p->next=pnew;
}
