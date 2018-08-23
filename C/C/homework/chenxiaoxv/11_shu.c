#include<stdio.h>

int main()
{
	int a,b,c,d;
	printf("输入三个数:");
	scanf("%d%d%d",&a,&b,&c);
	if(a-b>0)
	   a=b;//a最小
	else if(a-c>0)
	   a=c;//c最小在a里面
	else if(b-c>0)
	   c=b;//c最大 b剧中 a最小
	d=c-a;
	printf("最小:%d\n",a);
	printf("最大:%d\n",c);
	printf("cha:%d\n",d);
return 0;
}
