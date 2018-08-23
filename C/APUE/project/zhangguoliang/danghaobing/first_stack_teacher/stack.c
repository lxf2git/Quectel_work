#include"stack.h"

void creat_memory(pNode *p)
{
		*p = (pNode)malloc(sizeof(sNode));
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}

void init_Node(pNode *ps)
{
		creat_memory(ps);
		(*ps)->prev = *ps;
		(*ps)->next = *ps;
		(*ps)->data = NULL;
}

void init_stack(pStack ps)
{
		init_Node(&ps->bottom);
		ps->top = ps->bottom;
}

int push(pStack ps,pTree mod)
{
		pNode pnew = NULL;
		init_Node(&pnew);
		pnew->data = mod;

		pnew->next = ps->top->next;
		pnew->prev = ps->top;
		ps->top->next->prev = pnew;
		ps->top->next = pnew;
		ps->top = pnew;
		return SUC;
}

int pop(pStack ps,pTree *pop_data)
{
		pNode pdel = NULL;
		if(ps->bottom->next==ps->bottom)
		{
				return EMPTY;
		}
		
		*pop_data = ps->top->data;
		pdel = ps->top;
		ps->top->prev->next = ps->bottom;
		ps->bottom->prev = ps->top->prev;
		if(pdel!=NULL)
		{
				free(pdel);
				pdel = NULL;
		}

		ps->top = ps->bottom->prev;
		
		return SUC;
}






