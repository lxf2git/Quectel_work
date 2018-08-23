#include<stdio.h>
int num();
int deal(int n);
main()
{
num();
}
int num()
{
		int i;
		for(i=0;;i++)
			if(6==deal(i))
					break;
		printf("%d",i);
}
int deal(int n)
{
		int i;
		for(i=1;i<6&&(n%5==1);i++)
		{
				n=4*((n-1)/5);
		}
		return i;		
}
