#include"main.h"

int main()
{
		pTree root=NULL;
		create_tree(&root);
		output(root);
		return 0;
}

void create_tree(pTree *root)
{
		char ch;
		ch=getchar();
		getchar();
		if(ch==' ')
		{
				root=NULL;
		}
		else
		{
				init_tree_node(root);
				(*root)->data=ch;
				create_tree(&(*root)->lc);
				create_tree(&(*root)->rc);
		}
}

void push(pQueue queue,pTree tree)
{
		pLink pnew=NULL;
		init_link_node(&pnew);
		pnew->tree=tree;
		add_link_node(queue->pw,pnew);
		queue->pw=pnew;
}

void pop(pQueue queue,char *data)
{
		if(queue_empty(queue)==EMPTY)
		{
				return;
		}
		*data=queue->pr->next->tree->data;
		del_link_node(queue->pr,queue->pr->next);
		queue->pw=queue->pr->prev;
}

int queue_empty(pQueue queue)
{
		if(queue->pw==queue->pr)
		{
				return EMPTY;
		}
		return SUB;
}

void output(pTree root)
{
		char data;
		pQueue queue=NULL;
		init_queue(&queue);
		if(NULL==root)
		{
				return;
		}
		push(queue,root);
		while(queue_empty(queue)!=EMPTY)
		{
				root=queue->pr->next->tree;
				pop(queue,&data);
				printf("%c ",data);
				if(root->lc!=NULL)
				{
						push(queue,root->lc);
				}
				if(root->rc!=NULL)
				{
						push(queue,root->rc);
				}
		}
		printf("\n");
}
