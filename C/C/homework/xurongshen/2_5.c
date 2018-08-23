#include<stdio.h>

int main()
{
	int num=0;
	// int money=100,a=1,b=2,c=5;//money相当于一元钱，a是一分钱  b是俩分钱  c是五分钱
	int m,n,t;//m一分钱的个数   n俩分钱的个数   t是五分钱的个数
	for(m=0;m<101;m++)
		for(n=0;n<51;n++)
			for(t=0;t<21;t++)
				if(100 == (1*m + 2*n +5*t))
				{
					num++;
					printf("1元钱是由%d个一分钱和%d个俩分钱和%d个五分钱组成\n",m,n,t);
				}

	printf("总共由%d种方法！\n",num);
	return 0;
}

