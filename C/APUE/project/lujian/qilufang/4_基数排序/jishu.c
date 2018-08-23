/***************;;;**********************
  作业：基数排序

  0     1   2     3    4          5   6   7          8       9
  800     111    893  234         045                 108    219 
  120 
  080

  typedef struct node
  {
  int data;
  struct node *prev;
  struct node *next;
  }sNode,*pNode;

  typedef struct dis_chain
  {
  pNode record;

  struct dis_chain*nex()
  }sDisChain,*pDisChain;

  num = judge_num();
  for(i<num)
  {
  distribute();
  collected();	
}

 *
 * ****************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 10
typedef struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
}sNode,*pNode;
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
void init_chain(pNode *p,int size)
{
	getmemory((void **)p,size);
	(*p)->next=(*p);
	(*p)->prev=(*p);
}

int weishu(pNode pnew)
{
	int nb,i=1;
	int new=pnew->data;
	while(new/10 != 0)
	{
		i++;
		new=new/10;
		nb=i;
	}
	return nb;
}
void output(pNode pHead)
{
	pNode ptmp=NULL;
	for(ptmp=pHead->next;ptmp != pHead;ptmp=ptmp->next)
	{
		printf("%d\n",ptmp->data);
	}
}
void chain_head(pNode pHead,pNode pnew)//双连头差
{
		pHead->next->prev=pnew;
		pnew->prev=pHead;
		pnew->next=pHead->next;
		pHead->next=pnew;
}
void chain_head_sing(pNode pHead,pNode pnew)
{
	pnew->next=pHead->next;
	pHead->next=pnew;
}
void sing_prev(pNode pHead,pNode pnew)
{
	pnew->prev=pHead->prev;
	pHead->prev=pnew;
}
int creat_chain(pNode pHead)
{
	int i,nb_1=0,nb_2=0;
	pNode pnew=NULL;
	printf("请输入%d个数：\n",N);
	for(i=0;i<N;i++)
	{
		init_chain(&pnew,sizeof(sNode));
		scanf("%d",&pnew->data);
		nb_1=weishu(pnew);
		if(nb_1>nb_2)
		{
			nb_2=nb_1;
		}
		chain_head(pHead,pnew);
	}
	return nb_2;
}
void creat_chain_dis(pNode pHead_dis)
{
	int i;
	pNode pnew=NULL;
	for(i=0;i<10;i++)
	{
		init_chain(&pnew,sizeof(sNode));
		pnew->data=i;
		chain_head_sing(pHead_dis,pnew);
	}
}
int gol(int nb,double k)
{
	int re=0;
	re=((nb/((int)pow(10,k)))%10);
	return re;
}
void distribute(pNode pHead,pNode pHead_dis,double k)
{
	int ret=0;
	pNode pnew=NULL;
	pNode ptmp_1;
	pNode ptmp_2;
	for(ptmp_1=pHead_dis->next;ptmp_1 != pHead_dis;ptmp_1=ptmp_1->next)
		for(ptmp_2=pHead->next;ptmp_2 != pHead;ptmp_2=ptmp_2->next)
		{
			ret=gol(ptmp_2->data,k);
			if(ptmp_1->data==ret)
			{
				init_chain(&pnew,sizeof(sNode));
				pnew->data=ptmp_2->data;
				sing_prev(ptmp_1,pnew);
			}
		}
}
void dele(pNode pdel)
{
	if(pdel!=NULL)
	{
		pdel->prev=pdel;
		pdel->next=pdel;
		free(pdel);
		pdel=NULL;
	}
}
void destory(pNode *pHead_dis)
{
	pNode pdel;
	pNode ptmp_1;
	pNode ptmp_2;
	for(ptmp_1=(*pHead_dis)->next;ptmp_1 != (*pHead_dis);
					ptmp_1=ptmp_1->next)	
	{
		ptmp_2=ptmp_1->prev;
		while(ptmp_2 != ptmp_1)
		{
			pdel=ptmp_2;
			ptmp_2->prev=pdel->prev;
			ptmp_2=ptmp_2->prev;
			dele(pdel);
		}
		ptmp_1->prev=ptmp_1;
	}

}
void collected(pNode pHead,pNode pHead_dis)
{
	pNode ptmp_1;
	pNode ptmp_2;
	pNode ptmp_3=pHead->next;
	for(ptmp_1=pHead_dis->next;ptmp_1 != pHead_dis;ptmp_1=ptmp_1->next)	
	{
			for(ptmp_2=ptmp_1->prev;ptmp_2 != ptmp_1&&
							ptmp_3 != pHead;ptmp_2=ptmp_2->prev)
			{
				ptmp_3->data=ptmp_2->data;
				ptmp_3=ptmp_3->next;
			}
	}
	destory(&pHead_dis);
}
int main()
{
	double i;
	int nb_max=0;
	pNode pHead=NULL;
	pNode pHead_dis=NULL;
	init_chain(&pHead,sizeof(sNode));
	init_chain(&pHead_dis,sizeof(sNode));
	creat_chain_dis(pHead_dis);
	nb_max=creat_chain(pHead);
	for(i=0;i<nb_max;i++)
	{
		distribute(pHead,pHead_dis,i);
		collected(pHead,pHead_dis);
	}
	printf("Output after deal:\n");
	output(pHead);
	return 0;
}
