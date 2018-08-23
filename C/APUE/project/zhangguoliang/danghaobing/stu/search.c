#include"search.h"

int Fun_Searchi(pStu pHead,int num)
{
		pStu pTra = pHead->next;
		int count=0;
		printf("the same:\n");
		while(pTra!=NULL)
		{
				if(pTra->num==num)
				{
						printf("id:%d age:%d\n",pTra->num,pTra->age);
						count++;
				}
				pTra = pTra->next;
		}
		if(count==0)
		printf("not found!\n");
		return 0;
}

int Fun_Searcha(pStu pHead,int num)
{
		pStu pTra = pHead->next;
		int count=0;
		printf("the same:\n");
		while(pTra!=NULL)
		{
				if(pTra->age==num)
				{
						printf("id:%d age:%d\n",pTra->num,pTra->age);
						count++;
				}
				pTra = pTra->next;
		}
		if(count==0)
		printf("not found!\n");
		return 0;
}

int Search(pStu pHead,int (*pFun_Search[2])(pStu pHead,int num))
{
		int x,num;
		while(1)
		{
			printf("1 search id\n2 search age\n3 return\n");
			scanf("%d",&x);
			switch(x)
			{
					case 1:
					case 2:
							printf("please input id or age\n");
							scanf("%d",&num);
							pFun_Search[x](pHead,num);
							break;
					case 3:
							return 0;
					default:
							printf("input error! please input again!\n");
							break;
			}
		}
}
