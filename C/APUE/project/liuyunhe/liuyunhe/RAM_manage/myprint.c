#include"myprint.h"


void myprint(pmanage apply_head,pmanage myfree_head)
{
		int i=0;
		pmanage palit;
		printf("apply空间\n");
		for(palit=apply_head->next;palit!=apply_head;palit=palit->next)
		{
				printf("inidx:%d  mem_size:%d\n",palit->index,palit->mem_size);
				i++;
		}
		if(i==0)
		{
				printf("空间用完\n");
		}


		printf("free空间\n");
		i=0;
		for(palit=myfree_head->next;palit!=myfree_head;palit=palit->next)
		{
				printf("inidx:%d  mem_size:%d\n",palit->index,palit->mem_size);
				i++;
		}
		if(i==0)
		{
				printf("无free\n");
		}


}
