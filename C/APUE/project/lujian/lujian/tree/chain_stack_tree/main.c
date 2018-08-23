/**************
 *
 * 二叉树 三种便利方式的 （非递归 链栈）
 *
 *
 *
 *
 *
 * *************/

#include"main.h"

int main()
{
	char arr[N];

	Ptree proot =NULL;
	Ssta sta;
	Psta ps = &sta;
	init_stack(ps);

	printf("please input arr\n"); 
	gets(arr);
	creat_tree(&proot, arr);
	if (proot == NULL)
	{
		printf("nuil tree \n");
	   	exit(-1);	
	}
	show_tree(proot, ps);

	return TURE; 
}

int creat_tree(Ptree* proot, char* arr)
{
	static int i = -1;
	i++;
	if (arr[i] == ' ')
	{
		proot = NULL;
	}
	
	else if( arr[i] != '\0')
	{
		ma_init_node(proot);
		(*proot)->data = arr[i];
		creat_tree(&(*proot)->lc, arr);
		creat_tree(&(*proot)->rc, arr);
	}
		
	return TURE; 
}

int ma_init_node(Ptree * p)
{
	creat_memory((void**)p, sizeof(Stree));
	
	(*p)->lc = (*p)->rc =NULL;
	
	return TURE; 
}

int show_tree(Ptree proot, Psta ps)
{
	printf("prev==========\n");	
	prev_tree(proot, ps);
	
	putchar(10);
	printf("mid==========\n");	
	mid_tree(proot, ps);
	putchar(10);
	
	printf("back==========\n");	
	back_tree(proot, ps);
	putchar(10);
}
#if 1

/**********************************/

int prev_tree(Ptree proot, Psta ps)
{

	Ptree pop_node, p = proot;
	int flag =0;

	while(p!=NULL || ps->bottom->next !=ps->bottom)
	{
			while(p!=NULL)
			{		
						
					printf("%c ",p->data);
					push(ps, p);
					p =p->lc;
			}

			pop(ps,&pop_node);
			p = pop_node->rc;

	}

}

#endif 


#if 1
/*******************************/

int mid_tree(Ptree proot, Psta ps)
{
	Ptree pop_node, p = proot;
	int flag =0;

	while(p!=NULL || ps->bottom->next !=ps->bottom)
	{
			while(p!=NULL)
			{
					push(ps, p);
					p =p->lc;
			}	
			pop(ps,&pop_node);
			printf("%c ",pop_node->data);
			p = pop_node->rc;

	}

}

#endif

#if 1

/*************************************/

int back_tree(Ptree proot, Psta ps)
{
	
	Ptree pop_node =NULL, p = proot;
	while(p!=NULL || ps->bottom->next !=ps->bottom) //右子树 为空 且 栈空 跳出循环
	{
			while(p!=NULL)
			{
					push(ps, p);
					p =p->lc;
			}	
			p = ps->top->data;  //获得栈顶指针

			if ( p->rc == NULL || pop_node == p->rc) //判断节点是否出栈 1 它的右子为空 2 它的右子已经出栈访问过
			{		
				pop(ps,&pop_node);                  //出栈
				printf("%c ",pop_node->data);
				p =NULL;
			}
			else
			{
				p = p->rc;
			}

	}

}
#endif









