#include"main.h"
enum yy
{
	Apply=1,
	Free,
	Print,
	Exit
};

void get_memory(void **q,int size)
{
		*q = malloc(size);
		if(*q == NULL)
		{
				printf("malloc error.\n");
				exit(-1);
		}
}
void my_free(void **qq)
{
		if(*qq!=NULL)
		{
				free(*qq);
				*qq = NULL;
		}
}
void creat_fail_chain(pNode pHead,pNode pnew)
{
		pnew->next = pHead;
		pnew->prev = pHead->prev;
		pHead->prev->next = pnew;
		pHead->prev = pnew;
}

void init (pNode *pHead,int size)
{
		get_memory((void **)pHead,size);
		(*pHead)->next = (*pHead);
		(*pHead)->prev = (*pHead);
}
void print(pNode pHead);
void destory1(pNode pHead);
void destory2(pRecord *ppp);
int main()
{
		int i;
		int choose;
		pNode pHead=NULL;
		pNode pnew=NULL;
		init(&pHead,sizeof(sNode));
		init(&free_begin,sizeof(sNode));
		pHead->mem_size = 0;
		for(i=0;i<10;i++)
		{
				init(&pnew,sizeof(sNode));
				creat_fail_chain(pHead,pnew);
				pnew->index = i+1;
				pnew->mem_size = 10;
				pHead->mem_size = pnew->mem_size + pHead->mem_size;
		}
		printf("sum=%d\n",pHead->mem_size);
		while(1)
		{
				printf("请输入你的选择1:申请内存\n2:释放内存\n3:打印申请链表和释放链表\n4:退出\n");
				scanf("%d",&choose);
				switch(choose)
				{
						case Apply:apply(pHead);break;
						case Free:free_(pHead);break;
					 	case Print:print(pHead);break;
				 		case Exit:destory1(pHead);
								   destory2(ppp);
								 // my_free((void **)&pHead);
								exit(0);break;				   
				}
		}
}
void print(pNode pHead)
{
		pNode ptmp=pHead;
		pNode ptmp1 = free_begin;
		pRecord p = ppp[1];
		while(ptmp->next!=pHead)
		{
				printf("pHead->index:%dpHead->size:%d\n",ptmp->next->index,ptmp->next->mem_size);
				ptmp = ptmp->next;
		}
		while(ptmp1->next!=free_begin)
		{
				printf("free_begin->index:%dfree_begin->size:%d\n",ptmp1->next->index,ptmp1->next->mem_size);
				ptmp1 = ptmp1->next;
		}
}
void destory1(pNode pHead)
{
		pNode ptmp = pHead->next;
		while(ptmp!=pHead)
		{
				ptmp->next->prev = pHead;
				pHead->next = ptmp->next;
				my_free((void **)&ptmp);
				ptmp = pHead->next;				
		}
}
void destory2(pRecord *ppp)
{
		int i;
		for(i=0;i<count;i++)
		{
				my_free((void **)ppp+i);
		}
}










