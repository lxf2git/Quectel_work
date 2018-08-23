/********************
 *
 * 层次便利 链表队列
 *
 1 尾插 并赋值（入队）
 2 头删	返回值（出队）
 *
 *
 * ******************/

#include"main.h"

int main()
{
	char arr[SIZE];
	Ptree proot =NULL;
	printf("please input arr \n"); 
	gets(arr);
	

	creat_tree(&proot, arr);

	if (NULL == proot)
	{
		printf("nuil tree\n");
	   	exit(-1);	
	}	
	show_tree(proot);

	return TURE; 
}

int creat_tree(Ptree* proot, char* arr)
{
	static int i =-1;
	i++;
	if (arr[i] == ' ')
	{
		*proot =NULL;
	}

	else if (arr[i] !='\0')
	{
		init_tree(proot);

		(*proot)->data = arr[i];

		creat_tree(&(*proot)->lc, arr);
		creat_tree(&(*proot)->rc, arr);
	}
	
	return TURE; 
}

int init_tree(Ptree* p)
{
	creat_memory((void**)p, sizeof(Stree));

	(*p)->lc =(*p)->rc = NULL;

	return TURE; 
}
int show_tree(Ptree proot)
{
	printf("level_order ============\n");
	level_order(proot);
	printf("\n");

	return TURE; 
}


/***************层次便利*************/
	
int level_order(Ptree proot)
{
		Pnode phead;

		Ptree p = proot;

		Ptree pop_pnode =NULL;

		init_node(&phead);

		en_queue(phead, p); //根 入队列

		while(judge_queue(phead) != EMPTY) // 队列为空 跳出
		{
				de_queue(phead,&pop_pnode);  //出队列
				p = pop_pnode;
				printf("%c  ", p->data); 
				if ( p->lc  !=NULL)        //如果出队列的左右子 不为空 入队列
				{	
						en_queue(phead, p->lc);
				}
				if (p->rc !=NULL)
				{
						en_queue(phead, p->rc);
				}
		}

			return TURE; 
}











