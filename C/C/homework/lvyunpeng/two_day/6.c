#include<stdio.h>
int main()
{
	int x,y;
	printf("please two number:\n");
	scanf("%d%d",&x,&y);
	for(;x!=1;)
{
	if(x%2==0)
{
	x=x/2;
	y+=x;
}
	else //if(x%2==1)
{
	x=(x-1)/2;
	y+=x;
	x+=1;
}
}
	printf("%d\n",y);
	return 0;
}
