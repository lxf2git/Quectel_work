#include"search.h"
int (*pSearch)(pStu pHead,int(*pFun_Search[2])(pStu pHead, int num));

int find_age1(pStu pHead,int num)
{
	pStu p1 = NULL;	
	for(p1=pHead;p1->next!=NULL;p1=p1->next)
	{
		if(p1->next->age == num)					
		printf("%d %d\n",p1->next->id,p1->next->age);	
		break;	
	}	
}

int find_id1(pStu pHead,int num)
{
	pStu p2 = pHead;	
	while(p2->next!=NULL)
	{
		if(p2->next->id == num)
		{				
			printf("%d %d\n",p2->next->id,p2->next->age);	
			break;
		}
		p2 = p2->next;		
	}	
}	

int find(pStu pHead,int(*pFun_Search[2])(pStu pHead, int num))
{
	int a,in_age,in_id;	
	scanf("%d",&a);
	switch(a) 
	{	
			case 1:
					printf("input age\n");
					scanf("%d",&in_age);
					pFun_Search[0] = find_age1;
    				find_age1(pHead,in_age);	
					break;
			case 2:
					printf("input id\n");
					scanf("%d",&in_id);	
					pFun_Search[1] = find_id1;
					find_id1(pHead,in_age);
					break;
	}
}
