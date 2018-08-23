#include"creat.h"


void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p==NULL)
	{
			printf("malloc error!\n");
			exit(-1);
	}
}

void init_node(pTree *p)
{
	create_memory((void **)p,sizeof(sTree));
	(*p)->lc = NULL;
	(*p)->rc = NULL;
}

void creat_chain(pTree *root)
{
		char x;
		scanf("%c",&x);
		if(x==' ')
				(*root)=NULL;
		else
		{
				init_node(root);
				(*root)->data=x;
				creat_chain(&(*root)->lc);
				creat_chain(&(*root)->rc);
		}
}
