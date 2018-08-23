#include"main.h"

void min_show_tree(pStack sta,pTree root)
{
printf("=======min show tree======\n");
	pTree ptmp;
	pTree pdata;
	ptmp=root;
	while(ptmp!=NULL||sta->top!=0)
	{
		while(ptmp!=NULL)
		{
			push(sta,ptmp);
			ptmp=ptmp->lc;
		}
		pop(sta,&pdata);
		printf("=%c ",pdata->data);
		ptmp=pdata;
		ptmp=ptmp->rc;
	}
}
