#include<stdio.h>
int bijiao(int a,int b,int c);
int main()
{	
	int a,b,c;
	printf("输入3个数")；
	scanf("%d%d%d",&a,&b,&c);
	bijiao(a,b,c);
}
	      
int bijiao(int a,int b,int c)
{
	int n; 
	if(a<b)
		{
		  n=a;
			a=b;
			b=n;
		}			
		if(a<c)
		{
			n=a;
			a=c;
			c=n;
		}
		if(b<c)
		{
			n=b;
			b=c;
			c=n;
		}
	n=a-c;
	printf("最大值是%d, 最小值是%d\n",a,c);
	printf("%d-%d=%d",a,c,n);
	return 0;
}













































































































