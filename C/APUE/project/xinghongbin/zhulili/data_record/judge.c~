#include"judge.h"

int judge_num(pNode pHead_N,int n)
{
/**/	int i;
	int k=0;
	pNode ptmp = pHead_N->next->next;
	pNode pnode = pHead_N->next;
	int a;
	while(1)
	{	
		if(pnode->data  <  ptmp->data)
		{			
			pnode = pnode->next;
			if(pnode == pHead_N)
			{
				//printf("最大值为:%d\n",ptmp->data);
				a = ptmp->data;
				while(a != 0)
				{
					a = a/10;
					k+=1;
				}
				//printf("最大值的位数是:%d位\n",k);
				break;
			}
		}
		if(pnode->data > ptmp->data)
		{
			 ptmp = ptmp->next;
			if(ptmp == pHead_N)
			{
				//printf("最大值为:%d\n",pnode->data);
				a = pnode->data;
				while(a != 0)
				{					
						a = a/10;
						k+=1;							
				}
				//printf("最大值的位数是%d位\n",k);							
				break;
			}
		}				
		if(pnode->data == ptmp->data)
		{
			ptmp = ptmp->next;
			if(ptmp == pHead_N)
			{
				//printf("最大值为:%d\n",pnode->data);
				if(pnode->data == 0)
				{
					//printf("最大值的位数是1位\n");
					k=1;
					break;
				}				
				a = pnode->data;
				while(a != 0)
				{					
					a = a/10;
					k+=1;					
				}
				//printf("最大值的位数是%d位\n",k);									
				break;
			}
		}	
	}	
	return k;	
}
