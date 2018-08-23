#include<stdio.h>
#include<stdlib.h>
#include"stack_chain.h"
typedef struct tree
{
	struct tree *lc;
	struct tree *rc;
	char data;
}sTree,*pTree;

void init_node(pTree *node)
{
	*node = (pTree)malloc(sizeof(sTree));
	if(*node==NULL)
	{
		printf("malloc failed");
		exit(-1);
	}

	(*node)->lc = NULL;
	(*node)->rc = NULL;
}

void create_tree(pTree *root)
{
	char ch;
	scanf("%c",&ch);
	getchar();
	if(ch==' ')
	{
		*root = NULL;
	}
	else
	{
		init_node(root);//&root
		(*root)->data = ch;
		create_tree(&(*root)->lc);
		create_tree(&(*root)->rc);
	}
}
#if 0
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

	while(p!=NULL||EMPTY!=is_empty())
	{
	
		while(p!=NULL)
		{
			printf("%c",p->data);
			push(p);
			p = p->lc;
		}
		 p = pop();
		 p  = p->rc;
	}

}
#endif
void mid_show(pTree root)
{
#if 0		
	if(root->lc!=NULL)
	{
		mid_show(root->lc);
	}
	printf("%c ",root->data);
	if(root->rc!=NULL)
	{
		mid_show(root->rc);
	}
#endif
	
	pStack ps = init_stack(sizeof(sStack));
	pTree p = root;


	while(p!=NULL||EMPTY!=is_empty(ps))
	{
	
		while(p!=NULL)
		{
			push(ps,p);
			p = p->lc;
		}
		 p = pop(ps);
		 printf("%c",p->data);
		 p  = p->rc;
	}

}

#if 0
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

	pTree p = root;
	pTree have_visited = NULL;
	while(p!=NULL||EMPTY!=is_empty())
	{
	
		while(p!=NULL)//走到最左
		{
			push(p);
			p = p->lc;
		}
		 p = get_stack_top();//取栈定指针 来确定是否具有出栈打印资格
		 if(NULL==p->rc||have_visited==p->rc)//二者满足其一 即可出栈
		 {
		 	  p = pop();
			  printf("%c",p->data);
			  have_visited = p;//设置已经访问标记 记录当前结点
			   p =NULL;//进行下次循环时不入栈 直接出栈
		 }
		 else
		 {
		 	p = p->rc;
		 }
		
	}

}
#endif
void show_tree(pTree root)
{
#if 1		
	puts("====prev trav=====");
//	pre_show(root);

	printf("\n");
	puts("====mid trav=====");
	mid_show(root);
	printf("\n");
	puts("====last trav=====");
//	last_show(root);
	printf("\n");
#endif
}

int main()
{

	pTree root=NULL;
	create_tree(&root);//root &root	
	if(root==NULL)
	{
		printf("null tree\n");
		exit(-1);
	}
	show_tree(root);
	return 0;

}
