
#include"chain_queue.h"

Pnode find_ptail(Pnode phead);

int init_queue(Pqueue pque)
{
	init_node(&pque->pr);	
		
	pque->pw = pque->pr;

	return TURE; 
}

int init_node(Pnode* p)
{	
	creat_memory((void**)p, sizeof(Snode));
	
	(*p)->next = (*p);
	(*p)->prev = (*p);

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

int en_queue(Pqueue pque, Ptree en_data)
{
	Pnode pnew = NULL;
		
	init_node(&pnew);

	pnew->data = en_data;
	pque->pw = find_ptail(pque->pr);

	add_back(pque->pw, pnew);

	return TURE; 
}


Pnode find_ptail(Pnode phead)
{
	Pnode ptravl =phead;
			while(ptravl->next != phead)
			{
				ptravl =ptravl->next;
			}
	
			return ptravl;
}
int add_back(Pnode pos, Pnode pin)
{
	if (NULL == pos || NULL == pin)
	{
		return FALSE;  
	}
	
	pin->prev = pos;

	pin->next = pos->next;

	pos->next->prev  = pin;
	
	pos->next = pin;

	return TURE; 
}

int de_queue(Pqueue pque, Ptree* de_data)
{
	if (judge_queue(pque) == EMPTY)
	{
		printf("EMPTY \n");
	   	return EMPTY; 	
	}
	
	*de_data = pque->pr->next->data;
	
	delete_back(pque->pr);
	
	return TURE; 
}

int judge_queue(Pqueue pque)
{
	if (pque->pr->next == pque->pr)
	{
		return EMPTY; 	
	}
	else
	{
		return FALSE;  
	}
}

int delete_back(Pnode pos)
{
	if (NULL == pos)
	{
		return FALSE;  
	}

	Pnode pdel = pos->next;
	
	pos->next = pdel->next;
	
	pdel->next->prev =pos;

	pdel->next = pdel;

	pdel->prev = pdel;	

	myfree(&pdel);
			
	return TURE; 
}

int myfree(Pnode* pdel)
{
	if (NULL != *pdel)
	{
		free(*pdel);

		*pdel =NULL;
	}
	
	return TURE; 
}






