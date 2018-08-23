#include"free.h"

void free_Node(struct data **p)
{
		struct data *ptmp;
		while((*p)->prev!=(*p))
		{
			ptmp = (*p)->prev;
			(*p)->prev = (*p)->prev->prev;
			ptmp->data = 0;
			ptmp->prev = NULL;
			ptmp->next = NULL;
			if(ptmp!=NULL)
			{
					free(ptmp);
					ptmp=NULL;
			}
			
		}
			(*p)->data = 0;
			(*p)->prev = NULL;
			(*p)->next = NULL;
			if((*p)!=NULL)
			{
					free(*p);
					*p=NULL;
			}
}

void Free_chain(pMode pStart)
{
	
		int i,j;
		for(i=0;i<5;i++)
		{
				for(j=0;j<8;j++)
				{
						free_Node(&(pStart->mod[i]->and[j]));
				}
				if(pStart->mod[i]!=NULL)
				{
						free(pStart->mod[i]);
						pStart->mod[i]=NULL;
				}
		}

}
