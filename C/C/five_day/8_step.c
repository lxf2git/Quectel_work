#include<stdio.h>

int main()
{
	int i;	
	int a[5];
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<5;i++)
	{
		printf("a[%d]:%d\n",i,a[i]);
	}


	//printf("a+1:%p\n",a+1);//1:步长 sizeof(type)
	//printf("&a+1:%p\n",&a+1);//1:整个数组的长度

	return 0;
}
