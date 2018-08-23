#include<stdio.h>
int main()
{
	float h=100,sum,i;

		sum=100;
	for(i=1;i<11;i++)
	{
		h=h/2;
		sum+=2*(h);
		
	}
	printf("一共经过%f米\n",sum);
	//for(i=1;i<11;i++)
	//{
		//h=h/2;
	//}
	printf("第10次反弹%f米\n",h);
	return 0;
}
