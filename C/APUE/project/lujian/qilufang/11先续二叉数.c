#include<stdio.h>
#include<stdlib.h>
typedef struct Tree 
{
	char data;
	struct Tree *lc;
	struct Tree *rc;
}sTree,*pTree;
void init_tr(pTree *p)
{
	*p=malloc(sizeof(sTree));
	if(*p==NULL)
	{
		printf("getmemroy_error!\n");
		exit(-1);
	}
	(*p)->lc=NULL;
	(*p)->rc=NULL;
}
void creat_tr(pTree *root)
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
		init_tr(root);
		(*root)->data=ch;
		creat_tr(&(*root)->lc);
		creat_tr(&(*root)->rc);
	}
}
void prev_show(pTree root)
{
	printf("%c ",root->data);
	if(root->lc!=NULL)
	{
		prev_show(root->lc);
	}
	if(root->rc!=NULL)
	{
		prev_show(root->rc);
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
void show(pTree root)
{
	printf("prev_show:\n");
	prev_show(root);
	printf("\n");
	printf("mid_show:\n");
	mid_show(root);
	printf("\n");
	printf("last_show:\n");
	last_show(root);
	printf("\n");
}
int main()
{
	pTree root=NULL;
	creat_tr(&root);
	if(root==NULL)
	{
		printf("tree is empty!\n");
		exit(-1);
	}
	show(root);
	return 0;

}

