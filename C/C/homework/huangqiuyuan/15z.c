#include<stdio.h>
//#include"15z1.h"
//int jiahe (int x);
int main()
{
	int m,y,a,i,n,b,x=0;
	printf("输入一个100～500之间的整数\n");
	scanf("%d",&i);
	n=1;
	m=0;
	for(b=0;b<498;b++)
{
	n++;
	a=i%n;
	if(a==0&&n!=i)
{	
	printf("%d\n",n);
	m++;
	 x=x+n;
	//int y=jiahe (int x);	//
}	


}	
	printf("\n是这个数的约数");
	printf("\n有%d个\n",m);
	printf("它们的和为%d\n",x);
	return 0;

}
