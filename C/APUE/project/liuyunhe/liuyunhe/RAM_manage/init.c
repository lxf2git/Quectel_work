#include"init.h"
#include<stdlib.h>
#define APPLY 10;
great_memory(pmanage *pf)
{
		*pf=malloc(sizeof(smanage));
		(*pf)->prev=(*pf);
		(*pf)->next=(*pf);
}

pre_memory(pRecord *pf)
{
		(*pf)=malloc(sizeof(sRecord));
		(*pf)->next=(*pf);
		(*pf)->prev=(*pf);
}

void manage_st(pmanage apply_head)
{
		int i;
		for(i=0;i<10;i++)
		{
				pmanage apply_new;
				great_memory(&apply_new);
				apply_new->index=i+1;
				apply_new->mem_size=APPLY;

				apply_head->prev->next=apply_new;
				apply_new->prev=apply_head->prev;
				apply_new->next=apply_head;
				apply_head->prev=apply_new;
		}
}


