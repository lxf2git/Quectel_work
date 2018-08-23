#include<stdio.h>

int main()
{
	float a,b;
	char c;
	while(1)
	{
	scanf("%f%f",&a,&b);
	getchar();
	scanf("%c",&c);
	switch(c)
		{
			case '+':printf("%f\n",a+b);break;
			case '-':printf("%f\n",a-b);break;
			case '*':printf("%f\n",a*b);break;
			case '/':printf("%f\n",a/b);break;
		}
	}
	return 0;
}
