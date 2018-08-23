#include<stdio.h>
#include<stdlib.h>

#define M 10


typedef struct Data
{
	int data;
	struct Data *prev;
	struct Data *next;
}sDa,*pDa;

typedef struct dis_chain
{
	int num;
	pDa record;
	struct dis_chain *next;
}sDis,*pDis;

void init_node_data(pDa *p,int size);
void init_node_dis(pDis *p,int size);
void creat_memory(void **p,int size);
void creat_chain_data(pDa phead,int n);
void creat_chain_dis(pDis phead_dis);
void show(pDa phead);
//void show_(pDis phead);
int  insert_(pDa p1,pDa p2);
int  judge_num(pDa phead);
void change(pDa phead, pDis phead_dis, int count);
void distribute(pDa phead,pDis phead_dis,int x);
void collected(pDa phead,pDis phead_dis);
pDa  delete_(pDa p);
int	 count_num(int x,int y);
void destory(pDa *phead);
void destory_dis(pDis *phead_dis);
void i_free(void **p);

int main()
{
	int num;
	pDa phead=NULL;
	pDis phead_dis=NULL;
	init_node_data(&phead,sizeof(sDa));
	init_node_dis(&phead_dis,sizeof(sDis));
	printf("请输入要排序的数目\n");
	scanf("%d",&num);
	creat_chain_dis(phead_dis);
	creat_chain_data(phead,num);
	int n=judge_num(phead);
	//printf("max:%d",n);
	change(phead,phead_dis,n);
	show(phead);
	destory(&phead);
	destory_dis(&phead_dis);
	//show_(phead_dis);
	return 0;
}

void init_node_data(pDa *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->prev=*p;
	(*p)->next=*p;
}

void init_node_dis(pDis *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->next=NULL;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void creat_chain_data(pDa phead, int n)
{
	int i;
	pDa pnew=NULL;
	for(i=0;i<n;i++)
	{
		init_node_data(&pnew,sizeof(sDa));
		printf("请输入数据\n");
		scanf("%d",&pnew->data);
		insert_(phead,pnew);
	}
}

void creat_chain_dis(pDis phead_dis)
{
	int i;
	pDis pnew=NULL;
	pDis ptail=phead_dis;
	for(i=0;i<M;i++)
	{
		init_node_dis(&pnew,sizeof(pnew));
		init_node_data(&pnew->record,sizeof(sDa));
		pnew->num=i;
		pnew->next=ptail->next;
		ptail->next=pnew;
		ptail=pnew;
	}
}

int insert_(pDa p1,pDa p2)
{
	if(p1==NULL||p2==NULL)
	{
		return -1;
	}
	p2->next=p1;
	p2->prev=p1->prev;
	p1->prev->next=p2;
	p1->prev=p2;
	return 0;
}

void show(pDa phead)
{
	pDa p=NULL;
	for(p=phead->next;p!=phead;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}

void show_(pDis phead)
{
	pDis p=NULL;
	printf("2：");
	for(p=phead->next;p!=NULL;p=p->next)
	{
		printf("%d ",p->num);
	}
	printf("\n");
}

int judge_num(pDa phead)
{
	pDa p=NULL;
	int max=0;
	for(p=phead->next;p!=phead;p=p->next)
	{
		if(max<count(p->data))
		{
			max=count(p->data);
		}
	}
	return max;
}

int count(int x)
{
	int i;
	for(i=1;;i++)
	{
		x=x/10;
		if(x==0)
		{
			break;
		}
	}
	return i;
}

void change(pDa phead, pDis phead_dis, int count)
{
	int i;
	for(i=1;i<=count;i++)
	{
		distribute(phead,phead_dis,i);
		collected(phead,phead_dis);
	}
}

void distribute(pDa phead,pDis phead_dis,int x)
{
	pDa p=NULL;
	pDis pd=NULL;
	pDa p1=NULL;
	for(pd=phead_dis->next;pd!=NULL;pd=pd->next)
	{
		for(p=phead->prev;p!=phead;p=p->prev)
		{
			if(count_num(p->data,x)==pd->num)
			{
				p=p->prev;
				p1=delete_(p);
				insert_(pd->record,p1);
				p=p->next;
			}
		}
	}
}

int count_num(int x,int y)
{
	int i;
	int t=0;
	for(i=0;i<y;i++)
	{
		t=x%10;
		x=x/10;
	}
	return t;
}

pDa delete_(pDa p)
{
	pDa ptmp=NULL; 
	ptmp=p->next;
	p->next=ptmp->next;
	ptmp->next->prev=p;
	ptmp->prev=ptmp;
	ptmp->next=ptmp;
	return ptmp;
}

void collected(pDa phead,pDis phead_dis)
{
	pDis pd=NULL;
	pDa p=NULL;
	pDa p1=NULL;
	for(pd=phead_dis->next;pd!=NULL;pd=pd->next)
	{
		for(p=pd->record->prev;p!=pd->record;p=p->prev)
		{
			p=p->prev;
			p1=delete_(p);
			insert_(phead,p1);
			p=p->next;	
		}
	}
}

void i_free(void **p)
{
	if(*p=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void destory(pDa *phead)
{
	pDa pdel=NULL;
	while((*phead)->next!=*phead)
	{
		pdel=delete_(*phead);
		i_free((void **)&pdel);
	}
	i_free((void **)phead);
}

void destory_dis(pDis *phead_dis)
{
	pDis pdel=NULL;
	while((*phead_dis)->next=NULL)
	{
		pdel=(*phead_dis)->next;
		pdel->next=(*phead_dis)->next;
		pdel->next=NULL;
		i_free((void **)&(pdel->record));
		i_free((void **)&pdel);
	}
	i_free((void **)phead_dis);
}
