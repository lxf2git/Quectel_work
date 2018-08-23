#include<stdio.h>
int main()
{
	int num,i,n=1,j;
	printf("请输入整数及其次方数:\n");
	scanf("%d,%d",&num,&i);
	for(j=0;j<i;j++)
			n=n*num;
	n=n%1000;
	printf("%d\n",n);
	return 0; 
}
