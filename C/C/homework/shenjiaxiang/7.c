#include<stdio.h>
int main()
{
	char ch;
	int a,b,c,d;
	a=0;
	b=0;
	c=0;
	d=0;
	while(1)
	{
		scanf("%c",&ch);
		if(ch=='\n')
			break;
		else if(ch==32)	//空格
			a+=1;
		else if(ch>=48&&ch<=57)	//数字
			b+=1;
		else if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))	//字母
			c+=1;
		else
			d+=1;                      //其他

	}
	printf("空格：%d\n",a);
	printf("数字：%d\n",b);
	printf("字母：%d\n",c);
	printf("其他：%d\n",d);

		
	return 0;
}
