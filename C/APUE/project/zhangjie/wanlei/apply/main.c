#include"main.h"
#include"insert.h"

int main()
{
	pMem phead_app=NULL;
	pMem phead_free=NULL;
	init_memory(&phead_app,sizeof(sMem));
	init_memory(&phead_free,sizeof(sMem));
	creat_chain(phead_app,M);
	menu(phead_app,phead_free);
	return 0;
}

int menu(pMem phead_app,pMem phead_free)
{
	int n;
	pRec phead_rec=NULL;
	init_rec(&phead_rec,sizeof(sRec));
	do
	{
		printf("please choose a function\n");
		printf("*******0:EXIT***********\n");
		printf("*******1:APPLY**********\n");
		printf("*******2:FREE***********\n");
		printf("*******3:PRINT**********\n");
		scanf("%d",&n);
		switch(n)
		{
			case EXIT:
				return SUC;
				break;
			case APPLY:
				apply_mem(phead_app,phead_free,phead_rec);
				break;
			case FREE:
				free_mem(phead_app,phead_free,phead_rec);
				break;
			case PRINT:
				printf("memtory:\n");
				show(phead_app);
				printf("free:\n");
				show(phead_free);
				break;
			default:
				break;
		}
	}while(n>=EXIT||n<=PRINT);
	return FULL;	
}
