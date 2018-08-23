#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
		int data;
		struct tree *pa;
		struct tree *lc;
		struct tree *rc;
}sTre,*pTre;

void output(pTre p);
void insert_tree(pTre p,pTre pnew);
void create_tree(int arr[],int num,pTre root);
void init_node(pTre *p);
void create_memory(void **p,int size);
void delete(pTre *root);
pTre find_del(pTre p,int del);
void delete_node(pTre *root,pTre del_node);
void free_memory(pTre *p);
pTre find_rtree_min(pTre p);
pTre find_ltree_max(pTre p);
void exchange_ltree_node(pTre dest,pTre src,pTre *root);
void exchange_rtree_node(pTre dest,pTre src,pTre *root);

int main()
{
		int arr[]={22,7,5,4,6,12,10,13,34,30,31,45,44,46,23};
		pTre root=NULL;
		init_node(&root);
		root->data=arr[0];
		create_tree(arr,15,root);
		output(root);
		printf("\n");
		while(root!=NULL)
		{
				delete(&root);
				output(root);
				printf("\n");
		}
		return 0;
}

void create_memory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("create memory error!\n");
				exit(-1);
		}
}

void init_node(pTre *p)
{
		create_memory((void **)p,sizeof(sTre));
		(*p)->pa=NULL;
		(*p)->lc=NULL;
		(*p)->rc=NULL;
}

void create_tree(int arr[],int num,pTre root)
{
		pTre pnew=NULL;
		int i;
		for(i=1;i<num;i++)
		{
				init_node(&pnew);
				pnew->data=arr[i];
				insert_tree(root,pnew);
		}
}

void insert_tree(pTre p,pTre pnew)
{
		pTre pin=NULL;
		if(pnew->data<p->data)
		{
				if(p->lc!=NULL)
				{
						insert_tree(p->lc,pnew);
				}
				else
				{
						p->lc=pnew;
						pnew->pa=p;
						return;
				}
		}
		if(pnew->data>=p->data)
		{
				if(p->rc!=NULL)
				{
						insert_tree(p->rc,pnew);
				}
				else
				{
						p->rc=pnew;
						pnew->pa=p;
						return;
				}
		}
}

void output(pTre p)
{
		if(NULL==p)
		{
				return;
		}
		output(p->lc);
		printf("%d ",p->data);
		output(p->rc);
}

pTre find_del(pTre p,int del)
{
		pTre del_node=NULL;
		if(p!=NULL)
		{
				if(p->data==del)
				{
						return p;
				}
				del_node=find_del(p->lc,del);
				if(NULL==del_node)
				{
						del_node=find_del(p->rc,del);
				}
		}
		return del_node;
}

void delete(pTre *root)
{
		pTre del_node=NULL;
		int del;
		printf("please input delete data:\n");
		scanf("%d",&del);
		del_node=find_del(*root,del);
		if(del_node!=NULL)
		{
				delete_node(root,del_node);
		}
		else
		{
				printf("don't have this node!\n");
		}
}

pTre find_rtree_min(pTre p)
{
		while(p->lc!=NULL)
		{
				p=p->lc;
		}
		return p;
}
pTre find_ltree_max(pTre p)
{
		while(p->rc!=NULL)
		{
				p=p->rc;
		}
		return p;
}

void exchange_ltree_node(pTre dest,pTre src,pTre *root)
{
		if(src->pa!=dest)
		{
				src->pa->rc=src->lc;
				if(src->lc!=NULL)
				{
						src->lc->pa=src->pa;
				}
				src->lc=dest->lc;
				dest->lc->pa=src;
		}
		src->pa=dest->pa;
		src->rc=dest->rc;
		if(src->rc!=NULL)
		{
				src->rc->pa=src;
		}
		if(dest!=*root)
		{		
				if(dest->pa->lc==dest)
				{
						dest->pa->lc=src;
				}
				else
				{
						dest->pa->rc=src;
				}
		}
		else
		{
				*root=src;
		}
		dest->pa=NULL;
		dest->lc=NULL;
		dest->rc=NULL;
}
void exchange_rtree_node(pTre dest,pTre src,pTre *root)
{
		if(src->pa!=dest)
		{
				src->pa->lc=src->rc;
				if(src->rc!=NULL)
				{
						src->rc->pa=src->pa;
				}
				src->rc=dest->rc;
				dest->rc->pa=src;
		}
		src->pa=dest->pa;
		src->lc=dest->lc;
		if(src->lc!=NULL)
		{
				src->lc->pa=src;
		}
		if(dest!=*root)
		{
				if(dest->pa->lc==dest)
				{
						dest->pa->lc=src;
				}
				else
				{
						dest->pa->rc=src;
				}
		}
		else
		{
				*root=src;
		}
		dest->pa=NULL;
		dest->lc=NULL;
		dest->rc=NULL;
}

void free_memory(pTre *p)
{
		if(*p!=NULL)
		{
				free(*p);
				*p=NULL;
		}
}

void delete_node(pTre *root,pTre del_node)
{
		pTre p=NULL;
		if(del_node->lc!=NULL)
		{
				p=find_ltree_max(del_node->lc);
				exchange_ltree_node(del_node,p,root);
				free_memory(&del_node);
				return;
		}
		if(del_node->rc!=NULL)
		{
				p=find_rtree_min(del_node->rc);
				exchange_rtree_node(del_node,p,root);
				free_memory(&del_node);
				return;
		}
		if(del_node->pa!=NULL)
		{
				if(del_node->pa->lc==del_node)
				{
						del_node->pa->lc=NULL;
				}
				else
				{
						del_node->pa->rc=NULL;
				}
				free_memory(&del_node);
				return;
		}
		free_memory(root);
}
