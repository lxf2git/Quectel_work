#include<stdio.h>
#include<string.h>
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
void show_chain(pNode pHead);
void create_memory_small(pDisChain *p2,int size)
{
	*p2=(pDisChain)malloc(sizeof(sDisChain));
	if(NULL==*p2)
	{
		printf("create error!\n");
	}
	(*p2)->next=*p2;
}
void create_memory(pNode *p1,int size)
{
	*p1=(pNode)malloc(sizeof(size));
	if(NULL==*p1)
	{
		printf("create error!\n");
		exit(-1);
	}
	(*p1)->next=*p1;
	(*p1)->prev=*p1;
}

void link_node(pNode pHead,pNode ptmp,pNode pnew)
{
	pnew->next=pHead;
	pHead->prev=pnew;
	pnew->prev=ptmp;
	ptmp->next=pnew;
}
void link_node2(pDisChain phead,pNode p_cut,pNode p_pos,pDisChain p3)
{
	/*int u=0;
	pDisChain p4=phead->next;
	while(p4!=phead)
	{
		if(u==t)
		{*/
		p_cut->next=p3->record;
		(p3->record)->prev=p_cut;
		p_cut->prev=p_pos;
		p_pos->next=p_cut;
		//printf("*%d",(tar->record)->data);
	/*p1->next=(p4->record)->next;
	(p4->record)->prev=p1;
	p1->prev=p4->record;
	(p4->record)->next=p1;
		}
	p4=p4->next;
	u=u+1;
	}*/
}
int judge_num(pNode pHead)
{
	int num=0;
	int i;
	int max=0;
	pNode p2=pHead->next;
	while(p2!=pHead)
	{
		if(max<(p2->data))
		{
			max=p2->data;
				printf("*%d",max);
		}
		p2=p2->next;
	}
	for(i=0;;i++)
	{	
		num=num+1;
		max=max/10;
		if(max<10&&max>0)
		{
			num=num+1;
			return num;
		}
		else 
		if(max==0)
		{
			return num;	
		}
		
	}
}

void cut_node(pNode pHead,pNode p_cut)
{
	pHead->next=p_cut->next;
	(p_cut->next)->prev=pHead;
	p_cut->next=NULL;
	p_cut->prev=NULL;
		
}

void link_node_small(pDisChain phead,pDisChain pr,pDisChain pNew)
{
	pNew->next=phead;
	pr->next=pNew;
	

}
void show_chain2(pDisChain phead)
{
	pDisChain ptmp=phead->next;
	pNode ptm;
	while(ptmp!=phead)
	{
		ptm=(ptmp->record)->next;
		while(ptm!=ptmp->record)
		{
		printf("@%d ",ptm->data);
			ptm=ptm->next;
		printf("\n");
		}
		printf("\n");
		ptmp=ptmp->next;
	}
}


void distribute(pNode pHead,pDisChain phead,int n)  
{
	int t=0,j=0;
	int m=n/10;
	int p1_data;
	pNode p_pos;
	pNode p_cut=pHead->next;
	pDisChain p3=phead->next;
	pDisChain p3_next;
	while(p_cut!=pHead)
	{
		t=(p_cut->data)%n/m;
		printf("=%d",t);
		cut_node(pHead,p_cut);
		while(p3!=phead)
		{
			if(t==0)
			{
				p_pos=(p3->record)->next;
				while(p_pos->next!=p3->record)
				{
					p_pos=p_pos->next;
				}
			link_node2(phead,p_cut,p_pos,p3);		
			}
			t--;
			p3=p3->next;
		}
			
		p3=phead->next;
		p_cut=pHead->next;
	}

	
	
	
}

void collected(pDisChain phead,pNode pHead)
{
	pDisChain p5=phead->next;
	pNode ptu;
	pNode p_next;
	pNode pto=pHead;
	while(p5!=phead)
	{
		ptu=p5->record->next;
		while(ptu!=p5->record)
		{
			
			p_next=ptu->next;
			cut_node(p5->record,ptu);
			//printf("%d",ptu->data);
			link_node(pHead,pto,ptu);
			pto=pto->next;	
			ptu=p_next;
		}
		p5=p5->next;
	}
	
}
void sort_node(pNode pHead,int num)
{
	int i,j,n=10;
	pDisChain phead=NULL;
	create_memory_small(&phead,sizeof(sDisChain));
	pDisChain pr=phead;
	pDisChain pNew=NULL;
	for(j=0;j<10;j++)
	{
		create_memory_small(&pNew,sizeof(sDisChain));
		create_memory(&(pNew->record),sizeof(sNode));
		link_node_small(phead,pr,pNew);
		pr=pNew;
		//printf("%d",phead->record->data);
	}
	for(i=1;i<=num;i++)
	{
		distribute(pHead,phead,n);
		printf("\n");
		show_chain2(phead);
		collected(phead,pHead);
		show_chain(pHead);
		printf("\n");
		n=n*10;
		//printf("*%d",phead->record->data);
		//collected(phead);
	}
}



void insert_chain(pNode pHead)
{
	int i;
	pNode pnew=NULL;
	pNode ptmp=pHead;
	for(i=0;i<5;i++)
	{
	create_memory(&pnew,sizeof(sNode));
	printf("please input chain:\n");
	scanf("%d",&pnew->data);
	ptmp=ptmp->next;
	link_node(pHead,ptmp,pnew);
	}
}

void show_chain(pNode pHead)
{
	 pNode ptmp=pHead->next;
	while(ptmp!=pHead)
	{
		printf("%d ",ptmp->data);
		ptmp=ptmp->next;
	}
}
int main()
{
	int num;
	pNode pHead=NULL;
	create_memory(&pHead,sizeof(sNode));
	insert_chain(pHead);
	num=judge_num(pHead);
	printf("==%d\n",num);
	sort_node(pHead,num);
	//show_chain(pHead);
}

