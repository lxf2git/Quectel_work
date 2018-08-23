#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void create_memory(void **q,int size)
{
		*q = malloc(size);
		if(*q==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}
void input(char **p)
{
		int room;
		printf("请输入需要的空间:\n");
		scanf("%d",&room);
		create_memory((void **)p,room*sizeof(char));
}
void deal(char *p,char *p1,char *p2)
{
		char *temp=NULL,*temp1=NULL;
		int n,length = 0;
		int i;
		getchar();
		printf("请输入需要操作的字符串:\n");
		gets(p);
		length = strlen(p);
		printf("请输入右移的位数:\n");
		scanf("%d",&n);
		n = n % length;
		temp = p1;
		temp1 = p2;
		for(i=length-n;i<length;i++)
		{
				*p1++ = p[i];
		}
		*p1++ = '\0';
		p1 = temp;
		for(i=0;i<length-n;i++)
		{
				*p2++ = p[i];
		}
		*p2++ = '\0';
		p2 = temp1;
		strcat(p1,p2);
		puts(temp);
		if(p!=NULL)
		{
				free(p);
				p = NULL;
		}
		if(p1!=NULL)
		{
				free(p1);
				p1 = NULL;
		}
		if(p2!=NULL)
		{
				free(p2);
				p2 = NULL;
		}
		
}
int main()
{
		char *str=NULL,*str1=NULL,*str2=NULL;
		input(&str);
		input(&str1);
		input(&str2);
		deal(str,str1,str2);
		return 0;
}








