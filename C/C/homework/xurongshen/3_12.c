#include<stdio.h>
void math();
//void print(int a,int b);

int main()
{
	math();
	return 0;
}

void math()
{
	int i,j;
	for(i=1;i<10;i++){
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%d  ",j,i,i*j);
		}
				printf("\n");
	}
}
/*
void print(int a,int b)
{
	printf("最大值是%d\n",a);
	printf("最小值是%d\n",b);
	printf("差值是%d\n",a-b);
}
*/
