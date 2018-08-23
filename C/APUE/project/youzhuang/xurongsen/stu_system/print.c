#include"main_st.h"
#include"print.h"


void print(pStu phead)
{

	pStu p=NULL;
	p=phead;
	while(p != NULL)
	{
		p = p->next;
		if(NULL == p)
		{
			break;
		}
		printf("链表中的数是：id:%d age:%d \n",p->num,p->age);
	}
}
