#include"huffman.h"

void init_stack(pStack *ps)
{
	creat_memory((void**)ps,sizeof(sStack));
	init_node(&(*ps)->bottom);
	(*ps)->top = (*ps)->bottom;
}

int push(pStack ps,int b)
{
	pNode pnew = NULL;
	init_node(&pnew);
	pnew->weight = b;
	pnew->parent = ps->top;
	ps->top->next = pnew;
	ps->bottom->parent = pnew;
	pnew->next = ps->bottom;
	ps->top = pnew;
	return SUC;
}

int pop(pStack ps,int *pop_b)
{
	pNode pdel = NULL;
	if(ps->top == ps->bottom)
	{
		return EMPTY;
	}
	*pop_b = ps->top->weight;
	pdel = ps->top;
	ps->top = pdel->parent;
	ps->top->next = ps->bottom;
	ps->bottom->parent = ps->top;
	pdel->next = NULL;
	pdel->parent = NULL;
	free_node(&pdel);
	return SUC;
}
