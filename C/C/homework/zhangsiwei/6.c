#include<stdio.h>
int main()
{
	int	minute,second,a,hour;
	 float c,b;
	printf("input:hour minute second\n");
	scanf("%d%d%d",&hour,&minute,&second);
	getchar();
	for(;hour>23;)
	{
			printf("错误\n");
			break;
	}
	for(;minute>60;)
	{		printf("错误\n");
			break;
	}
	for(;second>59;)
	{
			printf("错误\n");
			break;
	}
	
	a=hour*60;
	b=second/60.0;
	c=a+b+minute;
	printf("%f\n",c);
	return 0;
}
