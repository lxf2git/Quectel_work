#include<stdio.h>

void deal();
main()
{
	deal();
}
void deal()
{
		int i,j;
	for(i=1;i<10;++i)
	{
			for(j=1;j<=i;++j)
					printf("%d*%d=%-2d ",i,j,i*j);
					printf("\n");
	}
			
}
