#include<stdio.h>

int main()
{
	int a=6;
	int s;
	s=yu(yu(yu(yu(a))));
	printf("至少要：%d条鱼\n",s);

}

int yu(int x)
{
	int y;
	y=5*x+1;
	return y;
}
