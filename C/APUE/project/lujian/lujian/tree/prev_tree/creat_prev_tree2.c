/*********字符串先序**********/

#include<stdio.h> 
#include<stdlib.h>
#define  TURE   (1) 
#define  FALSE  (-1) 
#define  N      (100)
typedef struct Tree
{
	
	char data;
	struct Tree* pa;
	struct Tree* lc;
	struct Tree* rc;


}Stree, *Ptree;


int creat_tree(Ptree* proot, char*arr);
int show_tree(Ptree proot);
int prev_sort(Ptree proot);
int mid_sort(Ptree proot);
int back_sort(Ptree proot);
int init_node(Ptree*p);
int creat_memory(void ** q, int size);
int main()
{
	Ptree proot =NULL;
	char arr[N];
	printf("please input arr  \n"); 
	gets(arr);

	creat_tree(&proot, arr);

	if (NULL == proot)
	{
		printf("nuil tree \n");
	   	exit(-1);	
	}

	else 
	{
		show_tree(proot);
	}


	return TURE; 
}

int creat_tree(Ptree* proot, char* arr)
{
	static int i=-1;
	i++;
	if (arr[i] == ' ')
	{
		*proot = NULL;
	}	
	else if(*arr !='\0')
	{
		init_node(proot);
		(*proot)->data = arr[i];
		creat_tree(&(*proot)->lc,arr);
		creat_tree(&(*proot)->rc,arr);
	}	

}

int show_tree(Ptree proot)
{
	printf("prev======== \n"); 
	
	prev_sort(proot);
	
	putchar(10);
	printf("mid======= \n"); 
	mid_sort(proot);

	putchar(10);
	printf("mid======= \n"); 
	back_sort(proot);
	putchar(10);

	return TURE; 
}

int prev_sort(Ptree proot)
{
	printf("%c ", proot->data); 

	if (proot->lc !=NULL)
	{
		prev_sort(proot->lc);
	}
	
	if (proot->rc !=NULL)
	{
		prev_sort(proot->rc);
	}

	return TURE; 
}

int mid_sort(Ptree proot)
{

	if (proot->lc !=NULL)
	{
		mid_sort(proot->lc);
	}

	printf("%c ", proot->data); 
	
	if (proot->rc !=NULL)
	{
		mid_sort(proot->rc);
	}

	return TURE; 
}


int back_sort(Ptree proot)
{

	if (proot->lc !=NULL)
	{
		back_sort(proot->lc);
	}
	
	if (proot->rc !=NULL)
	{
		back_sort(proot->rc);
	}
	printf("%c ", proot->data); 

	return TURE; 
}

int init_node(Ptree*p)
{
	creat_memory((void**)p, sizeof(Stree));
	
	(*p)->pa =(*p)->lc =(*p)->rc =NULL;
	
	return TURE; 
}

int creat_memory(void ** q, int size)
{
	*q = malloc(size);

	if (NULL  == *q)
	{
		printf("malloc fail \n");
	
	   	return FALSE;  	
	}


	return TURE; 
}