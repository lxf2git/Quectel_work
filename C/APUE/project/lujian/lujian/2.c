/***************;;;**********************
  作业：基数排序

  0     1   2     3    4          5   6   7          8       9
  800     111    893  234         045                 108    219 
  120 
  080

  typedef struct node
  {
  int data;
  struct node *prev;
  struct node *next;
  }sNode,*pNode;

  typedef struct dis_chain
  {
  pNode record;

  struct dis_chain*nex()
  }sDisChain,*pDisChain;

  num = judge_num();
  for(i<num)
  {
  distribute();
  collected();	
}

 *
 * ****************************************/

#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
#include"destroy.h"
#define  TURE   (1) 
#define  FALSE  (0) 
#define  N       (5)
#define  M       (11)     


int creat_memory(void** p ,int size);
int init_node(Pnode* p);
int creat_chain_data(Snode* phead);
int creat_chain_flag(Snode* phead);
int out_put(Snode* phead);
int add_back(Snode* pos, Snode* pin);
int out_put(Snode* phead);
int judge_num(Snode* phead);
int count_digit(int num);
int  distribute(Snode* phead_da, Snode* phead_fg, int i);
Snode* delete_prev(Snode* pos);
int count_bit(Snode*pel, int i);
Snode* find_ptail(Snode* ptravl);
int add_flag(Snode* phead_fg, Snode* pdel, int bit);
int collected(Snode* phead_da, Snode* phead_fg);

/**********主函数*****************/

int main()
{
	int i = 0 ; 
	static int num;
	Snode* phead_da;
	Snode* phead_fg;
	
	init_node(&phead_da);
	init_node(&phead_fg);

	creat_chain_data(phead_da);
	creat_chain_flag(phead_fg);
	

	num = judge_num(phead_da);
	printf("bf sort==================== \n"); 
	out_put(phead_da);


	for (i=0; i<num; i++)
	{
			distribute(phead_da, phead_fg,i);
			collected(phead_da, phead_fg);
			printf("the %dtime sort:result: \n",i+1); 
			out_put(phead_da);
			printf("\n" ); 
	}
			
			printf("=============================\n");
			out_put(phead_da);
			printf("==============================\n"); 

/*********释放函数****************/
	destroy(&phead_fg);
	destroy(&phead_da);

	return TURE; 
}


/**********初始化********************/

int init_node(Pnode* p)
{
	
	creat_memory((void**)p,sizeof(Snode));

	(*p)->prev = (*p);
	(*p)->next = (*p);

	return TURE; 
}

int creat_memory(void** p ,int size)
{

		(*p) = malloc(size);
		
		if (NULL == (*p))
		{
			printf("malloc error  \n"); 

			return FALSE;  
		}
	
	return TURE; 
}

/********建立数据链表**************/

int creat_chain_data(Snode* phead)
{
	Snode* pnew = NULL;
	Snode* ptail= phead;
	int i = 0;

	for (; i<N; i++)
	{
		init_node(&pnew);
		printf("please input data\n"); 
		scanf("%d",&pnew->data);
	   	add_back(ptail, pnew);
		ptail = pnew;	
	}


	return TURE; 
}

/*******建立标记的链表************/

int creat_chain_flag(Snode* phead)
{
	Snode* pnew = NULL;
	Snode* ptail = phead;
	int i =0;

	for (i =0; i<10; i++)
	{
		init_node(&pnew);
		pnew->data = i;
		add_back(ptail, pnew);
		ptail = pnew;
		
/********注意建立挂起双向的链表的前驱是指向自己的***********/

		pnew->prev =pnew;

	}

	return TURE; 
}


/********尾插节点*****************/

int add_back(Snode* pos, Snode* pin)
{
		if (NULL == pos || NULL == pin)
		{
			return FALSE;  
		}
		
		pin->prev = pos;
		pin->next = pos->next;
		pos->next->prev = pin;
	  	pos->next = pin;	

		return TURE; 
}

/**********打印函数****************/

int out_put(Snode* phead)
{
	Snode* ptmp;

	for ( ptmp = phead->next; ptmp !=phead; ptmp =ptmp->next )
	{

		printf("%d ", ptmp->data); 
	}
	putchar(10);

	return TURE; 

}

/**********判断最大位数***********/

int judge_num(Snode* phead)
{

		int max = phead->next->data; 
		Snode* ptmp; 

		for (ptmp = phead->next; ptmp != phead; ptmp = ptmp->next)
		{
			if (max < ptmp->data)
			{
				max = ptmp->data;
			}
		}
		
	return count_digit(max);
}

int count_digit(int num)
{
		int i, temp , shi = 1;

		for (i = 0;num !=temp; i++)
		{
				shi *=10;
				temp = num%shi;

		}

		return (i) ;

}


/******** 分发 函数***************/

int  distribute(Snode* phead_da, Snode* phead_fg, int i)
{
		
		Snode* pdel =NULL;
		int re;
		while(phead_da->prev !=phead_da)
		{
			pdel = delete_prev(phead_da);
			re = count_bit(pdel, i);	
			add_flag(phead_fg,pdel, re);
		}

		return TURE; 

}

/*************尾删***************/
Snode* delete_prev(Snode* pos)
{
		if (NULL == pos)
		{   
				return NULL;  
		}   
		Snode* pdel = pos->prev;

		pos->prev = pdel->prev;

		pdel->prev->next = pos;

		pdel->next = pdel;
		pdel->prev = pdel;

		return pdel; 
}
/************计算各个位的大小********/

int count_bit(Snode*dpel, int i)
{
		int bit;
	bit =	(((dpel->data)/((int)(pow(10,i))))%10);
	return bit; 
}
/***********挂到标记链表phead_fg**********/

int add_flag(Snode* phead_fg, Snode* pdel, int bit)
{
		Snode* ptravl = phead_fg;
		Snode* ptail =NULL;
		while(ptravl->next != phead_fg)
		{
			if (bit == ptravl->next->data)
			{
				ptail = find_ptail(ptravl->next);
				add_fg(ptail , pdel);
			}
			ptravl = ptravl->next;
		}

		return TURE; 
}

int add_fg(Snode* ptail , Snode* pdel)
{
			
		pdel->next = ptail;
		ptail->prev = pdel;
	
		return TURE; 
}
/**********查找挂在标记链表上的数据链表的最后一个节点**** 没有返回自己节点***/

Snode* find_ptail(Snode* ptravl)
{
	while(ptravl->prev != ptravl)
	{
		ptravl = ptravl->prev;
		
	}			

	return ptravl; 

}

/**************收集函数**********************/

int collected(Snode* phead_da, Snode* phead_fg)
{
		int i =0;
		Snode* ptmp_fg = phead_fg;
		Snode* ptmp_gg;
		Snode* ptail = NULL;
		 Snode* pf[M] = {NULL};
		 Snode* pt[M] = {NULL};

/**********收集挂在标记链表的数据链表的头节点 和尾节点***********/

		while(ptmp_fg->next != phead_fg)
		{
			ptail =	find_ptail(ptmp_fg->next);
			if (ptail != ptmp_fg->next)
			{
				pf[i] = ptail;
				pt[i] = ptmp_fg->next;
				i++;
			}
		
				ptmp_fg = ptmp_fg->next; 
		}	
/**********建立起新的双向数据链表***************/

/*************头指针插入第一个数据节点*********/

		pf[0]->prev =phead_da;
		phead_da->next =pf[0];

/***********链接节点**************************/
		for(i=0; pf[i] !=NULL && pt[i] !=NULL; i++)
		{
		
				if (pf[i+1] !=NULL || pt[i+1] !=NULL)
				{
				pt[i]->prev->next = pf[i+1];
				pf[i+1]->prev = pt[i]->prev;
				}
				else
				{
				pt[i]->prev->next = phead_da;
				phead_da->prev = pt[i]->prev;
				}
		}
/***********复原标记链表 节点的前驱 指向自己************/

		ptmp_gg = phead_fg;
	
		while(ptmp_gg->next != phead_fg)
		{	
				ptmp_gg->next->prev = ptmp_gg->next;

				ptmp_gg = ptmp_gg->next;
			
		}
		ptmp_gg->prev = ptmp_gg;
		
		return TURE;

}
				






