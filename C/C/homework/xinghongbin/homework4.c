#include<stdio.h>
main()
{
		int ch;
		printf("please input 0~9 超出按多次输入\n");
		while(ch=getchar())
		{
				
			// 	printf("\n");
		   		if(ch!='\n')
		   		{
						switch(ch)
						{
								case 49:printf("Mon ");break;
								case 50:printf("Tue ");break;
								case 51:printf("Wed ");break;
								case 52:printf("Thu ");break;
								case 53:printf("Fri ");break;
								case 54:printf("SAt ");break;
								case 55:printf("Sun ");break;
								default:
									printf("error\n");return 0;

						}
						
			    }	
      			else 
						printf("\nplease input 0～9 超出按输入多次\n");
		}
	 		
	//	printf("%d",getchar());
}
