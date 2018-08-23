#include"stack_chain.h"
void create_memory(void **p,int size)
{
		*p =  malloc(size);
		if(NULL==*p)
		{
				printf("mallocerror\n");
				exit(-1);
		}
}
void init_node(pNode *ps)
{
		create_memory((void **)ps,sizeof(sNode));
		(*ps)->prev = *ps;
		(*ps)->next = *ps;
}
void init_stack(pStack ps)
{
		init_node(&ps->bottom);
		ps->top = ps->bottom;
}
int push(pStack ps,pTree mod)
{
		pNode pnew = NULL;
		init_node(&pnew);
		pnew->data = mod;
		pnew->next = ps->top->next;
		pnew->prev = ps->top;
		ps->top->next->prev = pnew;
		ps->top->next = pnew;
		ps->top = pnew;
		return SUC;
}
int is_empty(pStack ps)
{
		if(ps->bottom->next==ps->bottom)
		{
				return EMPTY;
		}
		return SUC;
}
pTree pop(pStack ps)
{
		if(is_empty(ps))
		{
				return NULL;
		}
		pNode pdel= NULL;
		pdel = ps->top;
		pTree da = ps->top->data;
		ps->top->prev->next = ps->top->next;
		ps->bottom->prev = ps->top->prev;
		if(pdel !=NULL)
		{
				free(pdel);
				pdel = NULL;
		}
		ps->top = ps->bottom->prev;
		return da;
}
pTree get_stack_top(pStack ps)
{
        return (ps->top->data);
}
