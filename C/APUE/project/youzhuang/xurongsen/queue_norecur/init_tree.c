#include"init.h"
//---------------------------------------
void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}
void free_memory(void **p)
{
	free(*p);
	*p = NULL;
}

void init_node(pNode *pnode)
{
	create_memory((void**)pnode,sizeof(sNode));
	(*pnode)->prev = (*pnode);
	(*pnode)->next = (*pnode);
}
void init_stack(pStack *pstack)
{
	create_memory((void **)pstack,sizeof(sStack));
	init_node(&(*pstack)->bottom);
	(*pstack)->top = (*pstack)->bottom;
}

int push(pStack pst,pTree ptree)
{
	pNode pnode = NULL;
	init_node(&pnode);
	pnode->pdata = ptree;
	pst->top->next = pnode;
	pst->bottom->prev = pnode;
	pnode->prev = pst->top;
	pnode->next = pst->bottom;
	pst->top = pnode;
	return SUC;
}

int pop(pStack pst,pTree *ptr_del)
{
	pNode pndel = NULL;
	if(pst->bottom->prev == pst->bottom)
	{
	//	printf("栈空！\n");
		return EMPTY;
	}
	pndel = pst->top;
	*ptr_del = pst->top->pdata;
	pst->top = pst->top->prev;
	pst->top->next = pst->bottom;
	pst->bottom->prev = pst->top;
	pndel->prev = NULL;
	pndel->next = NULL;
	free_memory((void **)&pndel);
//	return SUC;
}

//-------------------------Queue-------------------
int push_queue(pStack pst,pTree ptree)
{
/*		
	if(pst->bottom != (pst->top))
	{
		pNode pa=NULL;
		int cot=0;
		pa = pst->bottom;
		while(pa->next != pst->top)
		{
			cot++;
		}
		if(cot == SIZE)
		{
			printf("Queue full!\n");
			return FULL;
		}
	}
	else
	{
*/
		pNode pnode =NULL;
		init_node(&pnode);
		pnode->pdata = ptree;
		pst->top->next = pnode;
		pst->bottom->prev = pnode;
		pnode->prev = pst->top;
		pnode->next = pst->bottom;
		pst->top = pnode;
		return SUC;
}

int pop_queue(pStack pst,pTree *ptree)
{
	pNode pndel = NULL;
	if(pst->top == pst->bottom)
	{
			printf("Queue empty!\n");
			return EMPTY;
	}
	else
	{
		pndel = pst->bottom->next;
		*ptree = pst->bottom->next->pdata;
		pst->bottom->next = pndel->next;
		pndel->next->prev = pst->bottom;
		pst->top = pst->bottom->prev;
	
		pndel->prev = NULL;
		pndel->next = NULL;
		free_memory((void **)&pndel);
		return SUC;
	}
}
