#include"main.h"

void last_show_tree(pStack sta,pTree root)
{
printf("========last show tree=======\n");
pTree pdata;
pTree ptmp;
pTree vist=NULL;
ptmp=root;
	while(sta->top!=0||ptmp!=NULL)
	{
		while(ptmp!=NULL)
		{
			push(sta,ptmp);
			ptmp=ptmp->lc;
		}
	ptmp=*(sta->bottom+sta->top);
		if(ptmp->rc==NULL||vist==ptmp->rc)
		{
			pop(sta,&pdata);
			printf("=%c ",pdata->data);
			vist=pdata;
			ptmp=NULL;
		}
		else
		{
			ptmp=ptmp->rc;
		}
	}
}
