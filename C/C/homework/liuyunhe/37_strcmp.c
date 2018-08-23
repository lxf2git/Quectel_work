#include<stdio.h>
int my_strcmp(char *s1,char *s2)
{
		int i,n=0,m=0;
		for(i=0;(*(s1+i)!='\0')&&(*(s2+i)!='\0');i++)
		{
				n++;
				if(*(s1+i)==*(s2+i))
				{
						m=0;
			//	printf("111%d\n",m);
				}
				else
				{
						m=*(s1+i)-*(s2+i);
			//	printf("222%d\n",m);
						break;
				}

		}
		if(*(s1+n)=='\0'||*(s2+n)=='\0')
		{
				m=*(s1+n)-*(s2+n);
			//	printf("333%d\n",m);
		}
		return m;
}

int main()
{
		int m;
		char s1[100]={'\0'};
		char s2[100]={'\0'};
		printf("输入字符串1\n");
		gets(s1);
		printf("输入字符串2\n");
		gets(s2);
		m=my_strcmp(s1,s2);
		printf("%d\n",m);
		return 0;
}
