#include<stdio.h>
#include<stdlib.h>
#define EMPTY -2
#define SIZE 50
#define FULL -1
#define SUC 0
typedef struct node
{
	void *data;
	struct node *prev;
	struct node *next;
}sNode,*pNode;

typedef struct Stack
{
	pNode top;
	pNode bottom;
}sStack,*pStack;

typedef struct tree
{
	char data;
	struct tree *lc;
	struct tree *rc;
}sTree,*pTree;

void creat_memory(void **p,int size)
{
	*p=malloc(size);
}

void init_node_stack(pNode *p)
{
	creat_memory((void **)p,sizeof(sNode));
	(*p)->prev=*p;
	(*p)->next=*p;
}
void init_node_tree(pTree *node)
{
	*node=(pTree)malloc(sizeof(sTree));
	if(*node==NULL)
	{
		printf("malloc failed");
		exit(-1);
	}
	(*node)->lc=NULL;
	(*node)->rc=NULL;
}
void init_node(pNode *node)
{
	*node=(pNode)malloc(sizeof(sNode));
	if(*node==NULL)
	{
		printf("malloc failed");
		exit(-1);
	}
	(*node)->next=NULL;
	(*node)->prev=NULL;
}

pStack init_stack(int size)
{
	pStack ps=NULL;
	creat_memory((void ** )&ps,size);
	init_node_stack((&ps->bottom));
	ps->top=ps->bottom;
	return ps;
}
int push(pStack ps,void *tr)
{
	pNode pnew=NULL;
	init_node(&pnew);
	pnew->data=tr;


	pnew->next=ps->top->next;
	pnew->prev=ps->top;
	ps->top->next->prev=pnew;
	ps->top->next=pnew;
	ps->top=pnew;
	return SUC;
}

int is_empty(pStack ps)
{
	if(ps->bottom->next==ps->bottom)
	{
		return EMPTY;
	}
	return SUC;
}

void *pop(pStack ps)
{
	if(is_empty(ps))
	{
		return NULL;
	}
	pNode pdel=NULL;
	void *da=NULL;
	da =ps->top->data;
	pdel=ps->top;
	ps->top->prev->next=ps->bottom;
	ps->bottom->prev=ps->top->prev;
	if(pdel!=NULL)
	{
		free(pdel);
		pdel=NULL;
	}
	ps->top=ps->bottom->prev;
	return da;
}

void creat_tree(pTree *root)
{
	char ch;
	scanf("%c",&ch);
	//getchar();
	if(ch==' ')
	{
		*root=NULL;
	}
	else
	{
		init_node_tree(root);
		(*root)->data=ch;
		creat_tree(&(*root)->lc);
		creat_tree(&(*root)->rc);
	}
}

void mid_show(pTree root)
{
	pStack ps=init_stack(sizeof(sStack));
	pTree p = root;


	while(p!=NULL||EMPTY!=is_empty(ps))
	{
		while(p!=NULL)
		{
			push(ps,p);
			p=p->lc;
		}
		p=pop(ps);
		 printf("%c ",p->data);
		p=p->rc;
	}
	printf("\n");
}

void pre_show(pTree root)
{
	pStack ps=init_stack(sizeof(sStack));
	pTree p = root;


	while(p!=NULL||EMPTY!=is_empty(ps))
	{
		while(p!=NULL)
		{
		 	printf("%c ",p->data);
			push(ps,p);
			p=p->lc;
		}
		p=pop(ps);
		p=p->rc;
	}
	printf("\n");
}
void last_show(pTree root)
{
	pStack sta;
	init_stack(sizeof(sStack));
	pTree p=root;
	pTree ptmp =NULL;
	int ret;
	while(p!=NULL||EMPTY!=is_empty(sta))
	{
		while(p!=NULL)
		{
			push(sta,p);
			p=p->lc;
		}
		p=pop(sta);
		push(sta,p);
		if(p->rc==NULL||ptmp==p->rc)
		{
			p=pop(sta);
			printf("%c ",p->data);
			ptmp=p;
			p=NULL;
		}
		else
		{
			p=p->rc;
		}
	}
}
void show_tree(pTree root)
{
	puts("======pre trav=====\n");
	pre_show(root);
	puts("======mid trav=====\n");
	mid_show(root);

	puts("======last trav======\n");
	last_show(root);
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
