#include<stdio.h>
int main()
{	
	int num;
	int j=0,sum=0,i;
	for(;;)
	{
	printf("输入一个大于100小于500的数：\n");
	scanf("%d",&num);
	if(num<100||num>500)
	printf("您输入的信息有误，请重新输入\n");
	else break;
	}
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{	
			j++;
			if(j==1)
			{	printf("%d的约数为：\n",num);}
			printf("%d\n",i);
			sum=sum+i;
		}
	}
	if(j==0)
	printf("%d为质数，无约数\n",num);
	else	printf("%d的约数共有%d个\n%d的约数和为%d\n",num,j,num,sum);

	return 0;


}
