#include<stdio.h>
#include<time.h>

void wait(int n);
void wait_one_second();

int main()
{
	wait(5);
	printf("main - ok\n");
	return 0;
}

void wait(int n)
{
	while(n>0)
	{
		wait_one_second();//等1s
		printf(".\n");
		n--;
	}
}

void wait_one_second()
{
	long t = time(NULL);
	t+=1;
	while(time(NULL)<t)
	{
		;
	}
}

