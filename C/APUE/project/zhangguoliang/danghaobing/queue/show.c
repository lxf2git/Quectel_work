#include"show.h"

void show_glob(pTree root)
{
	pQueue queue;
	init_queue(&queue);
	pTree p = root;
	pTree ptmp=NULL;
	int ret;
	//确定遍历哪里
	push_queue(queue,p);
	while((ret=pop_queue(queue,&ptmp))!=EMPTY)
	{
		printf("%c ",ptmp->data);
		if(ptmp->lc!=NULL)
		{
				push_queue(queue,ptmp->lc);
		}
		if(ptmp->rc!=NULL)
		{
				push_queue(queue,ptmp->rc);
		}
	}
	printf("\n");


}
