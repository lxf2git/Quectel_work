#include<stdio.h>
int l();
int s(int a,int b);
int main()
{
	l();
	return 0;
}

int l()
{
	int a,b;
	for(b=1;b<10;b++)
	{
		for(a=1;a<b+1;a++)
		{	s(a,b);
		}
		
	}
}
int s(int a,int b)
{
			printf("%d*%d=%d ",a,b,a*b);
			if(a==b)
				printf("\n");	
}
