#include"first.h"

pTree find_Node(pTree pHead)
{
	char x;
	if(pHead->tr_lc==NULL)
	{
		scanf("%c",&x);
		if(x!=' ')
		{
				pTree pnew;
				init_Node(&pnew);
				pnew->tr_data = x;
				pHead->tr_lc = pnew;
			    find_Node(pHead->tr_lc);
		}
	}
	if(pHead->tr_rc==NULL)
	{
		scanf("%c",&x);
		if(x!=' ')
		{
				pTree pnew;
				init_Node(&pnew);
				pnew->tr_data = x;
				pHead->tr_rc = pnew;
		 		find_Node(pHead->tr_rc);
		}
	}
}

void insert_data(pTree pHead)
{
	char x;
	scanf("%c",&x);
	pHead->tr_data = x;
	find_Node(pHead);
}

void first_creat(pTree pStart)
{
	insert_data(pStart);
}
