

#include"stack.h"

int init_stack(Psta ps)
{
	init_node(&ps->bottom);
	ps->top = ps->bottom;

	return TURE; 
}

int init_node(Pnode* psnode)
{
	creat_memory((void**)psnode,sizeof(Snode));
	
	(*psnode)->prev = (*psnode);
	(*psnode)->next= (*psnode);

	return TURE; 
}


int creat_memory(void** q, int size)
{	
	*q = malloc(size);

	if (NULL == *q)
	{
	printf("malloc fail \n");
   	return FALSE;  	
	}
	return TURE; 
}

int push(Psta ps, Ptree tr_node)
{
	Pnode pnew =NULL;
	
	init_node(&pnew);

	pnew->data = tr_node;
	add_back(ps->top, pnew);
	ps->top = pnew;

	return TURE; 
}

int add_back(Pnode pos, Pnode pin)
{
	if (NULL == pos || NULL == pin)
	{
		return FALSE;  	
	}
	pin->prev =pos;
	pin->next =pos->next;
	pos->next->prev = pin;
	pos->next = pin;

	return TURE; 
}

int pop(Psta ps, Ptree* pop_data)
{
		if (ps->bottom->next  == ps->bottom)
		{
				return EMPTY;
		}
		
		*pop_data = ps->top->data;
		delete_back(ps->top->prev);
		ps->top = ps->bottom->prev; // ps->top 指针指向尾节点 ************/
		return TURE; 
}	

int delete_back(Pnode pos)
{
	if (pos ==NULL || pos->next ==NULL)
	{
		return FALSE;  
	}

	Pnode pdel = pos->next;

	pos->next =pdel->next;
	pdel->next->prev = pos;

	pdel->next = pdel;
	pdel->prev =pdel;
	
	myfree(&pdel);

	return TURE; 
}

int myfree(Pnode* pdel)
{
	if (NULL !=*pdel)
	{
		free(*pdel);
		*pdel = NULL;
	}

	return TURE; 
}



