
#include"chain_queue.h"

Pnode find_ptail(Pnode phead);

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

int en_queue(Pnode phead, Ptree en_data) //尾插并赋值
{
	Pnode pnew = NULL, ptail =NULL;
		
	init_node(&pnew);

	pnew->data = en_data; // 赋值

	ptail = find_ptail(phead);

	add_back(ptail, pnew);

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

int de_queue(Pnode phead, Ptree* de_data) //头删 并返回值
{
	if (judge_queue(phead) == EMPTY)
	{
		printf("EMPTY \n");
	   	return EMPTY; 	
	}
	
	*de_data = phead->next->data;
	
	delete_back(phead);
	
	return TURE; 
}

int judge_queue(Pnode phead)
{
	if (phead->next == phead)
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






