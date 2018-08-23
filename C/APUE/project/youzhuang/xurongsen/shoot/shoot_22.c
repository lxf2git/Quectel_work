#include "shoot_22.h"

void create_memory(void **p, int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}

void init_node(pSot *pshoot)
{
	int len;
	len = sizeof(sSot);
	create_memory((void **)pshoot,len);
	(*pshoot)->next = *pshoot;
}

int insert_back(pSot phead,pSot pnew)
{
	if(NULL==phead || NULL==pnew)
	{
		printf("插入位置与插入不能为空！\n");
		exit(-1);
	}
	pSot ptail;
//	init_node(&ptail);
	ptail=phead;
	pnew->next = ptail->next;
	ptail->next=pnew;
//	ptail=pnew;
//	ptail->next=phead;
}

void init_chain(pSot *pp,int num)
{
	int i;
	pSot pnew,p;
	for(i=1;i<num;i++)
	{
		init_node(&pnew);
		pnew->life=1;
		pnew->id=i+1;
		if(pnew->id == 10)
		{
			p=pnew;
		}
		insert_back(*pp,pnew);
		*pp=pnew;
	}	
	*pp = pnew->next;
}

void delete_node(pSot pos,pSot pout)
{
	pos->next = pout->next;
	pout->next=NULL;
	free(pout);
}

void shoot_down(pSot *pphead,int num,int shoot)
{
	int i,sum=0;
	int len=1;//计算链表的长度
	pSot pnew,p;//,p代表被射杀的id的前一个数的id，pnew代表被射杀的id
	init_node(&pnew);
	pnew = *pphead;
//	pnew->next = (*pphead)->next;

	len = num;
	while(len>1)
	{
		sum = sum+(pnew->life);
		if(sum == shoot-1)
		{
			p=pnew;
//	printf("shoot_down--->befor shoot:%d \n",p->id);
		}
		if(sum == shoot)
		{
			pnew->life = 0;
			delete_node(p,pnew);
			sum=0;
			len--;
			pnew = p->next;
			continue;
		}
//		if((pnew->file==1) && (len==1))
			pnew = pnew->next;
//			printf("shoot_down--->pnew->id:%d\n",pnew->id);
	}
	(*pphead)=p;
}

void show(pSot phead)
{
		if(phead->life == 1)
		{
			printf("活着的人的id是%d \n",phead->id);
		}
}

void choose_type(pSot *pphead,int num,int shoot)
{
	int chos;
	printf("please choose type:(1:初始化2:射击3:打印4:退出)");
	scanf("%d",&chos);
	do{
	switch(chos)
	{
		case INPUT:{
					init_chain(pphead,num);
					break;
				   }
		case SHOOT:{
					shoot_down(pphead,num,shoot);
					break;
				   }
		case PRINT:{
					show(*pphead);
					break;
				   }
		case QUIT:{
					break;
				  }
		default:{
					printf("input error!\n");
	//				choose_type(pphead,num,shoot);
				}
	}
	}while( printf("please input again(1:初始化2:射击3:打印4:退出)")
					&&scanf("%d",&chos)&& chos !=4);	
}

void choose(pSot *pphead)
{
	int num,shoot,chos;
	printf("please input number of people,shoot:");
	scanf("%d%d",&num,&shoot);

	choose_type(pphead,num,shoot);
}

int main()
{
	pSot phead=NULL;
	init_node(&phead);
	phead->life=1;
	phead->id=1;
	choose(&phead);
	return 0;
}
