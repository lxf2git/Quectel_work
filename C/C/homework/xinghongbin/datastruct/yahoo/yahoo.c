#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
		int id;
		struct student *next;
		struct student *prev;
}*pStu;
void chain_init(pStu *p);
void create_memory(pStu *p,int size);
void chain_create(pStu pHead);
pStu chain_insert(pStu pHead,pStu pInsert);
void chain_delete(pStu pHeadA,pStu pHeadB);
void chain_output(pStu pHead);
void delete_fun(pStu *pDel);
void delete_A(pStu *pA,int temp,pStu pHeadA);
void myfree(pStu *pHead);
void free_fun(pStu *p);
int main()
{
		pStu pHeadA;
		pStu pHeadB;
		chain_init(&pHeadA);
		chain_create(pHeadA);

		printf("B:\n");
		chain_init(&pHeadB);
		chain_create(pHeadB);

		chain_delete(pHeadA,pHeadB);
		
		chain_output(pHeadA);
		myfree(&pHeadA);

		printf("B:\n");
		chain_output(pHeadB);
		myfree(&pHeadB);

}
void myfree(pStu *pHead)
{
		pStu p=(*pHead)->next;
		while(p!= (*pHead))
		{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				free_fun(&p);
				p = (*pHead)->next;
		}
		free_fun(pHead);
}
void free_fun(pStu *p)
{
		if(NULL != (*p))
		{
				free(*p);
				(*p) = NULL;
		}
		printf("free-free-free-free\n");

}
void chain_init(pStu *p)
{
		create_memory(p,sizeof(struct student));
		(*p)->next= *p;
		(*p)->prev= *p;

}
void create_memory(pStu *p,int size)
{
		*p = (pStu)malloc(size);
		if(*p == NULL)
		{
				printf("memroy error\n");
				exit(-1);
		}

}
void chain_create(pStu pHead)
{
		pStu p;
		pStu pPbf;
		int ret;
		do
		{
				chain_init(&p);
				printf("input id:");
				ret = scanf("%d",&p->id);
				if(ret !=0 )
				{
						pPbf=chain_insert(pHead,p);
						p->next = pPbf->next;
						p->prev = pPbf;
						pPbf->next->prev = p;
						pPbf->next = p;
				}

		}while(ret != 0);
		while(getchar() != '\n');
}

pStu chain_insert(pStu pHead,pStu pInsert)
{
		pStu p;
		p = pHead;
		while(p->next != pHead)
		{
				if(p->next->id > pInsert->id)
				{
						return p;
				}
				p=p->next;
		}
		return p;
}
void chain_delete(pStu pHeadA,pStu pHeadB)
{
		int temp = -1;
		int ret = 0;
		pStu pTemp = pHeadA->next;
		pStu pA= pHeadA->next;
		pStu pB = pHeadB->next;
		while(pTemp != pHeadA)
		{
				while(pB != pHeadB)
				{
						if(pTemp->id == pB->id)
						{
								temp = pTemp->id;
								delete_fun(&pB);
								pB =pHeadB->next;
								continue;

						}
						pB = pB->next;
				}

				if(temp != -1)
				{
						delete_A(&pA,temp,pHeadA);
						temp = -1;
						pTemp = pHeadA;
						

				}
			
				pTemp = pTemp->next;
				pB=pHeadB->next;
				pA=pHeadA->next;
		}


}
void delete_A(pStu *pA,int temp,pStu pHeadA)
{

		while ((*pA) != pHeadA)
		{
				if((*pA)->id == temp)
				{
						delete_fun(pA);
						(*pA) =pHeadA->next;
						continue;
				}
				(*pA) = (*pA)->next;
		}

}

void delete_fun(pStu *pDel)
{
		(*pDel)->prev->next = (*pDel)->next;
		(*pDel)->next->prev = (*pDel)->prev;

		(*pDel)->prev = NULL;
		(*pDel)->next = NULL;
		free_fun(pDel);

}
void chain_output(pStu pHead)
{
		pStu p =pHead->next;
		while(p !=pHead )
		{
				printf("%d\n",p->id);
				p = p->next;
				
		}
}
