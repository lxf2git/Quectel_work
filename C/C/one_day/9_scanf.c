#include<stdio.h>

int main()
{
	int a,b;
	char c,ch;

	printf("请输入 int int char：\n");
	scanf("%d%d",&a,&b);//12 34
	//ch = getchar();//scanf
	scanf("%c",&c);
	printf("a:%d b:%d c:%d ch:%d\n",a,b,c,ch);
		
	return 0;
}
