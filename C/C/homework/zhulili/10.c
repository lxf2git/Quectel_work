#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
		int x=1,i=0;
	while(x<=1000)
	{
			if(x%3==2 && x%5==3 && x%7==1)
			{
				printf("%d ",x);
				i+=1;
				if(i%6==0)
					printf("\n");
			}			
			x+=1;
	}
	return 0;
}

