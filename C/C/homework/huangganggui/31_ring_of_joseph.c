#include<stdio.h>

int main()
{
	int i,alive;
	int a[10];
	for(i=0;i<10;i++)
		a[i]=i+1;
	alive=kill(a);
	printf("remain people is :%d\n",alive);

	return 0; 
}

int kill(int a[])
{
	int i=0,k=0;
	int alive = 10;       //people alive
	while(1)
	{
		int j=0;
		alive = 0;
		for(j=0;j<10;j++)
			if(0 != a[j])//number of alive people
			{
				alive++;
				
			}
		if (1==alive)
		{
			for(j=0;j<10;j++)
				if(0 != a[j])//number of alive people
				return a[j];
					
				
		}
		if(a[i]!=0)
		{
			k++;
			if(k == 3)       //count people
			{
				k = 0;
				printf("%d\n",a[i]);
				a[i]=0;      //kill a[i]
			}

		}
		
			
		i++;
		if(i==10)
			i %=10;//if more than 10 ,count again 
	//	printf("    %d\n",i);
	}
	

}
