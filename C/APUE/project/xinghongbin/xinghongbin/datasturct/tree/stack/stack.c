#include"stack.h"
/*
int main()
{
		int data=1;
		int a,b,c,d;
		pSta p;
		stack_init(&p);
		push(p,data);
		push(p,data);
		push(p,data);
		push(p,data);
		pop(p,&a);
		pop(p,&b);
		pop(p,&c);
		pop(p,&d);
		printf("%d%d%d%d\n",a,b,c,d);
}
*/
void get_memory(void **p,int size)
{
		*p = malloc(size);
}

void node_init(pNode *p)
{
		get_memory((void**)p,sizeof(sNode));
		(*p)->next = (*p);
		(*p)->prev = (*p);

}
void stack_init(pSta *p)
{
		get_memory((void**)p,sizeof(sSta));
		node_init(&((*p)->bottom) );
		(*p)->top = (*p)->bottom;
}
int push(pSta p,struct tree *pTemp)
{
		pNode pnew;
		node_init(&pnew);
		pnew->pdata = pTemp;
		pnew->next = p->top->next;
		pnew->prev = p->top;
		p->top->next->prev = pnew;
		p->top->next = pnew;
		p->top = pnew;
		return 0;
}
int pop(pSta p,struct tree **pTemp)
{
		pNode pDel;
		if(p->bottom->next == p->bottom)
		{
				printf("stack is empty\n");
				return -1;
		}
		*pTemp= p->top->pdata;
		pDel = p->top;
		p->top->prev->next = p->top->next;
		p->top->next->prev = p->top->prev;
		p->top = p->top->prev;
		if(pDel != NULL)
		{
				free(pDel);
				pDel = NULL;
		}
		return 0;
}
