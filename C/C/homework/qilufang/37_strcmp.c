#include<stdio.h>
#define N 10
int strcmp(char *p1,char *p2);
int main()
{
	char str_1[N]={'\0'};
	char str_2[N]={'\0'};
	printf("输入两个进行操作的字符串：\n");
	gets(str_1);
	gets(str_2);
	printf("输出操作后的结果：\n");
	return 0;

}
int strcmp(char *p1,char *p2)
{
	int i,m=0;
	for(i=0;*(p1+i)!=0&&*(p2+i)!=0;i++)
	{
		if(*(p1+i)==*(p2+i))
		{
			m=0;
		}
		else if(*(p1+i)>*(p2+i))
		{
			m=*(p1+i)-*(p2+i);
			break;
		}
		else
		{
			m=*(p2+i)-*(p1+i);
			break;
		}
	}
	return m;
}
