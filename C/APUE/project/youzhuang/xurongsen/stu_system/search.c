#include"search.h"
#include"main_st.h"

int search(pStu phead,int (*pfun_sear[2])(pStu phead,int num))
{
	int id,age,ret,num;
	printf("please choose search type:(1:age 2:id):");
	scanf("%d",&num);
	if(num == 1)
	{
		pfun_sear[0] = sear_age;
		ret = pfun_sear[0](phead,num);
		return ret;
	}
	if(num == 2)
	{
		pfun_sear[1] = sear_id;
		ret = pfun_sear[1](phead,num);
		return ret;
	}
}

int sear_age(pStu phead,int num)
{
	
	pStu p=NULL;
		int age;
		printf("please input search age:");
		scanf("%d",&age);
	p=phead;
	while(p != NULL)
	{
			p = p->next;
		if(NULL == p)
		{
			printf("no find!\n");
			return FAILED;
		}
		if(age == p->age)
		{
			printf("链表中的数是：id:%d age:%d \n",p->num,p->age);
		}
	}
	return SUC;
}

int sear_id(pStu phead, int num)
{
	int id;
	pStu p=NULL;
		printf("please input search id:");
		scanf("%d",&id);
	p=phead;
	while(p != NULL)
	{
		p = p->next;
		if(NULL == p)
		{
			printf("no find!\n");
			return FAILED;
		}
		if(id == p->num)
		{
			printf("链表中的数是：id:%d age:%d \n",p->num,p->age);
			break;
		}
	}
	return SUC;
}
