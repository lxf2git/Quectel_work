#include"free.h"
#include"main.h"

void num_free(pMem pHead,pMem pfree,pRec pnum)
{
	int number;
	int j;
	printf("please input number:\n");
	scanf("%d",&number);
	int k;
	pRec ptmp=pnum;
	for(k=0;k<number;k++)
	{
		ptmp=ptmp->next;
	}
	pMem pnew=pHead->next;
	pMem pnewf=pfree->next;

	while(pnewf!=pfree)
	{
		int i=0;
		pnewf=pfree->next;
		for(j=0;j<5;j++)
		{
			if(ptmp->pdata[j]==pnewf)
			{
				pnew=pHead->next;
				while(pnew!=pHead)
				{
					if(pnew->index==pnewf->index)
					{
						pMem pdel=pnewf;
						pnew->mem_size+=pnewf->mem_size;
						pnewf->next->prev=pnewf->prev;
						pnewf->prev->next=pnewf->next;
						delete_mem(&pdel);
						i=1;
					}
					pnew=pnew->next;
				}
				if(i==0)//pnew中没有剩余相对的空间
				{
					int m;
					pMem pnewa=NULL;
					init_memory(&pnewa);
					pnewa->index=pnewf->index;
					m=pnewf->index;
					pnewa->mem_size=pnewf->mem_size;
					pnew=pHead->next;
					while(pnew!=pHead)
					{
						if(m < pnew->index && m > pnew->prev->index)
						{
							pMem pdel=pnewf;
							pnewf->next->prev=pnewf->prev;
							pnewf->prev->next=pnewf->next;

							pnewa->next=pnew;
							pnewa->prev=pnew->prev;
							pnew->prev->next=pnewa;
							pnew->prev=pnewa;
							delete_mem(&pdel);
							break;
						}
						else if(m > pHead->prev->index)
						{
							pMem pdel=pnewf;
							pnewf->next->prev=pnewf->prev;
							pnewf->prev->next=pnewf->next;
							
							pnewa->prev=pHead->prev;
							pnewa->next=pHead;
							pHead->prev->next=pnewa;
							pHead->prev=pnewa;

							delete_mem(&pdel);
						}
						else
						{
							pnew=pnew->next;
						}
					}
				}
			}
		}
		pnewf=pnewf->next;
	}
}


