#include"delet.h"

pTree find_data(pTree pHead,int data)
{
		if (pHead->tr_lc != NULL)
		{
			 pTree pnew = find_data(pHead->tr_lc,data);
			 if(pnew !=NULL )
			 	return pnew;
		}
		if (pHead->tr_data == data)
		{
				return pHead;
		}
		if (pHead->tr_rc != NULL)
		{
			 pTree pnew = find_data(pHead->tr_rc,data);
			 if(pnew !=NULL )
			 	return pnew;
		}
		return NULL;
}

void insert_Node(pTree pfind,int data)
{
	pTree insert_node = pfind;
	while(1)
	{
			if(insert_node==NULL)
					break;
			insert_node = insert_node->tr_lc;
	}
	insert_node = pfind->tr_lc->tr_rc;
	pfind->tr_lc->tr_rc = pfind->tr_rc;
	if(pfind->tr_parent!=NULL)
	{
		if(pfind->tr_lc!=NULL)
			pfind->tr_lc->tr_parent = pfind->tr_parent;
		if(pfind->tr_parent->tr_lc!=NULL&&pfind->tr_parent->tr_lc->tr_data == data)
		{
				pfind->tr_parent->tr_lc = pfind->tr_lc;
		}
		else
		{
				pfind->tr_parent->tr_rc = pfind->tr_lc;
		}
	}
	else
	{
		pfind->tr_data = pfind->tr_lc->tr_data;
		pfind->tr_rc = pfind->tr_lc->tr_rc;
		pfind->tr_lc = pfind->tr_lc->tr_lc;
		if(pfind->tr_rc!=NULL)
		pfind->tr_rc->tr_parent = pfind;
		if(pfind->tr_lc!=NULL)
		pfind->tr_lc->tr_parent = pfind;
	}

}

void delete_tail(pTree pfind,int data)
{
	if(pfind->tr_parent==NULL)
	{
		if(pfind->tr_rc!=NULL)
		{
			pfind->tr_data = pfind->tr_rc->tr_data;
			pfind->tr_lc = pfind->tr_rc->tr_lc;
			pfind->tr_rc = pfind->tr_rc->tr_rc;
			if(pfind->tr_rc!=NULL)
			pfind->tr_rc->tr_parent = pfind;
			if(pfind->tr_lc!=NULL)
			pfind->tr_lc->tr_parent = pfind;
		}
		else
		{
			pfind->tr_data = EMPTY;
			printf("have no number\n");
		}
		return ;
	}
	else
	{
		if(pfind->tr_parent->tr_lc!=NULL&&pfind->tr_parent->tr_lc->tr_data == data)
		{
			pfind->tr_parent->tr_lc = pfind->tr_rc;
		}
		else
		{
			if(pfind->tr_rc!=NULL)
			pfind->tr_rc->tr_parent = pfind->tr_parent;
			pfind->tr_parent->tr_rc = pfind->tr_rc;
		}
	}
}

void delete_Node(pTree pHead)
{
		int data;
		printf("please input number\n");
		scanf("%d",&data);
		pTree pfind = find_data(pHead,data);
		if(pfind==NULL)
		{
			printf("not find!\n");
			return ;
		}
		if(pfind->tr_lc!=NULL)
		{
			insert_Node(pfind,data);
		}
		else
		{
			delete_tail(pfind,data);
		}
}
