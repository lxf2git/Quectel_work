#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *deal(int l1,int l2,char *p1,char *p2,int flag);
void input(char *pt,int len);
int creat_memory(char **pt);
int main()
{
	char *str1=NULL;
	char *str2=NULL;
	int flag;
	int len1,len2;
	int i;
	len1 = creat_memory((char **)&str1);
	input(str1,len1);
	len2 = creat_memory((char **)&str2);
	input(str2,len2);
	printf("%s\n",deal(len1,len2,str1,str2,flag));

	return 0;
}
char *deal(int l1,int l2,char *p1,char *p2,int flag)
{
	char *p=NULL;
	printf("Flag:\n");
	scanf("%d",&flag);
	p=(char *)malloc((l1+l2)*sizeof(char));
	if(flag==0)
	{
		strcat(p,p1);
		strcat(p,p2);
	}
	else if(flag==1)
	{
		strcat(p,p2);
		strcat(p,p1);
	}
	return p;
}
void input(char *pt,int len)
{
	printf("please put in:\n");
	scanf("%s",pt);
	*(pt+len)=0;
}

int creat_memory(char **pt)
{
	int len;
	printf("Str Len:\n");
	scanf("%d",&len);
	*pt = (char *)malloc((len+1)*sizeof(char));
	if(pt==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	return len;
}
