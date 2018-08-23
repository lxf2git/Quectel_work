#include<stdio.h>
int main()
{
	int a,b,c,t=0,m;
	scanf("%d%d%d",&a,&b,&c);
	t=t>a?t:a;
	t=t>b?t:b;
	t=t>c?t:c;
	m=m<a?m:a;
	m=m<b?m:b;
	m=m<c?m:c;
	printf("最大值：%d\n",t);
	printf("最小值：%d\n",m);
	printf("差：%d\n",t-m);
			
	return 0;

}
