#include<stdio.h>

int main()
{
	float a = 0, b = 0, a1 = 0, b1 = 0;
    int 	c;
	printf("请输入数，输入0结束");
	for(;;)
	{
		scanf("%d",&c);
		getchar();
		if( 0 == c)
		{
			break;
		}
		if(c % 2 == 0)
		{

			a++;
			a1 += c;
		}
		else
		{
			b++;
			b1 += c;
		}

	}
	printf("偶数个%.1f数平均值%.2f \n奇数个数%.1f平均值%.2f",a,a1 / a,b,b1 / b);
}
