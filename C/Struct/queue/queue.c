typedef struct s_queue
{
	char arr[SIZE];//char *arr;
	int pw;//指向队尾元素下一个位置
	int pr;//指向队头元素
}sQueue,*pQueue;
//先进先出 后进后出
void init_queue(pQueue queue)
{
	queue->pw = 0;
	queue->pr = 0;
}

int push_queue(pQueue queue,char data)
{
	if(queue->pr==(queue->pw+1)%SIZE)
	{
		printf("queue full\n");
		return FULL;
	}	
    queue->arr[queue->pw] = data;//数据入队列
	queue->pw = (queue->pw+1)%SIZE;//写下标移动
}

int pop_queue(pQueue queue,char *pop_data)
{
	if(queue->pw==queue->pr)
	{
		printf("queue empty");
		return EMPTY;
	}

	*pop_data = queue->arr[queue->pr];//数据出队列
	queue->pr = (queue->pr+1)%SIZE;
}





