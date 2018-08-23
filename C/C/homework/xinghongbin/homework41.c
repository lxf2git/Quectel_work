#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define R 2
#define C 100
void creat_memory(void **p,int size);
void str_input(char *a);
int flog_input();
char *str_compose(int flog,char *str1,char *str2);
int main()
{
		char **str;
		int flog;
		char *str_com;
		creat_memory((void **)&str,2);
		creat_memory((void **)str,100);
		creat_memory((void **)str+1,100);
		str_input(*str);
		str_input(*(str+1));
		flog=flog_input();
		str_com=str_compose(flog,*str,*(str+1));
		if(str_com != NULL)
				printf("%s\n",str_com);
}
void creat_memory(void **p,int size)
{
		*p = malloc(size);
		
}


void str_input(char *a)
{
		printf("please input str\n");
		scanf("%s",a);
}

int flog_input()
{
		int flog;
		printf("please input flog\n");
		scanf("%d",&flog);
		return flog;
}
char *str_compose(int flog,char *str1,char *str2)
{
		char *q;
		if(flog==0)
				q=strcat(str1,str2);
		else if(flog==1)
				q=strcat(str2,str1);
		else 
		{
				printf("error\n");
				q=NULL;
		}
		return q;
}
