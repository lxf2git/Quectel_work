#include"apply.h"
void create_memory(pMem *p)
{
		*p=(pMem)malloc(sizeof(sMem));
		if(NULL==*p)
		{
				printf("malloc error");
				exit(-1);
		}
}
void init_pnode(pMem *pnode)
{
		create_memory(pnode);
		(*pnode)->next=*pnode;
		(*pnode)->prev=*pnode;

}
void create_tail_chain(pMem pHead,int num)
{
		int i;
		pMem pnew=NULL;
		for(i=0;i<num;i++)
		{
				init_pnode(&pnew);
				pnew->index=i+1;
				pnew->mem_size=10;
				pnew->prev=pHead->prev;
				pHead->prev->next=pnew;
				pHead->prev=pnew;
				pnew->next=pHead;
		}
}
void show_chain(pMem pHead)
{
		pMem ptmp=NULL;
		for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
		{
				printf("%d ",ptmp->index);
				printf("%d\n",ptmp->mem_size);
		}
}
/*void create_memory1(pr *p)
{
		*p=(pr)malloc(sizeof(sr ));
		if(NULL==*p)
		{
				printf("malloc error");
				exit(-1);
		}
}*/
void init_pnode1(pr *p)
{
		*p=(pr)malloc(sizeof(sr));
		(*p)->pdata=(pMem*)malloc(10*sizeof(pMem));
		if(*p==NULL)
		{
			printf("malloc error");
			exit(-1);
		}
		(*p)->next=*p;
		(*p)->prev=*p;
	//	(*p)->pdata=NULL;
}

pMem find_max(pMem pHead,pMem pnew)
{
		pMem pTrav=pHead;
		while(pTrav->next!=pHead)
		{
				if(pTrav->next->mem_size>=pnew->mem_size)
				{
						return pTrav;
				}
				pTrav=pTrav->next;
		}
		return pTrav;
}

int insert_back(pMem pPos,pMem pIn)
{
	if(pPos==NULL||pIn==NULL)
	{
			return -1;
	}
	pPos->next->prev=pIn;
	pIn->prev=pPos;
	pIn->next=pPos->next;
	pPos->next=pIn;
}
void show_chain1(pr pHead2,int n)
{
		int i;
		pr ptmp=NULL;
		for(ptmp=pHead2->next;ptmp!=pHead2;ptmp=ptmp->next)
		{
				printf("========\n");
				for(i=0;ptmp->pdata[i]!=NULL;i++)
				{
				printf("%d ",ptmp->pdata[i]->index);
				printf("%d\n",ptmp->pdata[i]->mem_size);
				}
		}

}
void  apply(pMem pHead,pMem pHead1,int a,pr pHead2)
{
		pMem ptmp=NULL;
		pMem pt=NULL;
		pMem pl=NULL; 
		pMem pmax1=NULL;
		pMem pmax2=NULL;
		pMem pmax3=NULL;
		pMem pnew=NULL;
		init_pnode(&pnew);
		pr pnew1=NULL;
		init_pnode1(&pnew1);
		int max=0,m=0,n=0;
		for(;;)
		{
			
		for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
		{
			if(max<ptmp->mem_size)
			{
					max=ptmp->mem_size;
					pt=ptmp;
			//		printf(" pt:%d\n",pt->index);

			}
		}
	//	printf("max:%d\n",max);
		if(a>=max)
		{
				pt->prev->next=pt->next;
				pt->next->prev=pt->prev;
				pt->prev=pt;
				pt->next=pt;
				a=a-max;
	//			printf("a==%d\n",a);
				 pmax1=find_max(pHead1,pt);
				insert_back(pmax1,pt);
				pnew1->pdata[n]=pt;
				n++;
		//		pt->prev=pHead1->next;
		//		pHead1->prev->next=pt;
		//		pHead1->prev=pt;
		//		pt->next=pHead1;

		}
		else
		{
				for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
				{
						if(a==ptmp->mem_size)
						{
	//							printf("a:%d\n",a);
							pl=ptmp;
							pl->prev->next=pl->next;
							pl->next->prev=pl->prev;
							pl->prev=pl;
							pl->next=pl;
							
							 pmax2=find_max(pHead1,pl);
							insert_back(pmax2,pl);
							m=1;
							pnew1->pdata[n]=pl;
							n++;
						//	pl->prev=pHead1->next;
						//	pHead1->prev->next=pl;
						//	pHead1->prev=pl;
						//	pl->next=pHead1;
							break;
						}

				}
				if(m==0)
				{
				pt->mem_size=pt->mem_size-a;
				pnew->mem_size=a;
				pnew->index=pt->index;
				pmax3=find_max(pHead1,pnew);
				insert_back(pmax3,pnew);
				pnew1->pdata[n]=pnew;
				n++;
				}
				a=0;
							
   		}
		if(a==0)
				break;
		max=0;
		}
		
				pnew1->prev=pHead2->prev;
				pHead2->prev->next=pnew1;
				pHead2->prev=pnew1;
				pnew1->next=pHead2;
				
}
