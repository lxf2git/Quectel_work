#include<stdio.h>
int main()
{
	char i;
	int a=0,b=0,c=0,d=0;
	i=getchar();
	while(i!='\n')
	{
		if(i>=48&&i<=57)
			a++;
		else if((i>=65&&i<=90)||(i>=97&&i<=122))
			b++;
		else if(i==32)
			c++;
		else
			d++;
	i=getchar();
	}
	printf("英文字母有%d个,\n数字有%d个,\n空格有%d个,\n其他的有%d个。\n",b,a,c,d);










return 0;
}
