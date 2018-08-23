#include<stdio.h>

int main()
{
		int a;

	    printf("nian=");
		scanf("%d",&a);
		if(a % 4== 0&&a % 100 != 0)
		{
				printf("Y\n");
		}	
		else if(a % 400 == 0)
		{

				printf("Y\n");
		}
		else
		{
		
				printf("N\n");
		}
		return 0;

}
