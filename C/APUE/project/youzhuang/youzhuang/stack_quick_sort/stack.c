#include"main.h"
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

void init_node(pData *p)
{
		create_memory((void**)p,sizeof(sData));
		(*p)->prev=*p;
		(*p)->next=*p;
}

void init_stack(pSta *ps)
{
		create_memory((void **)ps,sizeof(sSta));
		pData phead=NULL;
		init_node(&phead);
		(*ps)->bottom=phead;
		(*ps)->top=phead;
}

void push(pSta ps,int arr[N],int low,int high)
{
		pData pnew=NULL;
		init_node(&pnew);
		pnew->arr=arr;
		pnew->low=low;
		pnew->high=high;
		pnew->next=ps->bottom;
		pnew->prev=ps->top;
		ps->bottom->prev=pnew;
		ps->top->next=pnew;
		ps->top=pnew;
}

void pop(pSta ps,int arr[N],int *low,int *high)
{
		arr=ps->top->arr;
		*low=ps->top->low;
		*high=ps->top->high;
		ps->bottom->prev=ps->top->prev;
		ps->top->prev->next=ps->bottom;
		ps->top->next=NULL;
		ps->top->prev=NULL;
		free_memory((void**)&ps->top);
		ps->top=ps->bottom->prev;
}

int stack_empty(pSta ps)
{
		if(ps->top==ps->bottom)
		{
				return EMPTY;
		}
		return SUB;
}
