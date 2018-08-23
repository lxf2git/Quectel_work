#include"main.h"
int main()
{
	int a[5];
	int i,x,y;
	printf("输入一组数字:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	x=a[0];
	y=a[4];

	cp(a);

	for(i=1;i<4;i++)
	{	if(a[4]==a[i])
				a[i]=y;
		if(a[0]==a[i])
				a[i]=x;
	}
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
		if(i==4)
			printf("\n");
	}
	return 0;
}
