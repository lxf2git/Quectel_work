#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
		printf("请输入字符串长度:\n");
		scanf("%d",&length);
		create_memory((void **)p,length*sizeof(char));
}
void deal(char *p,char *q)
{
		int i,j=0,length=0;
		char *temp=q;
		getchar();
		gets(p);
        length = strlen(p);  
		for(i=0;i<length;i++)
		{
				if(p[i]=='#')
						j++;
				if(j%2==0)
				{
						if(p[i]!='#')
						{		
							*q = p[i];
							q++;
						}
				}
				if(j%2!=0)
				{
						;
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
