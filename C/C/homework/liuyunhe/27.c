#include<stdio.h>

int main()
{
		int a,b,m,n,i,j,c;
		printf("分别输入两个两位数\n");
		scanf("%d",&a);
		scanf("%d",&b);
		m=a/10;//a的十位
		n=a%10;//a的个位
		i=b/10;//b的十位
		j=b%10;//b的个位
		c=(m*100+n+i*10+j*1000);
		printf("形成的新数为：\n");
		printf("%d",c);
		return 0;
}
