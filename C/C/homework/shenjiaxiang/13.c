#include<stdio.h>
void dayu(int);

int main()
{
	int i;
	for(i=0;;i++)
	dayu(i);
	return 0;
}
void dayu(int number)
{
	int i;
	for(i=5;i>=0;i--)
	{
		if(number%5==0)
		number=number-number/5-1;
		else
		break;
	}
	printf("最少捕%d条鱼\n",number);
}
