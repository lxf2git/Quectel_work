#include<stdio.h>

int main()
{
	int a,b,c;
	int i,j,n,m;
	printf("请输入两个2位数的数a b：\n");
	scanf("%d%d",&a,&b);	
	i=a%10;     //a的数的各位
	j=a/10;		//a的数十位	
	m=b%10;		//b的各位	
	n=b/10;		//b的十位
	c=i+j*100+m*1000+n*10;
	printf("%d\n",c);

	return 0;
}
