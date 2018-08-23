#include<stdio.h> 
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},nu,i,bit,times;
//	printf("请输入10位按升序排列的数列\n");
	for(i=0;i<10;i++)
	{
		printf("请输入10位按升序排列的数列\n");
		scanf("%d",&a[i]);
	}
	printf("从第几个数开始逆转？");
	scanf("%d",&i);
	printf("逆转几位？\n");
	scanf("%d",&bit);
	times=bit/2;
	bit=bit+i;
	for(;times>0;times--)
	{
		nu=a[i-1];
		a[i-1]=a[bit-1];
		a[bit-1]=nu;
		i++;
		bit--;
	}
	for(i=0;i<10;i++)	
		printf("%d\n",a[i]);
}
