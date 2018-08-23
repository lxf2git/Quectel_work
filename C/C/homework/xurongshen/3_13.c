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
	int i, j, k;
	j=1;
	k=1;
	for(i =1;i<5;i++)
	{
		if((j*5+1)%4 == 0)
			j=(j*5+1)/4;
		else
		{
			k++;
			j=k;
			i=0;
		}
	}
	j=j*5+1;
	printf("%d\n",j);
}

/*
void print(int a,int b)
{
	printf("最大值是%d\n",a);
	printf("最小值是%d\n",b);
	printf("差值是%d\n",a-b);
}
*/
