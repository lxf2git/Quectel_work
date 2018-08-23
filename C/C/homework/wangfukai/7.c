#include<stdio.h>
int main()
{
	int a,space,n,other;
        char y;
	printf("请输入字符串：");
	//scanf("%c",&y);
	
	a=0,space=0,n=0,other=0;
	while((y=getchar())!=10)
{	if(y>=65&&y<=90||y>=97&&y<=122)
	a=a+1;
	else if(y==32)
	space=space+1;
	else if((y>=48)&&(y<=57))
	n=n+1;
	else  
	other=other+1;
}
	printf("字母数为：%d",a);
	printf("空格数为：%d",space);
	printf("数字数为：%d",n);
	printf("其他为：%d",other);

	return 0;
}
