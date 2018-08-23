#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	struct tree *lc;
	struct tree *rc;
	char data;
}sTree,*pTree;

void init_node(pTree *node)
{
	*node=(pTree)malloc(sizeof(sTree));
	if(*node==NULL)
	{
		printf("malloc faied");
		exit(-1);
	}

		(*node)->lc=NULL;
		(*node)->rc=NULL;
}
void creat_tree(pTree *root)
{
	char ch;
	scanf("%c",&ch);
	getchar();
	if(ch==' ')
	{
		*root=NULL;
	}
	else
	{
		init_node(root);
		(*root)->data=ch;
		creat_tree(&(*root)->lc);
		creat_tree(&(*root)->rc);
	}
}
void pre_show(pTree root)
{
	printf("%c ",root->data);
	if(root->lc!=NULL)
	{
		pre_show(root->lc);
	}
	if(root->rc!=NULL)
	{
		pre_show(root->rc);
	}
}
void mid_show(pTree root)
{
	if(root->lc!=NULL)
	{
		mid_show(root->lc);
	}
	printf("%c ",root->data);
	if(root->rc!=NULL)
	{
		mid_show(root->rc);
	}
}

void last_show(pTree root)
{
	if(root->lc!=NULL)
	{
		last_show(root->lc);
	}
	if(root->rc!=NULL)
	{
		last_show(root->rc);
	}
	printf("%c ",root->data);
}
void show_tree(pTree root)
{
	puts("=====prev trav=====");
	pre_show(root);

	puts("=====mid trav======");
	mid_show(root);

	puts("=====last trav=====");
	last_show(root);
	printf("\n");
}
int main()
{
	pTree root=NULL;
	creat_tree(&root);
	if(root==NULL)
	{
		printf("null tree\n");
		exit(-1);
	}
	show_tree(root);
	return 0;
}
