#include<stdio.h>
int max(int a,int b);
int min(int a,int b);
int jian(int a,int b);
int main()
{
	int a,b,c;
	int i,j,p;
	printf("输入三个数字：\n");
	scanf("%d%d%d",&a,&b,&c);
	i=max(max(a,b),c);
	j=min(min(a,b),c);
	printf("最大值为：%d\n",i);
	printf("最小值为：%d\n",j);
	p=jian(i,j);
	printf("相差为：%d\n",p);	

return 0;
}
int max(int a,int b)
{
	int t;
	if(a<b){
		t=a;
		a=b;
		b=t;}
	return a;
}
int min(int a,int b)
{
	int t;
	if(a>b){
		t=a;
		a=b;
		b=t;}
	return a;
}
int jian(int a,int b)
{
	int t;
	t=a-b;
	return t;
}
 
