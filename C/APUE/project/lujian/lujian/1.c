/***************************************
   雅虎笔试
   有两个双循环链表A，B 他们的头指针为pHeadA pHeadB 请写一个函数将两个链表中的data值相同的结点删除
  18 1  6
  19 2  9
 	
 注意链表删除后 不能引用了
 
 * *************************************/

#include<stdio.h> 
#include<stdlib.h>
#define  TURE   (1) 
#define  FALSE  (0) 
#define  N       (3)

typedef struct Date_compare
{

	int data;
	struct Date_compare* prev;
	struct Date_compare* next;

}Sdata, *Pdata;


int init_node(Pdata* p);
int creat_memory(void** p , int size);
int creat_chain(Sdata* phead);
int add_back(Sdata* pos, Sdata* pin);
int destroy_node(Pdata* phead);
int delete_node(Sdata* pos);
int myfree(Pdata* p);
int out_put(Sdata* phead);
int delete_same_node(Sdata* pheada, Sdata* pheadb);

/***************主函数****************/

int main()
{
	Sdata* pheada, *pheadb;	

	init_node(&pheada);
	init_node(&pheadb);
	
	printf("please input pheada data:\n"); 
	creat_chain(pheada);
	printf("please input pheadb data:\n"); 
	creat_chain(pheadb);



	printf("bf delete a b ======================== \n"); 
	out_put(pheada);
	out_put(pheadb);

	delete_same_node(pheada, pheadb);


	printf("after delete======================= \n"); 
	printf("a lib: \n"); 
	out_put(pheada);
	printf("b lib:=============================\n");
	out_put(pheadb);



	destroy_node(&pheada);
	destroy_node(&pheadb);

	return TURE; 

}

/*****************初始化*****************/

int init_node(Pdata* p)
{
		creat_memory((void**)p, sizeof(Sdata));

		(*p)->prev =(*p);
		(*p)->next =(*p);

		return TURE; 
}
int creat_memory(void** p , int size)
{
	(*p) = malloc(size);

	if (NULL == *p)
	{
		printf("malloc error \n");

		return FALSE;  	
	
	}
	return TURE; 
}

/**********建立链表*********/

int creat_chain(Sdata* phead)
{
	Sdata* pnew =NULL;
	Sdata* ptail= phead;
	int i=0;
	for (; i<N; i++)
	{
		init_node(&pnew);
		printf("please input data\n"); 
		scanf("%d",&pnew->data);

/*********后插节点************/

		add_back(ptail, pnew);
		ptail = pnew;
	}

	return TURE; 
}

/****** 后插节点子函数***********/

int add_back(Sdata* pos, Sdata* pin)
{
	if (NULL == pos || NULL == pin)
	{
		return FALSE;  
	}
	
	pin->prev = pos;
	pin->next = pos->next;
	pos->next->prev = pin;
	pos->next = pin;
}

/***********打印***************/

int out_put(Sdata* phead)
{
		Sdata* ptmp = phead;
		for (ptmp = phead->next;ptmp !=phead;ptmp = ptmp->next)
		{
				printf("%d ", ptmp->data); 
		}
		printf("\n");

		return TURE; 
}


/*************删除相同的节点**************/

#if 1
int delete_same_node(Sdata* pheada, Sdata* pheadb)
{
		int tmpa[N], tmpb[N];
	 	int i=0;
		Sdata* ptmpa = pheada;
		Sdata* ptmpb = pheadb;
		Sdata* psavea =NULL;
		Sdata* psaveb =NULL;

/****************保存链表a 中的数据****************/

		for (ptmpa = pheada->next; ptmpa != pheada; ptmpa= ptmpa->next)
		{
			tmpa[i++] = ptmpa->data;
		}
		
		i = 0;
/**************保存连表 b 中的数据*****************/

		for (ptmpb = pheadb->next; ptmpb != pheadb; ptmpb =ptmpb->next)
		{
			tmpb[i++] =ptmpb->data; 
		}
/**************删除 与a 相同的 b链表的节点*********/

		for (i=0; i<N; i++)
		{
		
			for (ptmpb = pheadb->next; ptmpb != pheadb; )
			{
					
					if (tmpa[i] == ptmpb->data)
					{
						psaveb = ptmpb; //注意
						ptmpb =ptmpb->next;
						delete_node(psaveb->prev);				
					}
					else
					ptmpb = ptmpb->next;
			}
		}
/***********删除 与 b 相同的 a链表的节点***********/

		for (i=0; i<N; i++)
		{
		
			for (ptmpa = pheada->next; ptmpa != pheada; )
			{
					
					if (tmpb[i] == ptmpa->data)
					{
						psavea = ptmpa;     //注意
						ptmpa =ptmpa->next; //
						delete_node(psavea->prev);
					}
					else
					ptmpa = ptmpa->next;
			}
		}

	
		return TURE; 
}
#endif

/**********删除并释放***************/

int destroy_node(Pdata* phead)
{
	while((*phead)->next != (*phead))
	{
		delete_node(*phead);

	}
	
	myfree(phead);
}

/*********删除节点**************/
int delete_node(Sdata* pos)
{
	if (NULL == pos)
	{
		return FALSE;  
	}
	Sdata* pdel = pos->next;
	

	pos->next = pdel->next;

	pdel->next->prev = pos;

	pdel->next = pdel;

	pdel->prev = pdel;


	myfree(&pdel);
	 
	return TURE; 
}
/***********释放函数***********/

int myfree(Pdata* p)
{
	if (NULL != (*p))
	{
		free(*p);
		(*p) = NULL;
	}

	return TURE; 
}











