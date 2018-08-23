#include"insert.h"

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("mallco error\n");
		exit(-1);
	}
}

void i_free(void **p)
{
	if(*p==NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void init_tree(pTree *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->lc=NULL;
	(*p)->rc=NULL;
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
		init_tree(root,sizeof(sTree));
		(*root)->data=ch;
		creat_tree(&(*root)->lc);
		creat_tree(&(*root)->rc);
	}
}
