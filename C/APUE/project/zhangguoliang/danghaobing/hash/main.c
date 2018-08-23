#include"main.h"

int main()
{
	pMode pStart;
	init_pMode(&pStart);
	while(1)
	{
		printf("please input:\n");
		printf("1 save number.\n");
		printf("2 find number.\n");
		printf("0 exit.\n");
		int x;
		scanf("%d",&x);
		switch(x)
		{
				case SAVE:
						save(pStart);
						break;
				case FIND:
						find(pStart);
						break;
				case EXIT:
						Free_chain(pStart);
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
