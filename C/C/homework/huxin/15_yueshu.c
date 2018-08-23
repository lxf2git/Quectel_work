#include<stdio.h>
int main()
{
	int n,i,f=0,l=0;
	printf("please input in :\n");
	scanf("%d",&n);
	if(n>99&&n<501)
	{
	    for(i=2;i<n;i++)
		{
		   if(n%i==0)
		   {
			 f=f+i;
			 l++;
			 
		     printf("%d ",i);
		   }
		}
	  printf("\n");	
	  printf("约数的个数:%d\n",l);
	  printf("sum:%d\n",f);
	}
	return 0;
}
