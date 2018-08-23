#include<stdio.h>
#define N 100
int main()
{
  	int i,alive;
	int a[N];
	for(i=0;i<N;i++)
	{
		a[i] = i+1;
	}	
	 kill(a);
//	printf("Alive people number :%d\n",alive);
	return 0;
}
int kill(int a[])
{
	int i=0,k=0,j;
	int alive;
    while(1)
	{
		if(a[i]!=0)      //kill people
		{
		 	k++;
			if(k==3)
			{
				k=0;
				printf("kill number : %d\n",a[i]);
				a[i]=0;
			}
		}
		alive=0;
		for(j=0;j<N;j++)
		{
			if(a[j]!=0)
			{
				alive++;      //judge alive people  number
			}
		}
		if(alive==1)
		{
			for(j=0;j<N;j++)   // 
			{
				if(a[j]!=0)
				{
	            printf("Alive people number :%d\n",a[j]);
				}
			
			}
				return 0;
		}
	    i++;
	    if(i==N)
		{
			i=0;
		}
	}
}
