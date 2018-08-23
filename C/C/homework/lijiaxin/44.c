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
		int length;
		printf("请输入字符长度:\n");
		scanf("%d",&length);
		create_memory((void **)p,length*sizeof(char));
}
void deal(char *p,char *q)
{
		int count,i;
		char *temp=q;
		getchar();
		gets(p);
		count = strlen(p);
		for(i=0;i<count;i++)
		{
				*q = p[i];
				 q += 1;
				if((i+1)%3==0)
				{
						*q = ' ';
						q++;
				}
		}
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
