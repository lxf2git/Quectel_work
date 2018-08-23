

#include"arr_queue.h"

int init_queue(Pqueue pque)
{

	int i=0; 
	pque->pw = 0;
	pque->pr = 0;

	return TURE; 
}

int creat_memory(void** q, int size)
{
	*q = malloc(size);

	if (NULL == *q)
	{
		printf("malloc failed \n");
	   	
		return FALSE;  	
	}

	return TURE; 
}

int push_queue(Pqueue pque , Ptree pnode)
{
		if (judge_queue(pque) == FULL)
		{
			printf("FULL\n");
		   	return FALSE;  	
		}
		
		pque->arr[pque->pw] = pnode;
		
		pque->pw = (pque->pw+1)%SIZE;

		return TURE; 
}

int pop_queue(Pqueue pque, Ptree* pop_pnode)
{
		if (judge_queue(pque) == EMPTY)
		{
			printf("EMPTY\n");
			
			return FALSE;  
		}	
		
		*pop_pnode = pque->arr[pque->pr];
		
		pque->pr = (pque->pr+1)%SIZE;

		return TURE; 	
}

int judge_queue(Pqueue pque)
{
	if (pque->pr == (pque->pw+1)%SIZE)
	{
		return FULL; 
	}

	if (pque->pr == pque->pw)
	{
		return EMPTY; 
	}
	
	else 
	{
		return FALSE;  
	}

	
}

