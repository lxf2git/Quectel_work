#include<stdio.h>
int main()
{
	char string[10];
	int a,b,c,i;
	for(i=0;i<10;i++)
	{string[i]=i+1;}
	printf("第几个数啊？\n");
	scanf("%d",&a);
	printf("逆序排列几个数啊？\n");
	scanf("%d",&b);
	for(i=0;i<10;i++)
	{printf("%d ",string[i]);}
	printf("\n");
	c=b;
	for(i=0;i<10;i++)
	{
		if(i+1>=a&&i+1<=a+b-1)
			{
			printf("%d ",string[i+c-1]);
			c-=2;
			}
		else	
			printf("%d ",string[i]);
	}
	printf("\n");
}
