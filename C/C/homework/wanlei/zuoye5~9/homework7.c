#include<stdio.h>

int main()
{
	int sp,ma,c,q;
	sp=0;
	ma=0;
	c=0;
	q=0;
	char ch;
	printf("请输入一串字符\n");
	/*ch=getchar();//取键盘上输入的第一个字符
	while(ch!=10)
	{
		if(ch>=65&&ch<=90||ch>=97&&ch<=122)
				c++;
		else if(ch==32)
				sp++;
		else if(ch>=48&&ch<=57)
				ma++;
		else 
				q++;
		ch=getchar();//循环输入输入的字符，并且取走最后的回车
	}*/
	
	while(ch!=10)
	{
		scanf("%c",&ch);
		if(ch>=65&&ch<=90||ch>=97&&ch<=122)
				c++;
		else if(ch==32)
				sp++;
		else if(ch>=48&&ch<=57)
				ma++;
		else if(ch!=10) 
				q++;
	}
	printf("zimu%d\n",c);
	printf("shuzi%d\n",ma);
	printf("space%d\n",sp);
	printf("qita%d\n",q);
	return 0;
}
