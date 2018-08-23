#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
		int data;
		struct data *prev;
		struct data *next;
}sd,*pd;
typedef struct and
{
		struct data *and[8];
}sa,*pa;
typedef struct mod
{
		struct and *mod[5];
}sm,*pm;
void create_memory1(pd *p)
{
		*p=(pd)malloc(sizeof(sd));
		//		printf("-----------\n");
		if(*p==NULL)
		{
				printf("malloc error");
				exit(-1);
		}
		(*p)->next=*p;
		(*p)->prev=*p;
}
void create_memory2(pa *p)
{
		int i;
		*p=(pa)malloc(sizeof(sa));
		for(i=0;i<8;i++)
		{
				create_memory1(&((*p)->and[i]));
		}
		if(*p==NULL)
		{
				printf("malloc error");
				exit(-1);
		}
}
void create_memory3(pm *p)
{
		int i;
		*p=(pm)malloc(sizeof(sm));
		for(i=0;i<5;i++)
		{
				create_memory2(&((*p)->mod[i]));
		}

		if(*p==NULL)
		{
				printf("malloc error");
				exit(-1);
		}
}
void init_pnew(pm *pnew)
{
		create_memory3(pnew);
}
void create_biao(pm pHead,int a)
{
		pm pnew=NULL;
		init_pnew(&pnew);
		pnew->mod[a%5]->and[a>>3&7]->data=a;
		
	
				
		pnew->mod[a%5]->and[a>>3&7]->prev=pHead->mod[a%5]->and[a>>3&7]->prev;
		pHead->mod[a%5]->and[a>>3&7]->prev->next=pnew->mod[a%5]->and[a>>3&7];
		pHead->mod[a%5]->and[a>>3&7]->prev=pnew->mod[a%5]->and[a>>3&7];
		pnew->mod[a%5]->and[a>>3&7]->next=pHead->mod[a%5]->and[a>>3&7];

		
		
}
void find(pm pHead,int a)
{
		pd ptmp=NULL;
		for(ptmp=pHead->mod[a%5]->and[a>>3&7]->next;ptmp!=pHead->mod[a%5]->and[a>>3&7];ptmp=ptmp->next)
		{
				if(ptmp->data==a)
				printf("%d ",ptmp->data);
		}
		printf("\n");
}
int main()
{
		int a,i,b;
		pm pHead=NULL;
		init_pnew(&pHead);
		for(;;)
		{
		printf("1输入,2查找,3退出\n");
		scanf("%d",&a);
		switch (a)
		{
				case 1:
						for(i=0;i<100;i++)
						{
								create_biao(pHead,i);
						}
						break;
				case 2:
						printf("输入寻找的数据");
						scanf("%d",&b);
						find(pHead,b);
						break;
				case 3:
						break;
		}
		if(a==3)
			break;
		}
}
