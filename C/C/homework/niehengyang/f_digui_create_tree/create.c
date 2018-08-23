#include"main.h"

void prev_create_tree(pTree *root)
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
		create_memory(root);
		(*root)->data=ch;
		prev_create_tree(&(*root)->lc);
		prev_create_tree(&(*root)->rc);
	}
}

void min_tree(pTree root)
{
        printf("%c ",root->data);
        if(root->lc!=NULL)
        {
                min_tree(root->lc);
        }
        if(root->rc!=NULL)
        {
                min_tree(root->rc);
        }
}


void show_tree(pTree root)
{
        min_tree(root);
}


void create_tree(pTree *root)
{
	printf("please input chain:\n");
	getchar();
	prev_create_tree(root);
	if(root==NULL)
	{
		printf("this is a null tree\n");
		exit(-1);
	}
	//show_tree(*root);
	printf("create tree succeed!\n");
}
