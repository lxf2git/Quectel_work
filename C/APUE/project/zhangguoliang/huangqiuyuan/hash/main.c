#include"main.h"

int main()
{
	pMode pStart;
	init_pMode(&pStart);
	while(1)
	{
		printf("**************\n");
		printf("1 save number\n");
		printf("2 find number\n");
		printf("0 exit \n");
		printf("**************\n");
		int x;
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				save(pStart);
				break;
			case 2:
				find(pStart);
				break;
			case 0:
				free_chain(pStart);
				if(pStart!=NULL)
				{
					free(pStart);
					pStart=NULL;
				}
				return 0;
			default:
			printf("choose error! please input again!\n");
				break;
		}
	}

	return 0;
}
