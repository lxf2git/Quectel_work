#include"main.h"

void prev_show_tree(pStack sta,pTree root)
{
printf("========prev show tree=======\n");
	pTree pdata;
	pTree ptmp=root;
	while(ptmp!=NULL||sta->top!=0)
	{
		while(ptmp!=NULL)
		{
			printf("=%c ",ptmp->data);
			push(sta,ptmp);
			ptmp=ptmp->lc;
		}
		pop(sta,&pdata);
		ptmp=pdata;
		ptmp=ptmp->rc;
	}
	
}


