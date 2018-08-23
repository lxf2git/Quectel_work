#include<stdio.h>

int main()
{
	int i,j,x,n;
	int a[10];
	printf("please input in :\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
    }
	printf("please again input in :\n");
	scanf("%d",&j);
	for(n=0;n<10;n++)
	{
	       x=a[n];
		  if(x==j)
		  {		  
				printf("%d\n",n);
		      	break;
		  }   
	}
	if(n==10&&x!=j)
    {
		printf("sorry,not found\n");
    }
	return 0;
}
