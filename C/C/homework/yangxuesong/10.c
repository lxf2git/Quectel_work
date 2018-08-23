#include<stdio.h>
int main()
{	int i=0,j=0,a,b,c;
	while(i<1000)
{
	
	a=i%3;
	b=i%5;
	c=i%7; 	
	if(a==2&&b==3&&c==1)
	{
	printf(" %d",i);
	j++;
	if(j%6==0)
	printf("\n");
	}
	i++;
}
return 0;
}//do while
