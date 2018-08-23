#include<stdio.h>
void math();
void print(int a);

int main()
{
	math();
	return 0;
}

void math()
{
	int i=1,num=0;

	for(;i<=1000;i++)
	{
		if(i%7 == 1)
			if(i%5 == 3)
				if(i%3 == 2)
				{
					print(i);
					num++;
					if(num %6 == 0)
					{
						printf("\n");
					}
				}
	}

}

void print(int a)
{
	printf("%d   ",a);
}
