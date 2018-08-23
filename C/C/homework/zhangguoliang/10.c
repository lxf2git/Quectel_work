#include<stdio.h>
void ch();
int main()
{
	ch();
	return 0;
}

void ch()
{
	int i,t=0;
	for(i=0;i<=1000;i++)
	{
		if((i%3==2)&&(i%5==3)&&(i%7==1))
		{			printf("%d ",i);
					t++;
					if(t%6==0)
					printf("\n");		
		}
		if(i==1000)
			printf("\n");
					
	}
}
