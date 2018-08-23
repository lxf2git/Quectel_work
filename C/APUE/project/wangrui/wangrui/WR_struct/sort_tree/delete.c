#include"main.h"

void (*deal_data[3])(pTree)={
	del_leaf,
	del_limb,
	del_root
	};
int delete_tree(pTree proot)
{
	int num;
	printf("delete data:\n");
	scanf("%d",&num);
	deal_op(proot,num);
}
int deal_op(pTree proot,int num)
{
	int jud;
	pTree ptmp = NULL;
	ptmp = traversal_tree(proot,num);
	printf("trav out\n");
	if(ptmp == NULL)
	{
		printf("fail\n");
		return FAIL;
	}
	if(ptmp->lc == NULL && ptmp->rc == NULL)
	{
		jud = 0;
	}
	else if(ptmp->lc == NULL || ptmp->rc == NULL)
	{
		jud = 1;
	}
	else
	{
		jud = 2;
	}
	printf("jud:%d\n",jud);
	deal_data[jud](ptmp);	
}
pTree traversal_tree(pTree p,int num)
{
	pTree ptmp = NULL;
	printf("data:%d\n",p->data);
	if(p->data == num)
	{
		ptmp = p;
		return ptmp;
	}
	else
	{
		if(p->lc != NULL)
		{
			ptmp = traversal_tree(p->lc,num);
			if(ptmp != NULL&&ptmp->data == num)
			{
				return ptmp;
			}
		}
		if(p->rc != NULL)
		{
			ptmp = traversal_tree(p->rc,num);
			if(ptmp != NULL&&ptmp->data == num)
			{
				return ptmp;
			}
		}
	}
//	return ptmp;
}
void del_leaf(pTree pnode)
{
	if(pnode->pa->lc == pnode)
	{
		pnode->pa->lc = NULL;
		pnode->pa = NULL;
	}
	else
	{
		pnode->pa->rc = NULL;
		pnode->pa = NULL;
	}
}
void del_limb(pTree pnode)
{
	printf("limb\n");
	if(pnode->pa == NULL)
	{
		if(pnode->lc == NULL)
		{
			pnode->rc->pa = NULL;
			pnode->rc = NULL;
		}
		else
		{
			pnode->lc->pa = NULL;
			pnode->lc = NULL;
		}
	}
	else
	{
		if(pnode->rc == NULL)
		{
			pnode->lc->pa = pnode->pa;
			if(pnode->pa->lc == pnode)
			{
				pnode->pa->lc = pnode->lc;
			}
			else
			{
				pnode->pa->rc = pnode->lc;
			}
			pnode->pa = NULL;
			pnode->lc = NULL;
		}
		else
		{
			pnode->rc->pa = pnode->pa;
			if(pnode->pa->lc == pnode)
			{
				pnode->pa->lc = pnode->rc;
			}
			else
			{
				pnode->pa->rc = pnode->rc;
			}
			pnode->pa = NULL;
			pnode->rc = NULL;
		}
	}
}
void del_root(pTree pnode)
{
	pTree ptmp = NULL;
	ptmp = find_left(pnode->lc);
	if(ptmp->lc == NULL)
	{
		if(pnode->pa == NULL)
		{
			pnode->data = ptmp->data;
			ptmp->pa->rc = NULL;
			ptmp->pa = NULL;
		}
		else
		{
			ptmp->pa->rc = NULL;
			ptmp->pa = pnode->pa;
			pnode->lc->pa = ptmp;
			ptmp->lc = pnode->lc;
			pnode->rc->pa = ptmp;
			ptmp->rc = pnode->rc;
			pnode->rc = NULL;
			pnode->lc = NULL;
		}
	}
	else
	{
		pnode->lc->pa = pnode->pa;
		if(pnode->pa != NULL)
		{
			if(pnode->pa->rc = pnode)
			{
				pnode->pa->rc = pnode->lc;
			}
			else
			{
				pnode->pa->lc = pnode->lc;
			}
			pnode->pa = NULL;
		}
		pnode->lc = NULL;
		pnode->rc->pa = ptmp;
		ptmp->rc = pnode->rc;
		pnode->rc = NULL;
	}
}

pTree find_left(pTree ptmp)
{
	while(ptmp->rc != NULL)
	{
		ptmp = ptmp->rc;
	}
	return ptmp;
}
