#include"tree2.h"

int queue_tree(pQueue pque,pTree proot)
{
	int ret = 0;
	pTree ptmp = proot;
	while(ret != EMPTY)
	{
		printf("%c ",ptmp->data);
		if(ptmp->left != NULL)
		{
			push_queue(pque,ptmp->left);
		}
		if(ptmp->right != NULL)
		{
			push_queue(pque,ptmp->right);
		}
		ret = pop_queue(pque,&ptmp);
	}
}
int is_queue_empty(pQueue pque)
{
	if(pque->read == pque->qhead)
	{
		return EMPTY;
	}
	return SUC;
}
int mid_tree(pStack psta,pTree proot)
{

	int ret = 0;
	pTree ptmp = proot;
/*
	for(;;)
	{
//		printf("test1%c\n",ptmp->data);
		push(psta,ptmp);
		if(ptmp->left != NULL)
		{
			ptmp = ptmp->left;
//			printf("test2%c\n",ptmp->data);
			continue;
		}
		else
		{
			for(;;)
			{
				ret = pop(psta,&ptmp);
				if(ret == EMPTY)
				{
					return SUC;
				}
				printf("%c ",ptmp->data);
				if(ptmp->right != NULL)
				{	
					ptmp = ptmp->right;
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
	*/
	while(ptmp != NULL||EMPTY != is_empty(psta))
	{
		while(ptmp!= NULL)
		{
		//	printf("%c ",ptmp->data);//先序
			push(psta,ptmp);
			ptmp = ptmp->left;
		}
		pop(psta,&ptmp);
		printf("%c ",ptmp->data);//中序
		ptmp = ptmp->right;
	}
}
int is_empty(pStack ps)
{
	if(ps->bottom->next == ps->bottom)
	{
		return EMPTY;
	}
	return SUC;
}
int pre_tree(pStack psta,pTree proot)
{
	int ret = 0;	
	pTree ptmp = proot;
	for(;;)
	{
//		printf("test1%c\n",ptmp->data);
		push(psta,ptmp);
		printf("%c ",ptmp->data);
		if(ptmp->left != NULL)
		{
			ptmp = ptmp->left;
//			printf("test2%c\n",ptmp->data);
			continue;
		}
		else
		{
			for(;;)
			{
				ret = pop(psta,&ptmp);
				if(ret == EMPTY)
				{
					return SUC;
				}
				if(ptmp->right != NULL)
				{	
					ptmp = ptmp->right;
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
}
pTree get_top(pStack ps)
{
	return ps->top->pdata;
}
int last_tree(pStack psta,pTree proot)
{
	int ret = 0;
	pTree ptmp = proot;
	pTree pvisit = NULL;
	while(ptmp != NULL||EMPTY != is_empty(psta))
	{
		while(ptmp!= NULL)
		{
			push(psta,ptmp);
			ptmp = ptmp->left;
		}
		ptmp = get_top(psta);
		if(ptmp->right == NULL||pvisit == ptmp->right)
		{
			pop(psta,&ptmp);
			printf("%c ",ptmp->data);
			pvisit = ptmp;
			ptmp = NULL;
		}
		else
		{
			ptmp = ptmp->right;
		}
	}
/*
	for(;;)
	{
		push(psta,ptmp);
//		printf("test1%c\n",ptmp->data);
		if(ptmp->left != NULL)
		{
			ptmp = ptmp->left;
			continue;
		}
		else
		{
			if(ptmp->right != NULL)
			{
				ptmp = ptmp->right;
				continue;
			}
			else
			{
				for(;;)
				{
					ret = pop(psta,&ptmp);
					printf("%c ",ptmp->data);
					if(ptmp->parent == NULL)
					{
						return SUC;
					}
					else if(ptmp->parent->right!=ptmp&&ptmp->parent->right!=NULL)
					{
						ptmp = ptmp->parent->right;
						break;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
*/
}
