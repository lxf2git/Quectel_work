#include<stdio.h>
int main()
{
		int a;
		scanf("%d",&a);
		switch(a)
		{
		     case 7:
					 printf("sunday\n");
					 break;
			 case 6: 
			         printf("staday\n");
	                 break;
			 case 5: 
			         printf("friday\n");
	                 break;
			 case 4:
			         printf("thursday\n");
			         break;
			 case 3:
			         printf("wedesday\n");
	                 break;
			 case 2:
			         printf("tuesday\n");
	                 break;
			 case 1:		
					 printf("monday\n");
					 break;
			 default:
					 printf("错误"); 
				     break;
		}				 
}	

