#include<stdio.h>
float mj(int x);
float zc(int y);
void pd(int z, char k);
int main()
{
	int r;
	char m;
	pd(r,m);
	return 0;
}

float mj(int x)
{
	return 3.14*x*x;
}

float zc(int y)
{
	return 6.28*y;
}

void pd(int z, char k)
{
	do
	{
		printf("输入半径和需要知道的结果\n");
		scanf("%d,%c",&z,&k);
		if(k=='a')
		printf("%.2f\n",mj(z));
		else if(k=='b')
		printf("%.2f\n",zc(z));
		else if(k=='c')
		printf("%.2f,%.2f\n",mj(z),zc(z));
		else if(k=='d')
		break;
		else 
		printf("请重新");
	}while(1);
}

 