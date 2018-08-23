#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}sNode,*pNode;

typedef struct dis_chain
{
	pNode record;
	struct dis_chain *next;
}sDisChain,*pDisChain;

void creat_momery(pNode *p,int size)
{
	*p = (pNode)malloc(size);
	if(NULL == *p)
	{
		printf("malloc error\n");
		exit(-1);
	}
	(*p)->next = (*p);
	(*p)->prev = (*p);
}


void input(pNode pHead)
{
	pNode pnew;
	printf("请输入数据   输入0退出\n");
	do
	{
		creat_momery(&pnew,sizeof(sNode));
		pHead->prev->next = pnew;
		pnew->prev = pHead->prev;
		pHead->prev = pnew;
		pnew->next = pHead;
		scanf("%d",&pnew->data);
	}while(pnew->data != 0);
	pnew->prev = pHead;
	pHead->prev = pnew->prev;
	pnew->prev = pnew;
	pnew->next = pnew;
	free(pnew);
	pnew = NULL;
	printf("输入完毕\n");

}

void jugg_num(pNode pHead,int *num)
{
		printf("**************************\n");
		pNode ptmp;
		printf("**************************\n");
		*num=1;
		printf("**************************\n");
		printf("num=%d",(*num));
		for(ptmp=pHead;ptmp->next!=pHead;ptmp=ptmp->next)
		{
				while(ptmp->next->data/10!=0)
				{
					*num++;
					ptmp->next->data = ptmp->next->data/10;
				}
		}
}

void jishu(pDisChain p_dis)
{
	int i;
	pDisChain ptmp = p_dis;
	pDisChain pnew;
	for(i=0;i<9;i++)
	{
		creat_momery(&ptmp->record,sizeof(sNode));
		ptmp->next = pnew;
		ptmp = ptmp->next;
	}
	
}

void list(pNode ptmp,pDisChain pdata)
{
	ptmp->prev->next = ptmp->next;
	ptmp->next->prev = ptmp->prev;

	pdata->record->next->prev = ptmp;  //头差
	ptmp->prev = pdata->record;
	ptmp->next = pdata->record->next;
	pdata->record->next = ptmp;

}


void distribute(pNode pHead,pDisChain p_dis,int num,int j)
{
	pNode ptmp = pHead;
	pNode pnew;
	pDisChain pdata = p_dis;
	int i;
	for(ptmp=pHead;ptmp->next!=pHead;ptmp=ptmp->next)
	{
		while(num > 0)
		{
			ptmp->next->data = ptmp->next->data/10;
			num--;
		}
		if(ptmp->next->data%10 == j)
		{
			list(ptmp->next,pdata);
		}
	}
}

void collected(pNode pHead,pDisChain p_dis)
{
	int i;
	pNode ptmp,pbmp;
	pDisChain pdata = p_dis;
	for(i=0;i<10;i++)
	{
	    ptmp = pdata->record;
		while(ptmp->next!=pdata->record)     
		{
			pbmp = ptmp->next;
			pbmp->next->prev = pbmp->prev;    //头拆
			pbmp->prev->next = pbmp->next;

			pbmp->prev = pHead->prev;    //头差
			pHead->prev->next = pbmp;
			pHead->prev = pbmp;
			pbmp->next = pHead;
		}
	}
	
}

void fun(pNode pHead,pDisChain p_dis,int num)
{
	int i,j;
	pNode ptmp = pHead;
	for(j=0;j<num;j++)
	{
			for(i=0;i<10;i++)
		{
			distribute(ptmp,p_dis,j,i);
			collected(ptmp,p_dis);	

		}
	}
	
}

void show_time(pNode pHead)
{
	pNode ptmp;
	for(ptmp=pHead;ptmp->next!=pHead;ptmp=ptmp->next)
	{
		printf("%d   ",ptmp->next->data);
	}
	printf("\n");
}


int main()
{
	int num;
	pDisChain p_dis;
	pNode pHead;
	creat_momery(&pHead,sizeof(sNode));
	input(pHead);
	jugg_num(pHead,&num);
	printf("num=%d\n",num);
	jishu(p_dis);
	fun(pHead,p_dis,num);
	show_time(pHead);
	return 0;
}
