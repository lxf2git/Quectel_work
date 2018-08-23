#include"init.h"

#if 0
typedef struct Tree
{
	char data;
	struct Tree *lc,*rc,*parent;
}sTree,*pTree;

void create_tree(pTree *proot);
void init_tree(pTree *proot);
void prev_show(pTree root);
void mid_show(pTree root);
void last_show(pTree root);
void show_tree(pTree root);
#endif
#if 1
void create_tree(pTree *proot)
{
	char ch;
	scanf("%c",&ch);
	getchar();
	if(ch == '-')
	{
		*proot = NULL;
	}
	else
	{
		init_tree(proot);
		(*proot)->data = ch;
		create_tree(&(*proot)->lc);
		create_tree(&(*proot)->rc);
	}	
}
#endif



void init_tree(pTree *proot)
{
	*proot = (pTree )malloc(sizeof(sTree));
	if(NULL == *proot)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	(*proot)->lc = (*proot);
	(*proot)->rc = (*proot);
	(*proot)->parent = (*proot);
}

void prev_show(pTree root)
{
	printf("%c ",root->data);
	if(root->lc != NULL)
	{
		prev_show(root->lc);
	}
	if(root->rc != NULL)
	{
		prev_show(root->rc);
	}
}
#if 0
void mid_show(pTree root)
{
	if(root->lc != NULL)
	{
		mid_show(root->lc);
	}
	printf("%c ",root->data);
	if(root->rc != NULL)
	{
		mid_show(root->rc);
	}
}
#endif
#if 0
void last_show(pTree root)
{
	if(root->lc != NULL)
	{
		last_show(root->lc);
	}
	if(root->rc != NULL)
	{
		last_show(root->rc);
	}
	printf("%c ",root->data);
}
#endif

void show_tree(pTree root)
{
	pStack pst = NULL;
	init_stack(&pst);
	printf("main cr_tree after!\n");
//	prev_show(root);
	first_tree(pst,root);
	printf("\nmain cr_tree after!\n");
	mid_tree(pst,root);
	printf("\nmain cr_tree after!\n");
//	last_show(root);
	last_tree(pst,root);
	printf("\n----queue---------\n");
	queue_show(pst,root);
}


int main()
{
	pTree root=NULL;
	create_tree(&root);
	show_tree(root);
	return 0;
}
