#include<stdio.h>

int main()

{
	int i,j,k,sum,n=0;
	printf("please enter a int :\n");
	scanf("%d",&sum);                     //输入
	for(i=0;i<=100;i++)

		for(j=0;j<=50;j++)

			for(k=0;k<=20;k++)

				if(sum==(i+2*j+5*k))     //判断和是否为总钱
						n++;
	printf("%d\n",n);
							
}
