#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int num;
	struct st *prev;
	struct st *next;
}sStu,*pStu;
void my_free(void **q)
{
		if(*q!=NULL)
		{
				free(*q);
				*q=NULL;
		}
}
void create_memory(pStu *pnode)
{
	*pnode = (pStu)malloc(sizeof(sStu));
	if(NULL==*pnode)
	{
		printf("malloc fail");
		exit(-1);
	}
}
void init_node(pStu *pnode)
{
	create_memory(pnode);
	(*pnode)->next = *pnode;
	(*pnode)->prev = *pnode;
}
//开空间，并让链表的的头和尾指向本身
pStu chain_max(pStu pHead,pStu pnew)
{
		pStu pp=pHead;
		while(pp->next!=pHead)
		{
				if(pp->next->num >=pnew->num)
				{
						return pp;
				}
				pp = pp->next;	
		}
		return pp;
}
//把新加入链表的值按从小到大的顺序插入
void creat_tail_chain(pStu pHead)
{
		int i,n;
		pStu pnew=NULL;
		pStu pp=NULL;
		printf("请输入个数\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{		
			init_node(&pnew);
			printf("请输入数字:\n");
			scanf("%d",&pnew->num);
			pp = chain_max(pHead,pnew);
			pp->next->prev = pnew;
			pnew->prev = pp;
			pnew->next = pp->next;
			pp->next = pnew;
		}
}
//按尾差的方式链接链表
void show_chain(pStu pHead)
{
		pStu ptmp=NULL;
		for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
		{
				printf("%d ",ptmp->num);
		}
}
//打印出排好的链表
void destory_chain(pStu *pHead)
{
        pStu pdel=(*pHead)->next;
        while(pdel!=(*pHead))
        {   
                pdel->next->prev = (*pHead);
                (*pHead)->next = pdel->next;
                pdel->next = pdel;
                pdel->prev = pdel;
                my_free((void **)&pdel);
                 pdel=(*pHead)->next;
        }   
        my_free((void **)pHead);
}
//把剩余链表的空间释放
void destory_link(pStu pp)
{
		pStu ptmp=(pp)->next;
        ptmp->next->prev = (pp);
        (pp)->next = ptmp->next;
        ptmp->next = ptmp;
        ptmp->prev = ptmp;
		printf("ptmp->num:%d\n",ptmp->num);
		my_free((void **)&ptmp);
}
//把两链表去掉相同的数据进行释放空间
void chain_compare(pStu pHeadA,pStu pHeadB)
{
		pStu pa=pHeadA;
		pStu pb=pHeadB;
		int i=0;
		while(pa->next!=pHeadA)
		{		i=0;
				printf("pa->next:%d\n",pa->next->num);
				while(pb->next!=pHeadB)
				{
						printf("pb1->next:%d\n",pb->next->num);
						if(pa->next->num==pb->next->num)
						{
								i++;
								destory_link(pb);
								continue;
						}
						pb = pb->next;
						printf("pb2->next:%d\n",pb->next->num);
				}
				if(i!=0)
				{
						while(pa->next->num == pa->next->next->num)
						{
								destory_link(pa);
						}
						destory_link(pa);
						pb=pHeadB;
						continue;
				}
				pa =pa->next;
				pb = pHeadB;
		}
}
//把两链表的相同的数据去掉
int main()
{
		pStu pHeadA=NULL;	
		pStu pHeadB=NULL;	
		init_node(&pHeadA);  
		init_node(&pHeadB);
		creat_tail_chain(pHeadA);
		creat_tail_chain(pHeadB);
		chain_compare(pHeadA,pHeadB);
		show_chain(pHeadA);
		show_chain(pHeadB);
		destory_chain(&pHeadA);
		destory_chain(&pHeadB);
		return 0;
}
