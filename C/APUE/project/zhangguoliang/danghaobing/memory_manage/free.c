#include"free.h"
void init_Rnode(pRc *pRead)
{
		create_memory((void **)pRead,sizeof(sRc));
		(*pRead)->pdata = (pMem*)malloc(sizeof(pMem));
		(*pRead)->prev=(*pRead);
		(*pRead)->next=(*pRead);
}

void Free(pMem pHead,pMem pFead,pRc pRead)
{
		printf("please input dijici:\n");
		int x,i=0,j;
		scanf("%d",&x);
		pRc ptmpr = pRead->next;
		while(ptmpr!=pRead)
		{
			i++;
			if(i==x)
			{
				pMem ptmpf = pFead;
					j=0;
					while(ptmpf->next!=pFead)
					{
							if(ptmpr->pdata[j]==ptmpf->next)
							{
								j++;
								pMem del = ptmpf->next;
								ptmpf->next->next->prev = ptmpf;
								ptmpf->next = ptmpf->next->next;
								pMem ptmp = pHead->next;
								while(1)
								{
									if(del->index < ptmp->index||ptmp==pHead)
									{
											del->next = ptmp;
											del->prev = ptmp->prev;
											ptmp->prev->next = del;
											ptmp->prev = del;
											pHead->mem_size+=del->mem_size;
											pFead->mem_size-=del->mem_size;
											break;
									}
									if(del->index == ptmp->index)
									{
											ptmp->mem_size+=del->mem_size;
											pHead->mem_size+=del->mem_size;
											pFead->mem_size-=del->mem_size;
											break;
											//free(ptmpf);
									}
    								ptmp = ptmp->next;
 	    						}
								ptmpf = pFead;
								continue;
							}
						
						ptmpf = ptmpf->next;
					}
					return ;
		   }
			ptmpr = ptmpr->next;
		}
		printf("don't find this node!\n");
}
