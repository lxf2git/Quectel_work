#include<stdio.h>
void output(int *a);
void deal(int *a);
void input(int *a);

int main()
{
	int a[10];
	input(a);
	output(a);

	deal(a);

	output(a);
	return 0;
}

void input(int *a)
{
	
	int i;
	printf("Input 10 numbers:\n");
	for(i = 0;i < 10;i++)
	{
		printf("NO.%d :",i);
		scanf("%d",&a[i]);
	}
}

void deal(int *a)
{
	int temp,max,min,i,j,max_num=0,min_num=0;
	int b[10];
	for(i=0;i<10;i++)
	{
		b[i]=a[i];
	}
	for(i=0;i<9;i++)
		for(j=i;j<10;j++)
		{
			if(b[i] < b[j])
			{
				temp = b[j];
				b[j] = b[i];
				b[i] = temp;
			}
		}
	a[0] = b[0];
	a[9] = b[9];
	//printf("min:%d\n",min);   //???????????????????????????
	//printf("max:%d\n",max);   //???????????????????????????
}

void output(int *a)
{
	int i;
	for(i = 0;i<10;i++)
	{
		printf("%d ",a[i]);
		
	}
	printf("\n");
}
