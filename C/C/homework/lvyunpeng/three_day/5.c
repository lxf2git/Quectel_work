#include<stdio.h>
int main()
{
	int i,y;
	for(i=0;;i++)
{
	y=(((((i-1)/5-1)/5-1)/5-1)/5-1)/5;
	if(y==1)
{
	printf("%d\n",i);
	return 0;
}
}
	return 0;
}
