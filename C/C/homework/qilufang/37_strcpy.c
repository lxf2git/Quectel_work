#include<stdio.h>
#define N 20
void mystrcpy(char *p1,char *p2);
int main()
{
	char str_1[N]={'\0'};
	char str_2[N]={'\0'};
	printf("输入两个进行操作的字符串：\n");
	gets(str_1);
	gets(str_2);
	mystrcpy(str_1,str_2);
	printf("复制后输出：\n");
	puts(str_1);
	return 0;

}
void mystrcpy(char *p1,char *p2)
{
	int m=0,n=0,i,j;
	while(*(p1+m)!=0)
	{
		m++;
	}
	while(*(p2+n)!=0)
	{
		n++;
	}
//	printf("M::%dN::%d",m,n);
	if(n<=m)
	{
			for(i=0;i<n;i++)
			*(p1+i)=*(p2+i);
	}
	else if(n>m)
	{
			for(j=0;j<m;j++)
			*(p1+j)=*(p2+j);
	}
	
}
