#include<stdio.h>
int main()
{
	float a,b,c;
	printf("请输入a,b,c:");
	scanf("%f %f %f",&a,&b,&c);
	if(a-b>=0)

	{
		if(b-c>=0)
		{
			printf("max:%f min:%f sub:%f\n",a,c,a-c);
		}
		else
		{
			if(a-c>=0)
			printf("max:%f min:%f sub:%f\n",a,b,a-b);
			else
			printf("max:%f min:%f sub:%f\n",c,b,c-b);
		}
	}

	if(a-b<=0)

	{	
		if(a-c>=0)
		{
			printf("max:%f min:%f sub:%f\n",b,c,b-c);
		}
		else
		{
			if(b>=c)
			printf("max:%f min:%f sub:%f\n",b,a,b-a);
			else
			printf("max:%f min:%f sub:%f\n",c,a,b-a);
		}
	}
	
}
