#include"clean.h"

void free_Node(pMem p)
{
		if(p!=NULL)
		{
			p->next = NULL;
			p->prev = NULL;
			free(p);
			p=NULL;
		}

}

void clean_Mem(pMem p)
{
		while(p->next!=p)
		{
			pMem ptmp = p->next;
			p->next = p->next->next;
			free_Node(ptmp);
		}
		free_Node(p);
}
void free_Rnode(pRc p)
{
		p->next = NULL;
		p->prev = NULL;
		if((p->pdata)!=NULL)
		{
			free(p->pdata);
			(p->pdata)=NULL;
		}
		if(p!=NULL)
		{	
			free(p);
			p = NULL;
		}

}
void clean_Rco(pRc p)
{
		while(p->next!=p)
		{
				pRc ptmp = p->next;
				p->next = p->next->next;
				free_Rnode(ptmp);
		}
		free_Rnode(p);
}

void clean_data(pMem pHead,pMem pFead,pRc pRead)
{
		clean_Mem(pHead);
		clean_Mem(pFead);
		clean_Rco(pRead);
}









