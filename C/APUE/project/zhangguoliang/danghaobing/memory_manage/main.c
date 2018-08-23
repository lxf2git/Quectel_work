#include"main.h"
int main()
{
	pMem pHead;
	init_Node(&pHead,0,0);
	init_Memory(pHead);
	pMem pFead;
	init_Node(&pFead,0,0);
	pRc pRead;
	init_Rnode(&pRead);
    int x;
    while(1)
     {
 			 printf("please input:\n");
         	 printf("1 apply memory.\n");
             printf("2 print memory information.\n");
			 printf("3 free memory\n");
             printf("0 exit.\n");
	         scanf("%d",&x);
		     switch(x)
	         {
		             case APPLY:
							   apply(pHead,pFead,pRead);
		                       break;
		             case PRINT:
							   printf("memory_now:\n");
							   show_chain(pHead);
							   printf("memory_free:\n");
							   show_chain(pFead);
		                       break;
					 case FREE:
							   Free(pHead,pFead,pRead);
							   break;
		             case EXIT:
							   clean_data(pHead,pFead,pRead);
		                       return 0;
		             default:
		                     printf("input error! please input again!\n");
		                       break;
		     }
      }
}

