#include<stdio.h>

int main()
{
	int a,b,output[4],i;
	printf("输入两位数a:\n");
	scanf("%d",&a);
	printf("输入两位数b:\n");
	scanf("%d",&b);
	output[0]=b%10;
	output[1]=a/10;
	output[2]=b/10;
	output[3]=a%10;
	printf("输出四位数C：\n");
	for(i=0;i<4;i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;

}	
