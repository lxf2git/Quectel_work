#include"main.h"
int main()
{
		struct Memory *pApply;
		struct Memory *pFree;
		struct Record *pFreenumber[10];
		chain_init(&pApply,sizeof(struct Memory));
		chain_init(&pFree,sizeof(sMem));
		free_arr(pFreenumber,sizeof(sRec));
		create_apply(pApply);

		Meun(pApply,pFree,pFreenumber);
//		myfree(&pApply);

}
void Meun(pMem pApply,pMem pFree,pRec *pFreenumber)
{
		int choose;
		int ret=0;
		int i=0;
		do
		{
				printf("1 make memory 2 output,3 free");
				ret = scanf("%d",&choose);
				if(ret != 0);
				switch(choose)
				{
						case 1:
								//chain_freehead(pFreenumber,pFree,pApply);
					            separate_memory(pApply,pFreenumber[i],pFree);
								output_rec(pFreenumber[i]);
								i++;
								break;
						case 2:
								output(pApply);
								printf("free\n");
					    		output(pFree);
								break;
						case 3:
								freefree(pFreenumber,pApply,pFree);
								break;
						default:
								printf("input error\n");
								exit(-1);

				}
		}while(ret != 0);

}
void free_arr(pRec *p,int size)
{
		int i;
		for(i=0;i<10;i++)
		{
				free_init(&p[i],sizeof(sRec));

		}
}
void free_init(pRec*p,int size)
{
				create_memory((pMem *)(p),size);
				chain_init(&(*p)->pdata,sizeof(sMem));
				(*p)->prev = (*p);
				(*p)->next = (*p);
		
}
void chain_init(pMem *p,int size)
{
		create_memory(p,size);
		(*p)->next = (*p);
		(*p)->prev = (*p);
}
void create_memory(pMem *p,int size)
{
		*p = (pMem)malloc(size);
		if(*p == NULL)
		{
				printf("memory error\n");
				exit(-1);
		}
}
void output(pMem pHead)
{
		pMem p=pHead->next;
		while(p != pHead)
		{
				printf("index%d size%d\n",p->index,p->size);
				p = p->next;
		}
}

void output_rec(pRec pHead)
{
		pRec p=pHead->next;
		while(p != pHead)
		{
				printf("index%d size%d\n",p->pdata->index,p->pdata->size);
				p = p->next;
		}

}
/*
void myfree(pMem *pHead)
{
		pMem p = (*pHead)->next
		while(p != (*pHead))
		{
				delete_chain(p,p->next);
				free()
				p = (*pHead)->next
		}
}
*/
