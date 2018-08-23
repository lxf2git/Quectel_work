#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void create_memory(void **q,int size)
{
		*q = malloc(size);
		if(NULL==*q)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}
void input(char **p)
{
		int length=0;
		printf("请规定需要的字符空间:\n");
		scanf("%d",&length);
		getchar();
		create_memory((void **)p,length*sizeof(char));
}

void deal(char *p,char *q)
{
		int length,n,i;
		char *temp;
		temp = q;
		printf("请输入一串字符:\n");
		gets(p);
		length = strlen(p);
		for(i=1;i<length;i++)
		{
				*q = p[i-1];
				q++;
				for(n=1;n<=2*i-1;n++)
				{
						*q = '#';
						q++;
				}
		}
		*q = p[i-1];
		puts(temp);
}
int main()
{
		char *str=NULL,*str1=NULL;
		input(&str);
		input(&str1);
		deal(str,str1);
		return 0;
}
