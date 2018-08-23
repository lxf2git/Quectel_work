#include<stdio.h>
void line_6(int);
int main()

{
	int i,j=0;
	for(i=1;i<=1000;i++)
		if( i%7==1 && i%5==3 && i%3==2 )
		{
	   			printf(" %d ",i);
		        line_6(++j);
		}
	printf("\n");
	return 0;
}
void line_6(int j)
{
	if(j%6==0)
		printf("\n");
}

