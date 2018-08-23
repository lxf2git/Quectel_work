#include"init.h"
void chain_init(pStu *p)
{
		create_memory(p,sizeof(struct student));
		(*p)->next=NULL;

}
void list_init(pList *p)
{
		
		*p=(pList)malloc(sizeof(struct list));
}
void create_memory(pStu *p,int size)
{
		*p=(pStu)malloc(size);
}

void init_file(pStu pHead,pList plist)
{
		FILE *fp;
		fp = fopen("a","r");
		if(fp == NULL)
		{
				fp = fopen("a","w+");
//				plist->pStu_Save = save_chain;
//				plist->pStu_Save(pHead,fp);		
		}
		plist->pStu_Save = read_chain;
		plist->pStu_Save(pHead,fp);
		fclose(fp);		
		
}
void findtiall(pStu *p_pro)
{
		
		pStu p_tiall ;
		p_tiall=(*p_pro)->next;

		while(p_tiall != NULL)
		{
				 findtiall(&p_tiall);

		}
		printf("->free->free->free->free->free--\n");
		myfree(p_pro);


}

void myfree(pStu *p)
{
		if(*p != NULL)
		{
				free(*p);
				*p=NULL;
		}
}
