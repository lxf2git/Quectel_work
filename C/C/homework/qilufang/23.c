#include<stdio.h>
void paixu(int data[10],int a,int b);
int main()
{
		int a,b;
		int data[10]={1,2,3,4,5,6,7,8,9,10};
		printf("输入两个数：\n");
		scanf("%d %d",&a,&b);
		printf("从第%d个数开始的%d个数逆续重新排列",a,b);
		paixu(data,a,b);
		return 0;
}
void paixu(int data[10],int a,int b)
{
		int i,j,k;
		for(i=0;i<a-1;i++)
		{
				printf("%d",data[i]);
		}
		for(j=a+b-2;j>a-2;j--)
		{
				printf("%d",data[j]);
		}
		for(k=a+b-1;k<10;k++)
		{
				printf("%d",data[k]);
		}
		printf("\n");
}
