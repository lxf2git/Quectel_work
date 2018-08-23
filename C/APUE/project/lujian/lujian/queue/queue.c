
#include"queue.h"

int init_queue(Pqueue pque)
{
	pque->pw =0;
	pque->pr =0;


	return TURE; 
}

int push_queue(Pqueue pque, char data)
{
		if (judge_queue(pque) == FULL)
		{
			return FULL;
		}

		pque->arr[pque->pw] = data; //写入数据
		
		pque->pw = (pque->pw+1)%SIZE; // 写下标移动
	
		return TURE; 

}

int  pop_queue(Pqueue pque, char* pop_data)
{

	if (judge_queue(pque) == EMPTY)
	{
		return EMPTY; 
	}
	*pop_data = pque->arr[pque->pr]; // 数据出队列

	pque->pr = (pque->pr+1)%SIZE;   // 删除下标移动

	return TURE; 
}

int judge_queue(Pqueue pque)
{
	if (pque->pr == ((pque->pw+1)%SIZE)) // 满(空一内存没用)
	{
		return FULL; 
	}

	if (pque->pr == pque->pw)          //空
	{
		return EMPTY; 
	}
	
	else
		return FALSE;  

}


