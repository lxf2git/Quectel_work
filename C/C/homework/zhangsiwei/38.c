#include<stdio.h>

int pingfang(int *i,int *j)
{
	if(*j>0)
	{
		(*j)--;
	//	printf("%p\n",*j);	
		return *i * pingfang(i,j);
	}
	else
	{
		return 1;
	}
	
}

int main()
{
	int i,j,a,g,k;	
	printf("请输入整数：\n");
	scanf("%d",&i);
	printf("请输入幂数：\n");
	scanf("%d",&j);
	
	printf("============================\n");
	a=pingfang(&i,&j);
	printf("%d\n",a);
	printf("最后三位分别是个 十 百：\n");
	for(k=0;k<3;k++)
	{
		g=a%10;
		printf("%d  ",g);
		a=a/10;
	}
	printf("\n");
	
	return 0;
}
