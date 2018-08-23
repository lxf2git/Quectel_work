#include<stdio.h> 
int main()
{
	int number,i=0,nu;
	char charc[100]={' '};
	scanf("%d",&number);
	if(number<0)
	{
		number=number*-1;
		for(;number!=0;i++)
		{	
			nu=number%10;
			number=number/10;
			charc[i]=48+nu;
		
		}
		printf("-");
		for(;i>=0;i--)
		{
			printf("%c",charc[i]);
		}
	}
	else
	{
		for(;number!=0;i++)
		{	
			nu=number%10;
			number=number/10;
			charc[i]=48+nu;
		
		}
		for(;i>=0;i--)
		{
			printf("%c",charc[i]);
		}
	}
	printf("\n");
}
