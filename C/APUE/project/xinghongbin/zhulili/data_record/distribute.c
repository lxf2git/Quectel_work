#include"distribute.h"

void distribute(pNode pHead_N, pDis pHead_D, int i,int num)
{
	int figure;
	pNode pdel = NULL;	
	pNode pnode = NULL;
	pNode ptmp = NULL;
	pNode pp = NULL;
	pDis ptmp_D = NULL;
	pNode p = NULL;
	pDis pdis = NULL;
	int a,n=1;
	int k;
		for(ptmp=pHead_N->prev;ptmp!=pHead_N;ptmp=pp)//双链表 
		{
				a = ptmp->data;
				if(i == 1)					
					a = a%10;
				else if( i == num)
				{
					for(k=0;k<num-1;k++)
					{
						n = n*10;
					}
					a = a/n;
				}
				else
				{
					for(k=0;k<i-1;k++)
					{
						n = n*10;
					}
					a = a/n%10;
				}
				n=1; 			
				for(ptmp_D=pHead_D->next;ptmp_D!=pHead_D;ptmp_D=ptmp_D->next)//单链表	
				{				
					if(ptmp_D->record->data == a)
					{
					
						//有相同的就把那个数尾删
						pdel  = NULL;
						pdel = pHead_N->prev;
						pp = ptmp->prev;
						ptmp->prev->next = pHead_N;
						pHead_N->prev = ptmp->prev;	
					
						//挂到相应的单链表下面       
						pnode = ptmp_D->record;  
						pnode->prev->next = ptmp;
						ptmp->prev = pnode->prev;
						pnode->prev = ptmp;
						ptmp->next = pnode;							
						break;  
					}					
				}
		}				
}







