#include<stdio.h>
#include<math.h>
#define N 5

int main()
{
  int m,i,j,b,c=0,a=0,input;
  char output[N]={'\0'};
	printf("输入一个数字：\n");
	scanf("%d",&input);
	if(input<0)
	{	
		c=1;
		input=fabs(input);
	}
	while(m!=0)
	{
		m=input/10;
		b=input%10;
		input=m;
		output[a]=b+48;
	    a++;
	}
	printf("变换模式后的数字：\n");
	if(c==1)
	{
		printf("-");
	}
	for(j=a-1;j>=0;j--)
	{
		printf("%c",output[j]);
	}
	return 0;
}
