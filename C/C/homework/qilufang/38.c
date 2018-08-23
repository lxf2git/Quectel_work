#include<stdio.h>
int cifang(int *px,int *py);
void output(int *a);
int main()
{
	int abb,power,result=0;
	printf("输入一个基数：\n");
	scanf("%d",&abb);
	printf("输入次方：\n");
	scanf("%d",&power);
	result=cifang(&abb,&power);
	printf("result:%d\n",result);
	output(&result);
	return 0;

}
int cifang(int *px,int *py)
{	
	int b;
	if(*py>0)
	{
		(*py)--;
		b=*px*cifang(px,py);
	}
	else if(*py==0)
	{
		b=1;
	}
	return b;
}
void output(int *a)
{
	int i,b=0,j;
	int put[3]={0};
	for(i=0;;i++)
	{
		put[b]=*a%10;
		*a=*a/10;
		b++;
		if(b==3)
		break;
	}
	printf("输出后三位：\n");
	for(j=2;j>=0;j--)
	{
		printf("%d",put[j]);
	}
	printf("\n");
}
