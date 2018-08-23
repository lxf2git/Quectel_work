#include"main.h"
void destory(pNode ptmp)
{
		ptmp->prev->next = ptmp->next;
		ptmp->next->prev = ptmp->prev;
		ptmp->next = ptmp;
		ptmp->prev = ptmp;
}
create_head_chain(pNode pHead,pNode ptmp)
{
		ptmp->next = pHead->next;
		ptmp->prev = pHead;
		pHead->next->prev = ptmp;
		pHead->next = ptmp;
}
/*void prrr(pNode pHead)
{
		pNode ptmp=pHead;
		while(ptmp->next!=pHead)
		{
				printf("index:%d size:%d\n",ptmp->next->index,ptmp->next->mem_size);
				ptmp = ptmp->next;
		}
		printf("**************\n");

}*/
int free_(pNode pHead)
{
		int i; 
		pNode pswp=pHead;
		printf("请输入要归还第几次申请的空间\n");
		scanf("%d",&i);
		if(i>count)
		{
				printf("输入错误.\n");
				return -1;
		}
		pRecord ptmp = ppp[i-1];
		while(ptmp->next!=ppp[i-1])
		{
				while(pswp->next!=pHead)
				{
					if((ptmp->next->pdata->index) < pswp->next->index)
					{		
							destory(ptmp->next->pdata);
							create_head_chain(pswp,ptmp->next->pdata);
							break;
					}
					if(ptmp->next->pdata->index == pswp->next->index)
					{
							pswp->next->mem_size = 10;
							destory(ptmp->next->pdata);
							my_free((void **)&ptmp->next->pdata);
							break;
					}
					pswp = pswp->next;
				}
				pswp = pHead;
				ptmp = ptmp->next;
		}
}
