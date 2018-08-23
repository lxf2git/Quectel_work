#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void create_memory(char **q,int size)
{
	*q = (char *)malloc(size);
	if(NULL==*q)
	{
		printf("malloc error");
		exit(-1);
	}
}

void fun(char *str_new,char str_old[])
{
	int size,i,n,j=0,k=0;
	printf("请输入新的字符串所占空间大小：");
		scanf("%d",&size);
	create_memory(&str_new,size);
	n=strlen(str_old);
	for(i=0;i<n;i++)
	{
		*(str_new+j)=str_old[i];
		j++;
		k+=1;
		if(k%3==0)
		{
			*(str_new+j)=32;
			k=0;
			j++;
		}
	}
	printf("str_new:%s\n",str_new);
	if(str_new!=NULL)
	{
		free(str_new);
		str_new=NULL;
	}
}

int main()
{
	char str_old[1024];
	char *str_new;
	printf("请输入字符串str_old：\n");
	scanf("%s",str_old);
	fun(str_new,str_old);
	return 0;
}



