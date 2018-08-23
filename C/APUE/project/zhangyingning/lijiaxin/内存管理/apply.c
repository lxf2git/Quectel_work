#include"main.h"
void init_s(pRecord *p,int size)
{
		get_memory((void **)p,sizeof(sRecord));
		(*p)->prev = *p;
		(*p)->next = *p;	
}
int max_mem(pNode pHead)
{
		int max_size,flag;
		pNode ptmp = pHead;
		max_size = pHead->next->mem_size;
		flag = pHead->next->index;
		while(ptmp->next!=pHead)
		{
				if(max_size<ptmp->next->mem_size)
				{
						flag = ptmp->next->index;
						max_size = ptmp->next->mem_size;
				}
				ptmp = ptmp->next;

		}
		return flag;
}
pNode find_index(int i,pNode pHead)
{
		pNode ptmp = pHead->next;
		while(1)
		{
			if(i==ptmp->index)
			{
					return (ptmp);
			}
			ptmp = ptmp->next;
		}
}
pNode find_mem(int size,pNode pHead)
{
		pNode ptmp = pHead->next;
		while(ptmp!=pHead)
		{
			if(size==ptmp->mem_size)
			{
					printf("size: %d ",size);
					printf(" %d \n",ptmp->index);
					return (ptmp);
			}
			ptmp = ptmp->next;
		}
	/*	if(size==ptmp->mem_size)
		{
				return (ptmp);
		}*/
		return NULL;
}
get_fail_chain(pRecord pHead,pRecord pnew)//尾差建链函数
{
		pnew->next = pHead;
		pnew->prev = pHead->prev;
		pHead->prev->next = pnew;
		pHead->prev = pnew;
}
pNode free_size_max(pNode pHead,pNode pnew)
{
		pNode ptmp = pHead;
	   while(ptmp->next!=pHead)
	   {
			   if(pnew->mem_size < ptmp->next->mem_size)
			   {
					   return ptmp;
			   }
			   ptmp = ptmp->next;
	   }	   
	   return ptmp;
}
void creat_free_chain(pNode pHead,pNode pnew)
{
		pNode ptmp=NULL;
		printf("free_pnew:%d\n",pnew->mem_size);
		ptmp = free_size_max(pHead,pnew);
		printf("free_chain_begin:%d\n",ptmp->mem_size);
		pnew->next = ptmp->next;
		pnew->prev = ptmp;
		ptmp->next->prev = pnew;
		ptmp->next = pnew;

}
void destory_chain(pNode ptmp)
{
		ptmp->prev->next = ptmp->next;
		ptmp->next->prev = ptmp->prev;
		ptmp->next = ptmp;
		ptmp->prev = ptmp;
}
void creat_chain(int size,pNode pHead,pRecord ppp)
{
		int i;
		pHead->mem_size = pHead->mem_size - size;//计算剩余空间a
		pRecord pp=NULL;
		pNode ptmp = NULL;
		pNode ptmp1 = NULL;
		pNode ptmp2 = pHead;
		i =	max_mem(pHead);   //差找最大空间的index
		ptmp = find_index(i,pHead);
		while(1)
		{
			if(size<=ptmp->mem_size)
			{
				init_s(&pp,sizeof(sRecord));	
				get_fail_chain(ppp,pp);
				ptmp1 = find_mem(size,pHead);

				if(ptmp1==NULL)
				{
						ptmp->mem_size =  ptmp->mem_size - size;
						init(&ptmp1,sizeof(sNode));
						pp->pdata = ptmp1;
						ptmp1->mem_size = size;
						ptmp1->index = i;
						creat_free_chain(free_begin,ptmp1);
						return ;
				}
				else
				{
						pp->pdata = ptmp1;
						destory_chain(ptmp1);
						creat_free_chain(free_begin,ptmp1);
						return ;
				}

			}	
			else
			{
					//让记录结构体成员记录位置
					init_s(&pp,sizeof(sRecord));
					get_fail_chain(ppp,pp);
					pp->pdata = ptmp;	
					destory_chain(ptmp);
					creat_free_chain(free_begin,ptmp);
					size = size - ptmp->mem_size;
					i = max_mem(pHead);
					printf("i2=%d\n",size);
					ptmp = find_index(i,pHead);

			}		
		}

}
void apply(pNode pHead)//申请空间
{
		int size;
		init_s(ppp+count,sizeof(sRecord));//给记录结构体开空间
		printf("请输入需要的内存大小\n");//输入申请的空间
 		printf("sum=%d\n",pHead->mem_size);
		scanf("%d",&size);
		if(size > pHead->mem_size)//判断申请空间是否超过剩余空间
		{
				printf("申请的内存过大\n");
				exit(-1);
		}
		else
		{
				creat_chain(size,pHead,ppp[count]);//给申请的开空间
		}
		count++;
}
