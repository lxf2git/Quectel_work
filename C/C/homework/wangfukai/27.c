#include<stdio.h>

int main()
{
	int a,b,c[4],i,h,j,x,y;
	printf("请输入两个两位正整数：");
	scanf("%d %d",&a,&b);
	i=a%10;
	j=a/10;
	x=b%10;
	y=b/10;
	/*c[0]=x;
	c[1]=j;
	c[2]=y;
	c[3]=i;*/
	//for(h=0;h<4;h++)
	
		printf("%d%d%d%d",x,j,y,i);
		//printf("%d",c[4]);	
	
	return 0;
}
