#include<stdio.h>
#include<stdlib.h>
void check_num(int num);
void count_div(int num);

int main()
{
	int num;
	printf("please input num:(100~500)\n");
	scanf("%d",&num);
	check_num(num);
	count_div(num);
	return 0;
}	

void check_num(int num)
{
	if (num < 100 || num > 500)
	{
			printf("input error!\n");
			exit(-1);
	}
}

void count_div(int num)
{
	int i, count = 0, sum = 0; 
	for (i = 2 ; i < num ; i++)
	{
		if (num%i == 0)
		{
			count++;
			sum += i;
		}
	}
	
	printf("count = %d\nsum = %d",count,sum);
}


