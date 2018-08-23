#include<stdio.h>
#define N 20
void  mystrcat(char *p1,char *p2);
int main()
{	
	char str_1[N]={'\0'};
	char str_2[N]={'\0'};
	printf("输入字符串1：\n");
	gets(str_1);
	printf("输入字符串2：\n");
	gets(str_2);
	mystrcpy(str_1,str_2);
	printf("合并后输出：\n");
	puts(str_1);

	return 0;

}
void mystrcat(char *p1,char *p2)
{
		int i=0,j,k=0;
		while(*(p1+i)!=0)
		{
			i++;
		}
		while(*(p2+k)!=0)
		{
			k++;
		}	
//		printf("I==%d",i);
		for(j=0;j<i+k;j++)
		{
			*(p1+i+j)=*(p2+j);
		}
}
