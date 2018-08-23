#include<stdio.h>
int main()
{
	char i;
	int a=0,b=0,c=0,d=0;
	while(1)
	{
	scanf("%c",&i);
	if(i==10)
		break;
	else if(i==32)
		a++;
	else if(i>47&&i<58)
		b++;
	else if(i>64&&i<91||i>96&&i<123)
		c++;
	else
		d++;
	}
	printf("空格：%d\n",a);
	printf("数字：%d\n",b);
	printf("字母：%d\n",c);
	printf("其他：%d\n",d);
	return 0;
	
}
