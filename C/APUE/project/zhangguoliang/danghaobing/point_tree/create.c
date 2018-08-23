#include"create.h"

void init_tree(pTree *p)
{
		*p = (pTree)malloc(sizeof(sTree));
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
		(*p)->tr_data = EMPTY;
		(*p)->tr_parent = NULL;
		(*p)->tr_lc = NULL;
		(*p)->tr_rc = NULL;
}

void link_tree(pTree head,pTree insert)
{
	if(insert->tr_data > head->tr_data)
	{
			if(head->tr_rc==NULL)
			{
					head->tr_rc = insert;
					insert->tr_parent = head;
			}
			else
					link_tree(head->tr_rc,insert);
	}
	else
	{
			if(head->tr_lc==NULL)
			{
					head->tr_lc = insert;
					insert->tr_parent = head;
			}
			else
					link_tree(head->tr_lc,insert);
	}
}

void create(pTree pt_arr)
{
		int i,x,data;
		pTree pnew;
	printf("plese intput how many number you'll save!\n");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		scanf("%d",&data);
		if(pt_arr->tr_data==0)
			pt_arr->tr_data = data;
		else
		{
				init_tree(&pnew);
				pnew->tr_data = data;
				link_tree(pt_arr,pnew);
		}
	}
}
