#include"main.h"

int main()
{
	pTree proot = NULL;
	init_node(&proot);
	int arr[N]={22,7,7,22,7,22,22};
//	creat_arr(arr);
	creat_tree(arr,proot);
	show_tree(proot);
	delete_tree(proot);
	show_tree(proot);
}
void mid_tree(pTree pnode)
{
	if(pnode->lc != NULL)
	{
		mid_tree(pnode->lc);
	}
	printf("%d ",pnode->data);
	if(pnode->rc != NULL)
	{
		mid_tree(pnode->rc);
	}
}
void show_tree(pTree proot)
{
	mid_tree(proot);
	printf("\n");
}
void creat_tree(int *arr,pTree proot)
{
	int i;
	proot->data = arr[0];
	for(i=1;i<N;i++)
	{
		insert(proot,arr[i]);
	}
}
void insert(pTree pnode,int num)
{
	pTree pnew = NULL;
	if(num < pnode->data)
	{
		if(pnode->lc == NULL)
		{
			init_node(&pnew);
			pnew->data = num;
			pnode->lc = pnew;
			pnew->pa = pnode;
		}
		else
		{
			insert(pnode->lc,num);
		}
	}
	else
	{
		if(pnode->rc == NULL)
		{
			init_node(&pnew);
			pnew->data = num;
			pnode->rc = pnew;
			pnew->pa = pnode;
		}
		else
		{
			insert(pnode->rc,num);
		}
	}
}
void creat_arr(int *arr)
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
}

void init_node(pTree *pnode)
{
	creat_memory((void**)pnode,sizeof(sTree));
	(*pnode)->pa = NULL;
	(*pnode)->lc = NULL;
	(*pnode)->rc = NULL;
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