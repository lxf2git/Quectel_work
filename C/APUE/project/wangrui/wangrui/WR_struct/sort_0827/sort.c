#include"sort.h"

void collected(pNode pHead,pChain pFrist)
{
	int i;
	pChain pctmp = pFrist->next;
	pNode pcol = NULL;
	for(i=0;i<10;i++)
	{
		while(pctmp->record->next != pctmp->record)
		{
			pcol=head_des(pctmp->record,pcol);
			insert_back(pHead,pcol);
		}
		pctmp = pctmp->next;
	}
}

pNode head_des(pNode pHead,pNode ptmp)
{
		ptmp = pHead->next;
		pHead->next = ptmp->next;
		pHead->next->prev = pHead;		
		ptmp->next = ptmp;
		ptmp->prev = ptmp;
}

void distribute(pNode pHead,pChain pFrist,int num,int i)
{
	int n;
	pNode ptmp = NULL;
	while(pHead->next!=pHead)
	{
		ptmp = head_des(pHead,ptmp);
		n = deal_data(ptmp->data,num,i);
		insert_node(pFrist,n,ptmp);
	}
}
int deal_data(int a,int n,int i)
{
	int sum;
	sum = deal_num(n-1);
	while(i<n)
	{
		a=a%sum;
		sum = sum/10;
		i++;
	}
	a=a/sum;
	return a;
}
int deal_num(int n)
{
	int sum = 1;
	while(n!=0)
	{
		sum = sum*10;
		n--;
	}
	return sum;
}

void insert_node(pChain pFrist,int num,pNode pIn)
{
	pChain ptmp = pFrist->next;
	while(num != 0)
	{
		ptmp=ptmp->next;
		num--;
	}
	insert_back(ptmp->record,pIn);
}
