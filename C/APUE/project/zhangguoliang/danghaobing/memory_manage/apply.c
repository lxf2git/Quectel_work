#include"apply.h"

void create_memory(void **p,int size)
{
		*p = malloc(size);
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}

void init_Node(pMem *p,int indx,int size)
{
		create_memory((void **)p,sizeof(sMem));
		(*p)->index = indx;
		(*p)->mem_size = size;
		(*p)->prev = (*p);
		(*p)->next = (*p);
}

void creat_chain(pMem pHead,int indx,int size)
{
		pMem pnew;
		init_Node(&pnew,indx,size);
		pHead->mem_size += size;
		pnew->next = pHead;
		pnew->prev = pHead->prev;
		pHead->prev->next = pnew;
		pHead->prev = pnew;
}

void init_Memory(pMem pHead)
{
	int i;
	for(i=1;i<=N;i++)
	{
		creat_chain(pHead,i,M);//每个空间size=10；开N个；
	}
}

pMem find_max(pMem pHead,int *x)
{
		pMem ptmp,pmax;
		pmax = pHead->next;
		ptmp = pHead->next;
		while(ptmp!=pHead)
		{
				if(ptmp->mem_size == *x)
				{
						pmax = ptmp;
						ptmp->prev->next=ptmp->next;
						ptmp->next->prev=ptmp->prev;
						*x=0;
						return pmax;
				}
				if(ptmp->mem_size > pmax->mem_size)
				{
						pmax = ptmp;
				}
				ptmp=ptmp->next;
		}
		if(*x>pmax->mem_size)
		{
				ptmp = pmax;
				ptmp->prev->next=ptmp->next;
				ptmp->next->prev=ptmp->prev;
				*x -= ptmp->mem_size;
				return pmax;
		}
		if(*x<pmax->mem_size)
		{
			pmax->mem_size -= *x;
			init_Node(&pmax,pmax->index,*x);
			*x=0;
			return pmax;
		}
	return pmax;		
}

void apply(pMem pHead,pMem pFead,pRc pRead)
{
		int x;
		printf("please input memory you'll use:\n");
		scanf("%d",&x);
		//先找最大，再找相等
		if(x>pHead->mem_size)
		{
				printf("memory is not enough!\n");
				return ;
		}
		pHead->mem_size -= x;
		pFead->mem_size += x;
		int i=0;//记录每次数据个数
		pRc pRnew;
		init_Rnode(&pRnew);
		while(x!=0)
		{
				pMem ret = find_max(pHead,&x);
				printf("ret:index:%d ret:size:%d\n",ret->index,ret->mem_size);
				pMem ptmp = pFead;
				while(1)
				{
					if(ptmp->next->mem_size >= ret->mem_size||ptmp->next==pFead)
					{
						ret->next = ptmp->next;
						ret->prev = ptmp;
						ptmp->next->prev = ret;
						ptmp->next = ret;
						break;
					}
					ptmp=ptmp->next;
				}
				if(i>0)
				{
						pRnew->pdata = realloc(pRnew->pdata,(i+1)*sizeof(pMem));
				}
				pRnew->pdata[i] = ret;
				i++;
				
		}
				pRead->prev->next = pRnew;
				pRnew->next = pRead;
				pRnew->prev = pRead->prev;
				pRead->prev = pRnew;
		//		printf("%p %p %p\n",pRead,pRead->next,pRead->next->next);
}















