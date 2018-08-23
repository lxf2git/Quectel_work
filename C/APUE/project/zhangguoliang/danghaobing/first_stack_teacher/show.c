#include"show.h"

int is_empty(pStack sta)
{
		pTree p;
		int ret = pop(sta,&p);
		push(sta,p);
		return ret;
}

void show(pTree root)
{
	sStack sta;
	init_stack(&sta);
	pTree p = root;
	while ( p!=NULL || EMPTY!=is_empty(&sta) )
	{
			while ( p!=NULL )
			{
					push(&sta,p);
					p = p->lc;
			}
			pop(&sta,&p);
			printf("%c ",p->data);
			p = p->rc;
	}
}

void show_pre(pTree root)
{
	sStack sta;
	init_stack(&sta);
	pTree p = root;
	while ( p!=NULL || EMPTY!=is_empty(&sta) )
	{
			while ( p!=NULL )
			{
					printf("%c ",p->data);
					push(&sta,p);
					p = p->lc;
			}
			pop(&sta,&p);
			p = p->rc;
	}
}

void show_last(pTree root)
{
	sStack sta;
	init_stack(&sta);
	pTree p = root;
	pTree ptmp = NULL;
	int ret;
	while( p!=NULL || EMPTY!=is_empty(&sta) )
	{
			while( p!=NULL )
			{
					push(&sta,p);
					p = p->lc;
			}
			pop(&sta,&p);
			push(&sta,p);
			if ( p->rc==NULL||ptmp==p->rc )
			{
				pop(&sta,&p);
				printf("%c ",p->data);
				ptmp=p;
				p = NULL;
			}
			else
			{
				p = p->rc;
			}
			
	}
}




