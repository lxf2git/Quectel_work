/******************************************
 *
 *作业：先序建立二叉树 （根左右）
 并以1 先序便利打印
 	2 中序便利打印
	3 后序便利打印

 * ****************************************/



#include<stdio.h> 
#include<stdlib.h>
#define  N      (100)
#define  FALSE  (-1) 
#define  TURE   (1) 
typedef  struct Tree
{
	char tr_ch;
	struct Tree* tr_pa;
	struct Tree* tr_lc;
	struct Tree* tr_rc;

}Stree, *Ptree;

enum Menu
{
	prev=1,
	mid,
	back,
	ex,

};

int prev_sort(Ptree proot);
int mid_sort(Ptree proot);
int back_sort(Ptree proot);
int init_node(Ptree* p);
int show_tree(Ptree proot);
int creat_memory(void** p , int size);
Ptree add_tree(Ptree proot, char ch);

/********主函数************/

int main()
{

	char arr[N];

	int i=0;

	Ptree proot =NULL;

	init_node(&proot);
	
	printf("please arr  \n"); 
	
	gets(arr);
	creat_tree(proot, arr);
	show_tree(proot);
	return TURE;  
}

/*******创建先序二叉树********/

int creat_tree(Ptree proot, char* arr)
{
	int i=0;
	char ch;
	if(ch ==' ')
	{
		return FALSE;  
	}

	proot->tr_ch = *arr; //根节点赋值

	for (i=1; arr[i] !='\0'; i++)
	{	
		proot = add_tree(proot, arr[i]); //返回
	}
	
	return TURE; 
}

/********添加树节点（根左右）************/

Ptree  add_tree(Ptree proot, char ch)
{
		static int flag = 0; //定义标记位

		if (flag==0)     // 左
		{ 
				if (ch != ' ')
				{
						if (proot->tr_lc ==NULL)
						{
								{
										init_node(&proot->tr_lc); //建立根节点
										proot->tr_lc->tr_ch = ch;
										proot->tr_lc->tr_pa = proot;
										 return proot->tr_lc; //返回根节点
								}
						}
				}
				else
				{
						flag++; // 切换到右
						return proot;
				}
		}

		else if(flag ==1) //右  根的左子树为空 转换到 根的右子树（右子树 作为根）
		{

				if (ch != ' ') //如果字符不是' ';
				{
						if (proot->tr_rc == NULL)
						{

								init_node(&proot->tr_rc); //建立根节点
								proot->tr_rc->tr_ch = ch;
								proot->tr_rc->tr_pa = proot;
								flag =0;                  //转换到 根的左子树
								return proot->tr_rc; 	//返回子根
						}

				}
				else					// 字符为空 
				{
					flag++;				//标记位加+1
					return proot;		//返回 根节点
				}
		}
		else  // 根的左右均为空
		{	
				if (proot->tr_pa->tr_rc ==NULL)// （递归返回）如果根的父的右子树为空
				{
					flag = 1;            		// 切换的子的父的右子树
					add_tree(proot->tr_pa, ch); 
				}
				else                          // 如果子的父亲的右子树不为空
				{ 
					add_tree(proot->tr_pa, ch); // 继续递归
				}
		}
		
}

/******节点初始化*******************/

int init_node(Ptree* p)
{
	creat_memory((void**)p, sizeof(Stree));

	(*p)->tr_pa = (*p)->tr_lc =(*p)->tr_rc =NULL;

	return TURE; 
}

int creat_memory(void** p , int size)
{
	*p = malloc(size);

	if (NULL == *p)
	{
		printf("malloc error \n");
		return FALSE;  
	}
	
	return TURE; 
}

/********打印*****************/

int show_tree(Ptree proot)
{
		int choose;
		while(1)
		{
				printf("please choose 1 prev_sort 2 mid_sort 3 back_sort 4 exit\n"); 
				scanf("%d",&choose);
				switch(choose)
				{
						case prev:  prev_sort(proot);putchar(10);break;
						case mid:	mid_sort(proot);putchar(10);break;
						case back: back_sort(proot);putchar(10);break;
						case ex: exit(-1);
						default : printf("please input  again\n"); break;
				}
		}
		return TURE; 
}

/******前中后便利打印***********/

int prev_sort(Ptree proot)
{
	printf("%c  ", proot->tr_ch);
	
	if (proot->tr_lc !=NULL)
	{
		prev_sort(proot->tr_lc);
	}
	if (proot->tr_rc !=NULL)
	{
		prev_sort(proot->tr_rc);
	}

	return TURE; 
}

int mid_sort(Ptree proot)
{
	if (proot->tr_lc !=NULL)
	{
		mid_sort(proot->tr_lc);
	}

	printf("%c  ", proot->tr_ch);

	if (proot->tr_rc !=NULL)
	{
		mid_sort(proot->tr_rc);
	}

	return TURE; 
}

int back_sort(Ptree proot)
{
		if (proot->tr_lc !=NULL)
		{
				back_sort(proot->tr_lc);
		}
		if (proot->tr_rc !=NULL)
		{
				back_sort(proot->tr_rc);
		}

		printf("%c  ", proot->tr_ch);

		return TURE; 
}

