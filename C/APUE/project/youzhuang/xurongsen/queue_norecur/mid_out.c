#include"init.h"
//----mid_out.c----
int first_tree(pStack pst,pTree ptroot)
{
	int ret=0;
	while(1)
	{
		push(pst,ptroot);
				printf("%c",ptroot->data);
		if((ptroot->lc == NULL))
		{
			while(1)
			{
				ret = pop(pst,&ptroot);
				if(ret == EMPTY)
				{
					return SUC;
				}
				if(ptroot->rc != NULL)
				{
					ptroot = ptroot->rc;
					break;
				}
				else
				{
					ptroot = ptroot->parent;
					continue;
				}
			}
		}
		else
		{
			ptroot = ptroot->lc;
			continue;
		}
	}
}
int mid_tree(pStack pst,pTree ptroot)
{
	int ret=0;
	while(1)
	{
		push(pst,ptroot);
		if((ptroot->lc == NULL))
		{
			while(1)
			{
				ret = pop(pst,&ptroot);
				if(ret == EMPTY)
				{
					return SUC;
				}
				printf("%c",ptroot->data);
				if(ptroot->rc != NULL)
				{
					ptroot = ptroot->rc;
					break;
				}
				else
				{
					continue;
				}
			}
		}
		else
		{
			ptroot = ptroot->lc;
			continue;
		}
	}
}

int last_tree(pStack pst,pTree ptroot)
{
	int ret = 0;
	pTree have_visited=NULL;

	while(1)
	{
		push(pst,ptroot);
	//printf("push:%c \n",ptroot->data);
		if(ptroot->lc == NULL)
		{
			while(1)
			{
				//不知到为什么出栈不成功？？？
					ret = pop(pst,&ptroot);
				 if((ret == EMPTY))
				 {
					return SUC;
				}
				if(ptroot->rc != NULL)
				{
					if(ptroot->rc != have_visited)
					{
						push(pst,ptroot);
						ptroot = ptroot->rc;
						have_visited = ptroot;
						break;
					}
					else
					{
						have_visited = ptroot;
						printf("%c",ptroot->data);
						continue;
					}
				}
				else
				{
					printf("%c",ptroot->data);
				}
			}
		}
		else
		{
			ptroot = ptroot->lc;
			continue;
		}
	}
	printf("\n");
}

//------------------Queue----------------------------
void queue_show(pStack pst,pTree ptroot)
{
	printf("inter queu_show---!\n");
	int ret=-5;
	int a=1;//1代表未入栈，0代表已经入栈
//	push_queue(pst,ptroot);
	while(ret != EMPTY)
	{
		printf("%c ",ptroot->data);
		if(NULL != ptroot->lc)
		{
			push_queue(pst,ptroot->lc);
		}
			if(NULL != ptroot->rc)
			{
				push_queue(pst, ptroot->rc);
			}
		ret = pop_queue(pst,&ptroot);
		if(ret == EMPTY)
		{
			break;
		}
	//	printf("ret:%d \n",ret);
	}
}
