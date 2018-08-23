#include"search.h"
int Search(pStu phead,int (*pFun_Search[2])(pStu pHead,int num))
{
		int n,m,p;
		while(1)
		{
				printf("please input find way 1-id 2 -age\n");
				scanf("%d",&n);
				while(getchar()!='\n');
				if(n == 1)
				{
						printf("please input id\n");
						scanf("%d",&m);
						(*pFun_Search[n-1])(phead,m);
						break;
				}
				else 
				{
						if( n == 2 )
						{
								printf("printf input num\n");
								scanf("%d",&p);
								(*pFun_Search[n-1])(phead,p);
								break;
						}
						else 
						{
								printf("input errpr please again\n");

						}

				}

		}
}
int Search_id(pStu phead,int num)
{
	int i=0;
	pStu ptmp = phead->next;
	while(ptmp != phead)
	{
		if(ptmp->num == num)
		{
			i++;
			printf("id:%d age:%d\n",ptmp->num,ptmp->age);
		}	
		ptmp =ptmp->next;
	}
	if( i == 0)
	{
		printf("not find people \n");
	}
}
int Search_age(pStu phead,int age)
{
	int i=0;
	pStu ptmp = phead->next;
	while(ptmp != phead)
	{
		if(ptmp->age ==age)
		{
			i++;
			printf("id:%d age:%d\n",ptmp->num,ptmp->age);
		}	
			ptmp = ptmp->next;
	}
	if( i == 0)
	{
		printf("not find people \n");
	}
}
