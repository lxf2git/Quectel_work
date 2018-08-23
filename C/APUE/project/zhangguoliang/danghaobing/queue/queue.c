#include"queue.h"

void init_queue(pQueue *queue)
{
	create_memory((void **)queue,sizeof(sQueue));
	(*queue)->pw = 0;
	(*queue)->pr = 0;
}

int push_queue(pQueue queue,pTree data)
{
	if ( queue->pr == (queue->pw+1)%SIZE )
	{
			printf("queue full!\n");
			return FULL;
	}
	//数据入队列
	queue->arr[queue->pw] = data;
	queue->pw = (queue->pw+1)%SIZE;//下标移动
	return SUC;//正常返回
}

int pop_queue(pQueue queue,pTree *pop_data)
{
	if(queue->pw==queue->pr)
	{
	//		printf("queue empty");
			return EMPTY;
	}	
	*pop_data = queue->arr[queue->pr];//数据出列
	queue->pr = (queue->pr+1)%SIZE;
	return SUC;
}
