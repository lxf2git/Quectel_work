#include"search.h"

int Fun_search_id(pStu pHead,int id)
{
	int r=0;
	pStu ptmp;
	for(ptmp=pHead->next;ptmp!=NULL;)
	{
		if(id==ptmp->num)
		{
			printf("==ID-af:%d Age:%d==\n",ptmp->num,ptmp->age);
			r=1;
		}
		ptmp=ptmp->next;
	}
	return r;
}

int Fun_search_age(pStu pHead,int age)
{
	int r=0;
	pStu ptmp;
	for(ptmp=pHead->next;ptmp!=NULL;)
	{
		if(age==ptmp->age)
		{
			printf("==ID:%d Age:%d==\n",ptmp->num,ptmp->age);
			r=1;
		}
		ptmp=ptmp->next;
	}
	return r;	
	
}
int search(pStu pHead,int (*pFun_Search[2])(pStu pHead,int num))
{
	int num,r;
	printf("please input data to search!\n");
	scanf("%d",&num);
	r=(*pFun_Search)(pHead,num);

	if(r==0)
	{
		printf("search null!\n");
	}
}

void s_search(pStu pHead)
{
	pList p_list;
	printf("please choose search for 1:ID or 2:Age? o_O\n");
	int i;
	scanf("%d",&i);	
	if(1==i||2==i)
	{
	int (*Fun_search[2])(pStu pHead,int num)={Fun_search_id,Fun_search_age};
	p_list->pSearch=search;
	p_list->pSearch(pHead,&Fun_search[i-1]);
	}
	else 
	{
		printf("choose error!\n");
		return ;
	}

}
