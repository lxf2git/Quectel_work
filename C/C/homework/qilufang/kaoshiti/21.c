#include<stdio.h>
#define N 10
void output(int data[N],int b);
void data(int a);
int main()
{
	int a;
	printf("输入一个数字：\n");
	scanf("%d",&a);
	data(a);
	return 0;
}
void data(int a)
{
	int b,i;
   	int data[N]={0};	
	for(i=0;;i++)
	{
		data[i]=a%2;
		a=a/2;
		b=i;
		if(a==0)
		{
			data[i+1]=1;
			break;
		}
	}
	output(data,b);
}
void output(int data[N],int b)
{
	int i=0;
	for(i=b;i>=0;i--)
	{
		printf("%d",data[i]);
	}

}
