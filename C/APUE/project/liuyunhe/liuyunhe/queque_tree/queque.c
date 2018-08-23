#include"init.h"

void push(pStack pStack_head,pTree tr)
{
		if(tr!=NULL)
		{
				pStack new;
				init_pStack(&new);

				new->paar=tr;

				pStack_head->prev->next=new;
				new->next=pStack_head;
				new->prev=pStack_head->prev;
				pStack_head->prev=new;
		}		

}

void pop(pStack pStack_head,pTree *pTree_print)
{
		*pTree_print=pStack_head->next->paar;
		pStack palit=pStack_head->next;

		pStack_head->next=palit->next;
		palit->next->prev=pStack_head;

		palit->prev=palit;
		palit->next=palit;
		if(palit!=NULL)
		{
				free(palit);
		}
}

void queque_print(pStack pStack_head,pTree root)
{
		pTree pTree_print=NULL;
		while(pStack_head->next!=pStack_head)
		{
			root=pStack_head->next->paar;
			push(pStack_head,root->tr_lc);
			push(pStack_head,root->tr_rc);
		
			pop(pStack_head,&pTree_print);
			printf("%c ",pTree_print->ch);
		}
		printf("\n");
}

void queque(pStack pStack_head,pTree root)
{
		int ch;
		push(pStack_head,root);
		queque_print(pStack_head,root);
		
}
