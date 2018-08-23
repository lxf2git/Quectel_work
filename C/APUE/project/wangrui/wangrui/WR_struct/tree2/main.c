#include"tree2.h"
int i=0;
char trr[N]={};
int main()
{
	pTree proot = NULL;
	scanf("%s",trr);
	creat_tree(&proot);
	show_tree(proot);
	return 0;
}
void creat_tree(pTree *p)
{
	if(trr[i] != '-'&&trr[i]!=10&&trr[i]!=0)
	{
		init_tree(p);
		(*p)->data = trr[i];
		i++;
		creat_tree(&(*p)->left);
		if((*p)->left != NULL)
		{
			(*p)->left->parent = *p;
		}
		i++;
		creat_tree(&(*p)->right);
		if((*p)->right != NULL)
		{
			(*p)->right->parent = *p;
		}
	}
	else
	{
		*p = NULL;
	}
}
void show_tree(pTree proot)
{
	pStack psta = NULL;
	init_stack(&psta);	//建立栈
	pQueue pque = NULL;
	init_queue(&pque);	//建立队列
	
	pre_tree(psta,proot);
	printf("\n");
	mid_tree(psta,proot);
	printf("\n");
	last_tree(psta,proot);
	printf("\n");
	queue_tree(pque,proot);
	printf("\n");
}
/*
void pre_tree(pTree p)
{
	printf("%c ",p->data);
	if(p->left != NULL)
	{
		pre_tree(p->left);
	}
	if(p->right != NULL)
	{
		pre_tree(p->right);
	}
}
void mid_tree(pTree p)
{
	if(p->left != NULL)
	{
		mid_tree(p->left);
	}
	printf("%c ",p->data);
	if(p->right != NULL)
	{
		mid_tree(p->right);
	}
}
void last_tree(pTree p)
{
	if(p->left != NULL)
	{
		last_tree(p->left);
	}
	if(p->right != NULL)
	{
		last_tree(p->right);
	}
	printf("%c ",p->data);
}*/
void init_tree(pTree *p)
{
	creat_memory((void **)p,sizeof(sTree));
	(*p)->left = NULL;
	(*p)->right = NULL;
	(*p)->parent = NULL;
}
void creat_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}
void free_memory(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
