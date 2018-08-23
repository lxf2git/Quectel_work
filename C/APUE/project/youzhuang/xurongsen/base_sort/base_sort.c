#include"base_sort.h"

int main()
{
	pSt phead=NULL;
	init_node(&phead,sizeof(sSt));

	pChain pCh=NULL;
	init_chain(&pCh,sizeof(sChain));

	create_chain(phead);
	create_chain_chain(pCh);
	show_chain(phead);

	int num,i;
	num=judge_num(phead);

	for(i=0;i<num;i++)
	{
		distribute(pCh,phead,num,i+1);
		collect(pCh,phead);
	}
	show_chain(phead);
	return 0;
}
//------------------------------------------------------
void distribute(pChain pFh,pSt phead,int num,int n)
{
	int m;
	pSt pnode=NULL;
	while(phead->next != phead)
	{
		pnode = head_del(phead, pnode);
		m = deal_num(pnode->data, num, n);
		insert_back(pFh,m,pnode);
	}
}

pSt head_del(pSt phead,pSt pnode)
{
	pnode = phead->next;
	phead->next = pnode->next;
	pnode->next->prev = phead;
	pnode->next = pnode;
	pnode->prev = pnode;
}

void insert_back(pChain pFh,int m,pSt pnode)
{
	pChain pcn = pFh->next;
	while(m != 0)
	{
		pcn = pcn->next;
		m--;
	}
	insert_back_node(pcn->record, pnode);
}

void insert_back_node(pSt phead,pSt pnode)
{
	pnode->next = phead->next;
	phead->next = pnode;
	pnode->next->prev = pnode;
	pnode->prev = phead;
}

int deal_num(int data, int num, int n)
{
	int sum;
	sum = deal_n(num-1);
	while(n<num)
	{
		data = data%sum;
		sum = sum/10;
		n++;
	}
	data = data/sum;
	return data;
}

int deal_n(int n)
{
	int sum=1;
	while(n>0)
	{
		sum = sum*10;
		n--;
	}
	return sum;
}

int judge_num(pSt phead)
{
	pSt pnode=phead;
	int max=0,n=0;
	for(pnode=phead->next;(pnode != phead);pnode=pnode->next)
	{
		n=count(pnode->data);
		if(n > max)
		{
			max = n;
		}
	}
	return max;
}

int count(int data)
{
	int i=0;
	while(data != 0)
	{
		data = data/10;
		i++;
	}
	return i;
}
//-----------------------------------------------------
void collect(pChain pFh,pSt phead)
{
	int i;
	pChain pcn = pFh->next;
	pSt pnode = NULL;
	for(i=0;i<10;i++)
	{
		while(pcn->record->next != pcn->record)
		{
			pnode = head_del(pcn->record,pnode);
			insert_back_node(phead,pnode);
		}
		pcn = pcn->next;
	}
}
