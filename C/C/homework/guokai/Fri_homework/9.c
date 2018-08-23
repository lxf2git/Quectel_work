#include<stdio.h>
int main()
{
    	int a[10];
		int	b,i;
		for(i=0;i<10;i++)
		scanf("%d",&a[i]);
		scanf("%d",&b);
		for(i=0;i<10;i++)
		{
		if(a[i]==b)
			{	
				printf("%d",i);
	            break;
			}	
		if(a[i]!=b&&i==9)
				
		     printf("sorry,not found!");
		}
           
return 0;
}aaaaaaaaa
