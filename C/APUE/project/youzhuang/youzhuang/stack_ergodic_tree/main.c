#include"main.h"
int main()
{
		pLink phead=NULL;
		pTre root=NULL;
		pSta ps=NULL;
		create_tree(&root);
		init_link(&phead);
		init_stack(&ps,root,phead);
		pre(ps,root,phead);
		mid(ps,root,phead);
		last(ps,root,phead);
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

void free_memory(void **p)
{
		if(*p!=NULL)
		{
				free(*p);
				*p=NULL;
		}
}

void init_link(pLink *p)
{
		create_memory((void **)p,sizeof(sLink));
		(*p)->prev=*p;
		(*p)->next=*p;
		(*p)->tree_node=NULL;
}

void init_node(pTre *p)
{
		create_memory((void **)p,sizeof(sTre));
		(*p)->pa=NULL;
		(*p)->lc=NULL;
		(*p)->rc=NULL;
}

void init_stack(pSta *p,pTre root,pLink phead)
{
		create_memory((void **)p,sizeof(sSta));
		(*p)->bottom=phead;
		(*p)->top=phead;
}

void create_tree(pTre *p)
{
		char ch;
		scanf("%c",&ch);
		getchar();
		if(ch==' ')
		{
				*p=NULL;
		}
		else
		{
				init_node(p);
				(*p)->data=ch;
				create_tree(&(*p)->lc);
				create_tree(&(*p)->rc);
				if((*p)->lc!=NULL)
				{
						(*p)->lc->pa=(*p);
				}
				if((*p)->rc!=NULL)
				{
						(*p)->rc->pa=(*p);
				}
		}
}

void push(pSta ps,pTre p,pLink phead)
{
		pLink pnew=NULL;
		create_memory((void**)&pnew,sizeof(sLink));
		pnew->tree_node=p;
		pnew->prev=phead->prev;
		phead->prev->next=pnew;
		phead->prev=pnew;
		pnew->next=phead;
		ps->top=pnew;
}

void pop(pSta ps,pLink phead)
{
		pLink ptem=NULL;
		ps->top=ps->top->prev;

		ptem=phead->prev;
		ptem->prev->next=phead;
		ptem->next=NULL;
		phead->prev=ptem->prev;
		ptem->prev=NULL;
		free_memory((void**)&ptem);
}

void pre(pSta ps,pTre p,pLink phead)
{
		printf("pre: ");
		while(ps->top!=ps->bottom||p!=NULL)
		{
				while(p!=NULL)
				{
						printf("%c ",p->data);
						push(ps,p,phead);
						p=p->lc;
				}
				p=ps->top->tree_node;
				pop(ps,phead);
				p=p->rc;
		}
		printf("\n");
}

void mid(pSta ps,pTre p,pLink phead)
{
		printf("mid: ");
		while(ps->top!=ps->bottom||p!=NULL)
		{
				while(p!=NULL)
				{
						push(ps,p,phead);
						p=p->lc;
				}
				p=ps->top->tree_node;
				pop(ps,phead);
				printf("%c ",p->data);
				p=p->rc;
		}
		printf("\n");
}

void last(pSta ps,pTre p,pLink phead)
{
		pTre record=NULL;
		printf("last: ");
		while(ps->top!=ps->bottom||p!=NULL)
		{
				while(p!=NULL)
				{
						push(ps,p,phead);
						p=p->lc;
				}
				p=ps->top->tree_node;
				if(p->rc==NULL||p->rc==record)
				{
						pop(ps,phead);
						printf("%c ",p->data);
						record=p;
						p=NULL;
				}
				else
				{
						p=p->rc;
				}
		}
		printf("\n");
}

/*
void mid(pTre p)
{
		if(p!=NULL)
		{
				mid(p->lc);
				printf("%c ",p->data);
				mid(p->rc);
		}
}
*/
