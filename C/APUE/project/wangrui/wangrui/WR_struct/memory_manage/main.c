#include"memory.h"
sRec *pHrec[N];
int rec = 0;
int main()
{
	int choose;
	int ret;
	pMem pHapp = NULL;
	pMem pHfre = NULL;
//	pRec pHrec = NULL;
	init_mem_node(&pHapp);
	init_mem_node(&pHfre);
//	init_rec_node(&pHrec);
	creat_mem_chain(pHapp);
	while(1)
	{
		choose = Menu();
		switch(choose)
		{
			case APPLY:
			{
				ret=apply_mem(pHapp,pHfre);
				break;
			}
			case FREE:
			{
				ret=free_mem(pHapp,pHfre);
				break;
			}
			case PRINT:
			{
				print(pHapp,pHfre);
				break;
			}
			case EXIT:
			{
				ret=exit_free(pHapp,pHfre);
				return 0;
			}
		}
		if(ret == SUC)
		{
			printf("success\n");
		}
		else
		{
			printf("fail\n");
		}
	}	
	return 0;
}

int Menu()
{
	int choose;
	do
	{
		printf("==================\n");
		printf("-----APPLY-----:1)\n");
		printf("-----FREE------:2)\n");
		printf("-----PRINT-----:3)\n");
		printf("-----EXIT------:0)\n");
		scanf("%d",&choose);
	}while((choose<0||choose>3)&&printf("choose again\n"));
	return choose;
}
