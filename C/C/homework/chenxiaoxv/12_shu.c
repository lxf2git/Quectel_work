#include<stdio.h>

int main()
{
	int a,b,c;
	int i=0,s=0,j=0;

	for(a=1;a<10;a++)
	{	for(b=1;b<a+1;b++)
		{		
			c=a*b;	
		 	i++;	
			
		//	i=(i*(i-1))/2
			printf("%d*%d=%d ",a,b,c);

 	/*		if((s=s+i)==i)		
			for(j=0;j<9;j++)
			{
				s=s+j;
	*///		if(s==i)
		}
			printf("\n",i);
			
		
	}
return 0;
} 
