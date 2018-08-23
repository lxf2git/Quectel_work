#include"main.h"

enum choosename
{
	Apply=1,
	Free,
	Print,
	Exit
};
void link_Memory(pMem pHead,pMem ptmp,pMem pnew_memory)
{
	pnew_memory->next=pHead;
	pHead->prev=pnew_memory;
	ptmp->next=pnew_memory;
	pnew_memory->prev=ptmp;
}
void build_Memory(pMem pHead,int num,int lenth)
{
	pMem ptmp=pHead->next;	
	pMem pnew_memory;
	int i;
	for(i=0;i<num;i++)
	{
		create_memory(&pnew_memory,sizeof(sMem));
		pnew_memory->index=i+1;
		pnew_memory->mem_size=lenth;
		link_Memory(pHead,ptmp,pnew_memory);
		ptmp=pnew_memory;
	}
}

void show_memory(pMem pHead)
{
	pMem p1=pHead->next;
	while(p1!=pHead)
	{
		printf("index: %d,size %d\n",p1->index,p1->mem_size);
		p1=p1->next;
	}
}

void show_Memory(pRec phead)
{
	pRec p2=phead->next;
	pMem p3;
	while(p2!=phead)
	{
		p3=(p2->pdata)->next;
		while(p3!=p2->pdata)
		{
		printf("index: *%d,size *%d\n",p3->index,p3->mem_size);
		p3=p3->next;
		}
		printf("\n");
		p2=p2->next;
		//p3=p2->pdata->next;
	}
}
int main()
{
	int choose;
	int num,lenth;
	pMem pHead=NULL;
	pRec phead=NULL;
	create_memory(&phead,sizeof(sRec));
	pRec ptm=phead->next;
	create_memory(&pHead,sizeof(sMem));
	printf("please input how much memory have\n");
	scanf("%d",&num);
	printf("please input how large every memory\n");
	scanf("%d",&lenth);
	pHead->mem_size=lenth;
	build_Memory(pHead,num,lenth);
	show_memory(pHead);
	printf("\n");
	while(1)
	{
	printf("**************************\n");
	printf("*********1.apply**********\n");
	printf("*********2.free***********\n");
	printf("*********3.print**********\n");
	printf("*********4.exit***********\n");
	printf("**************************\n");
	printf("please input your choose:\n");
	scanf("%d",&choose);
	switch(choose)
	{
		case Apply:
		apply_memory(pHead,ptm,phead);
		ptm=phead->prev;
		show_Memory(phead);
		break;
		case Free:
		free_memory(pHead,phead);
		show_memory(pHead);
		break;
		case Print:
		printf("you having memory now!\n");
		show_memory(pHead);
		printf("you useing memory now!\n");
		show_Memory(phead);
		break;
		case Exit:
		return 0;
		default:
	printf("choose error!please input restart\n");
		break;
	}
	}
}
