#include<stdio.h>



int main()
{
	int a,b;
	printf("输入两位正整数a\n");
	scanf("%d%d",&a,&b);
	int i,j;
	int c[2][2]={'0'};
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			if(i==0&&j==0)
			c[i][j]=b%10;
			if(i==0&&j==1)
			c[i][j]=a/10;
			if(i==1&&j==0)
			c[i][j]=b/10;
			if(i==1&&j==1)
			c[i][j]=a%10;	
		}
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			printf("%d",c[i][j]);
		}
	return 0;
}
