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
}sDischain,*pDischain;

void init_Node(pNode *prt)
{
		*prt=malloc(sizeof(sNode));
		(*prt)->next=(*prt);
		(*prt)->prev=(*prt);
}

void init_Chain(pDischain *prt)
{
		*prt=malloc(sizeof(sDischain));
		init_Node(&(*prt)->record);
		(*prt)->next=(*prt);
}

void insert_tail(pNode pNew,pNode pHead)
{
				pNew->prev=pHead->prev;
				pHead->prev->next=pNew;
				pNew->next=pHead;
				pHead->prev=pNew;
}

int judge_num(pNode pHead)
{
		int a,i;
		int sum;
		int num=0;
		printf("输入数的个数\n");
		scanf("%d",&sum);
		for(;sum>0;sum--)
		{
				pNode pNew;
				init_Node(&pNew);
				printf("请输入一个正整数\n");
				scanf("%d",&pNew->data);
				a=pNew->data;
				for(i=0;a!=0;i++)
				{
						a=a/10;
				}
				insert_tail(pNew,pHead);
		
				if(i>num)
				{
						num=i;
				}
		}
		return num;
}

void prin_(pNode pHead)
{
		pNode palit=pHead;
		while(palit->next!=pHead)
		{
				printf("data=%4d\n",palit->next->data);
				palit=palit->next;
		}
}

void dis_bnte_tow(pNode palit,pDischain palitchain,pNode pHead)
{
		pHead->prev->next=palit->next;
		pHead->prev=palit->prev;
		palit->next=palit;
		palit->prev=palit;

		palitchain->record->prev->next=palit;
		palit->prev=palitchain->record->prev;
		palit->next=palitchain->record;
		palitchain->record->prev=palit;
}

void distribnte(int i,pNode pHead,pDischain pHeadChain)
{
		int a;
		printf("**distr_data=%d\n",pHead->prev->data);
		while(pHead->prev!=pHead)
		{
		int data=pHead->prev->data;
		for(a=i;a>0;a--)
		{
			data=data/10;
		}
		data=data%10;
		printf("data=%d\n",data);
		pDischain palitChain=pHeadChain;
		for(data;data>=0;data--)
		{
				palitChain=palitChain->next;
		}
		dis_bnte_tow(pHead->prev,palitChain,pHead);

		}

}

void collected(pNode pHead,pDischain pHeadChain)
{
		pDischain palitChain=pHeadChain->next;
		while(palitChain!=pHeadChain)
		{
				pNode palit=palitChain->record->prev;
				while(palit!=palitChain->record)
				{
						palit->prev->next=palitChain->record;
						palitChain->record->prev=palit->prev;
						palit->prev=palit;
						palit->next=palit;

						pHead->prev->next=palit;
						palit->prev=pHead->prev;
						palit->next=pHead;
						pHead->prev=palit;
						
						palit=palitChain->record->prev;
				}
				palitChain=palitChain->next;
		}
}

void main()
{
		int num;
		int i;
		pNode pHead;
		init_Node(&pHead);
		num = judge_num(pHead);

		pDischain pHeadChain;
		init_Chain(&pHeadChain);
		pDischain palitChain=pHeadChain;
		for(i=0;i<10;i++)
		{
				pDischain pNew_Chain;
				init_Chain(&pNew_Chain);
				pNew_Chain->next=palitChain->next;
				palitChain->next=pNew_Chain;
				palitChain = palitChain->next;
		}


		prin_(pHead);

		printf("num=%d\n",num);
		for(i=0;i<num;i++)
		{
				distribnte(i,pHead,pHeadChain);
				printf(" distribnte  ok\n");
				collected(pHead,pHeadChain);
		prin_(pHead);
		}
}
