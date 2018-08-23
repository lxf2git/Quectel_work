#include<stdio.h>
#include<stdlib.h>

#define N 20

typedef struct tree
{
		char data;
		struct tree *pa;
		struct tree *lc;
		struct tree *rc;
}sTre,*pTre;

void output(pTre p);
void create_tree(pTre root,char arr[N]);
int pre_create_tree(pTre p,char arr[N],int i);
void init_node(pTre *p);
void create_memory(pTre *p);
void pre(pTre p);
void mid(pTre p);
void last(pTre p);
void free_memory(pTre *p);
void delete_node(pTre p);
void unload(pTre p);

int main()
{
		pTre root=NULL;
		init_node(&root);
		char arr[N];
		printf("please input pre tree:\n");
		gets(arr);
		create_tree(root,arr);
		output(root);
		unload(root);
		return 0;
}

void create_tree(pTre root,char arr[N])
{
		if(arr[0]=='\0')
		{
				printf("input error!\n");
				return;
		}
		root->data=arr[0];
		pre_create_tree(root,arr,1);
}

int pre_create_tree(pTre p,char arr[N],int i)
{
		pTre pnew=NULL;
		if(arr[i]=='\0')
		{
				return i;
		}
		if(arr[i]!=' ')
		{
				init_node(&pnew);
				pnew->data=arr[i];
				p->lc=pnew;
				pnew->pa=p;
				i=pre_create_tree(pnew,arr,i+1);
				if(arr[i]=='\0')
				{
						return i;
				}
		}
		i++;
		if(arr[i]=='\0')
		{
				return i;
		}
		if(arr[i]!=' ')
		{ 
				init_node(&pnew);
				pnew->data=arr[i];
				p->rc=pnew;
				pnew->pa=p;
				i=pre_create_tree(pnew,arr,i+1);
		}
		return i;
}

void init_node(pTre *p)
{
		create_memory(p);
		(*p)->pa=NULL;
		(*p)->lc=NULL;
		(*p)->rc=NULL;
}

void create_memory(pTre *p)
{
		*p=malloc(sizeof(sTre));
		if(NULL==*p)
		{
				printf("create memory error!\n");
				exit(-1);
		}
}

void pre(pTre p)
{
		if(p!=NULL)
		{
				printf("%c ",p->data);
				pre(p->lc);
				pre(p->rc);
		}
}
void mid(pTre p)
{
		if(p!=NULL)
		{
				mid(p->lc);
				printf("%c ",p->data);
				mid(p->rc);
		}
}
void last(pTre p)
{
		if(p!=NULL)
		{
				last(p->lc);
				last(p->rc);
				printf("%c ",p->data);
		}
}

void unload(pTre p)
{
		if(p!=NULL)
		{
				unload(p->lc);
				unload(p->rc);
				delete_node(p);
		}
}

void delete_node(pTre p)
{
		p->pa=NULL;
		free_memory(&p);
}

void free_memory(pTre *p)
{
		if(*p!=NULL)
		{
				free(*p);
				*p=NULL;
		}
}

void output(pTre p)
{
		printf("pre:");
		pre(p);
		printf("\nmid:");
		mid(p);
		printf("\nlast:");
		last(p);
		printf("\n");
}
