#include<stdio.h>
#include<stdlib.h>
int num;
int j;
typedef struct node
{
		int data;
		struct node *prev;
		struct node *next;
}sNode,*pNode;
typedef struct dis_chain
{
		pNode record;
		struct dis_chain *prev;
		struct dis_chain *next;

}sDis,*pDis;
pDis pp[10];
void get_memory(void **q,int size)
{
		*q = malloc(size);
		if(*q==NULL)
		{
				printf("malloc error.\n");
				exit(-1);
		}
}
void my_free(void **q)
{
		if(*q!= NULL)
		{
				free(*q);
				*q = NULL;
		}
}
void init_n(pNode *p)
{
		get_memory((void **)p,sizeof(sNode));
		(*p)->prev = *p;
		(*p)->next = *p;
}
int judge_num(int n)
{
		int count =0;
		while(n%10!=0)
		{
				count++;
				n /= 10;
		}
		
		if(count>num)
		{
				num = count;
		}	

}
void creat_chain(pNode pHead)
{
		int i=0;
		pNode pnew=NULL;
		printf("input need to deal diget number:\n");
		scanf("%d",&i);
		while(i--)
		{
			init_n(&pnew);
			printf("please input digit:\n");
			scanf("%d",&pnew->data);
			judge_num(pnew->data);
			pnew->next = pHead;
			pnew->prev = pHead->prev;
			pHead->prev->next = pnew;
			pHead->prev = pnew;	
		}
}
void input (pNode pHead)
{
		creat_chain(pHead);
}
void print(pNode pHead)
{
		pNode pa=pHead;
		while(pHead->next!=pa)
		{
				printf("pHead->next:%d\n",pHead->next->data);
				pHead = pHead->next;
		}
}
void init_s(pNode pHead,pNode pnew)
{
		pnew->next = pHead;
		pnew->prev = pHead->prev;
		pHead->prev->next = pnew;
		pHead->prev = pnew;	
}
void next_arr(pNode ptail)
{
		int i;
	//	i = (ptail->data)%j;
		i = ((ptail->data)/j)%10;
	//	printf("i=%d\n",ptail->data);
		switch(i)
		{
				case 0:init_s(pp[0]->record,ptail);break;
				case 1:init_s(pp[1]->record,ptail);break;
				case 2:init_s(pp[2]->record,ptail);break;
				case 3:init_s(pp[3]->record,ptail);break;
				case 4:init_s(pp[4]->record,ptail);break;
				case 5:init_s(pp[5]->record,ptail);break;
				case 6:init_s(pp[6]->record,ptail);break;
				case 7:init_s(pp[7]->record,ptail);break;
				case 8:init_s(pp[8]->record,ptail);break;
				case 9:init_s(pp[9]->record,ptail);break;
		}
}		
void destory_tail_chain(pNode pHead)
{
		pNode ptail = NULL;
		ptail = pHead->prev;
		while(pHead->next!=pHead)
	  
		{
				pHead->prev = ptail->prev;
				ptail->prev->next = pHead;
				ptail->next =ptail;
				ptail->prev =ptail;
				next_arr(ptail);
				ptail = pHead->prev;
		}
}

void distribute(pNode pHead)
{
		destory_tail_chain(pHead);
}
void creat_link(pNode pHead,pNode pHead1)
{
		pNode ptail = NULL;
		pNode pinsert = NULL;
		ptail = pHead->prev;
		while(pHead->next!=pHead)
	  
		{
				pHead->prev = ptail->prev;
				ptail->prev->next = pHead;
				ptail->next =ptail;
				ptail->prev =ptail;
				printf("pp:%d\n",ptail->data);
				if(ptail->data!=0)
				{
					pinsert = ptail;
					init_s(pHead1,pinsert);
				}
				ptail = pHead->prev;

		}
}
void collected(pNode pHead)
{
		int i=0;
		for(i=0;i<10;i++)
		{
				creat_link(pp[i]->record,pHead);
		}
}
int main()
{
		int i=0;
		j=1;
		for(i=0;i<10;i++)
		{
				pp[i] = (sDis *)malloc(sizeof(sDis));
				init_n(&pp[i]->record);
		}
		pNode pHead =NULL;
		init_n(&pHead);
		input(pHead);
		for(i=0;i<num;i++)
		{
				distribute(pHead);
				collected(pHead);
				j = j * 10;
		}
		print(pHead);
		return 0;
}

