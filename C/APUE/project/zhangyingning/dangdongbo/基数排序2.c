#include<stdio.h>
#include<stdlib.h>
typedef struct shu
{
		int a;
		struct shu *prev;
		struct shu *next;
}ss,*ps;
typedef struct dis_chain
{
		ps record;
		int b;
		struct dis_chain *prev;
		struct dis_chain *next;
}sd,*pd;
void creat1(ps *p)
{
		*p=(ps)malloc(sizeof(ss));
		if(NULL==*p)
		{
				printf("malloc error");
				exit(-1);
		}
}
void init1(ps *p)
{
		creat1(p);
		(*p)->next=*p;
		(*p)->prev=*p;
}
int chain1(ps phead,int num)
{
		int i,t=1,l,max=0;
		ps pnew=NULL;
		for(i=0;i<num;i++)
		{
				init1(&pnew);
				scanf("%d",&pnew->a);
				l=pnew->a;
				while(l/10!=0)
				{
					l=l/10;
					t++;
				}
			//	printf("%d\n",t);

		if(max<t)
		{
				max=t;
		}
		t=1;
				phead->next->prev=pnew;
				pnew->prev=phead;
				pnew->next=phead->next;
				phead->next=pnew;
		}
			//	printf("%d\n",max);
			return max;
}
void show1(ps phead)
{
		ps ptmp=NULL;
		printf("结果为\n");
		for(ptmp=phead->next;ptmp!=phead;ptmp=ptmp->next)
		{
				printf("%d ",ptmp->a);
		}
		printf("\n");
}
void creat2(pd *p)
{
		*p=(pd)malloc(sizeof(sd));
		if(NULL==*p)
		{
				printf("malloc error");
				exit(-1);
		}
}
void init2(pd *p)
{
		creat2(p);
		(*p)->next=*p;
		(*p)->prev=*p;
}
void chain2(pd phead)
{
		int i;
		pd pnew=NULL;
		
		for(i=9;i>=0;i--)
		{
				init2(&pnew);
				pnew->b=i;
				init1(&pnew->record);
				phead->next->prev=pnew;
				pnew->prev=phead;
				pnew->next=phead->next;
				phead->next=pnew;
		}
}
void show2(pd phead)
{
		pd ptmp=NULL;
		pd pl=NULL;
		int n;
		for(ptmp=phead->next;ptmp!=phead;ptmp=ptmp->next)
		{
				printf("%d ",ptmp->b);
	//			for(pl=ptmp->record->next;pl!=phead->record;pl=pl->next)
				printf("%d ",ptmp->record->next->a);
				printf("%d \n",ptmp->record->next->next->a);
		}
		printf("\n");
}
void distribute(ps phead1,int s,pd phead2,int d)
{
	
		ps ptmp=phead1->prev;
		pd ptm=phead2->next;
		ps pt;
		int i,m,c,k,g;
	//	for(ptmp=phead1->prev;ptmp!=phead1;ptmp=ptmp->prev)
		for(k=0;k<d;k++)
		{
				
				m=ptmp->a;
				ptmp->prev->next=phead1;
				phead1->prev=ptmp->prev;
				ptmp->next=ptmp;
				ptmp->prev=ptmp;
				printf("%d",ptmp->a);
			//	printf("3\n");
		for(i=0;i<s;i++)
		{
				c=m%10;
		m=m/10;
		}
		
		//	printf("%d ",c);
	//		printf("\n");
	//	for(ptm=phead2->prev;ptm!=phead2;ptm=ptm->prev)
		for(g=0;g<10;g++)
		{
	//			printf("%d",ptm->b);
		if(c==ptm->b)
		{
			//	ptm->record->next->a=ptmp->a;
				
				ptmp->prev=ptm->record->prev;
				ptm->record->prev->next=ptmp;
				ptm->record->prev=ptmp;
				ptmp->next=ptm->record;
	//		ptm->record->next=ptmp;
	//		ptmp->next=ptm->record;
	//		ptm->record->prev=ptmp;
	//		ptmp->prev=ptm->record;
	//		printf("1");
	//		printf("%d",ptm->record->a);
	//		printf("2");
		}
		//	printf("2\n");
			ptm=ptm->next;
			if(ptm==phead2)
					ptm=ptm->next;
		}
		printf("\n");
				ptmp=phead1->prev; //?????????
		}
	//	printf("%d",ptmp->a);
		ptm=phead2->next;
		for(g=0;g<10;g++)
		{
		ptmp=ptm->record->prev;
		for(;;)
		{
				if(ptmp->a==0)
						break;
		ptmp->prev->next=ptm->record;
		ptm->record->prev=ptmp->prev;
	//	printf("a:%d ",ptmp->a);
	//	printf("b:%d ",ptmp->a);
		ptmp->next=ptmp;
		ptmp->prev=ptmp;
		ptmp->prev=phead1->prev;
		phead1->prev->next=ptmp;
		phead1->prev=ptmp;
		ptmp->next=phead1;
		ptmp=ptm->record->prev;
		if(ptmp==ptm->record)
				break;
	//	printf("%d ",1);
		}
	//	ptmp->next=ptmp;
	//	ptmp->prev=ptmp;
		ptm=ptm->next;
	//	printf("%d ",ptmp->a);
		}
}
/*
void collect(ps phead1,pd phead2,int d)
{
	pd	ptm=phead2->next;
	int g;
	pd	ptmp=ptm->record;
		for(g=0;g<10;g++)
		{
		ptmp->prev->next=ptm->record;
		ptm->record->prev=ptmp->prev;
		ptmp->next=ptmp;
		ptmp->prev=ptmp;
		ptm=ptm->next;
		}
}*/
int main()
{
		int time,i;
	ps phead1=NULL;
	pd phead2=NULL;
//	ps phead3=NULL;
	init1(&phead1);
//	init1(&phead2->record);
	init2(&phead2);
time	=chain1(phead1,6);
//printf("%d\n",time);
//	show1(phead1);
	chain2(phead2);
//	show2(phead2);
printf("---------");
	for(i=1;i<=time;i++)
	{

distribute(phead1,i,phead2,6);
show1(phead1);
	}
//distribute(phead1,1,phead2,4);
//show1(phead1);
//show2(phead2);
//collect(phead1,1,phead2,4);
//show2(phead2);
	
}
