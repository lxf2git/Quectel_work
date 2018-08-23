#include"tree2.h"

void init_stack(pStack *ps)	
{
	creat_memory((void**)ps,sizeof(sStack));
	init_node(&(*ps)->bottom);
	(*ps)->top = (*ps)->bottom;
}
void init_node(pNode *pnode)
{
	creat_memory((void**)pnode,sizeof(sNode));
	(*pnode)->prev = *pnode;
	(*pnode)->next = *pnode;
}
int push(pStack ps,pTree pmod)
{
	pNode pnew = NULL;
	init_node(&pnew);
	pnew->pdata = pmod;//接收mod

	pnew->prev = ps->top;
	pnew->next = ps->bottom;
	ps->top->next = pnew;
	ps->bottom->prev = pnew;
	ps->top = pnew;
	return SUC;
}
int pop(pStack ps,pTree *pop_tree)
{
	pNode pdel = NULL;
	if(ps->bottom->next == ps->bottom)
	{
//		printf("error:bottom!\n");
		return EMPTY;
	}
	*pop_tree = ps->top->pdata;
	pdel = ps->top;
	ps->top = pdel->prev;

	ps->top->next = ps->bottom;
	ps->bottom->prev = ps->top;
//	ps->bottom->prev = ps->top;
//	ps->top->next = ps->bottom;
	pdel->prev = NULL;
	pdel->next = NULL;
	free_memory((void**)&pdel);
	return SUC;
}

