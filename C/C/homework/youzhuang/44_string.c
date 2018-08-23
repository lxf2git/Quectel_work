#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1024

char *new_string(char str_old[N]);
void create_memory(void **p,int size);
void input(char str_old[N]);
int main()
{
		char str_old[N];
		input(str_old);
		printf("new string:%s\n",new_string(str_old));
		return 0;
}

void input(char str_old[N])
{
		printf("please input:\n");
		scanf("%s",str_old);
}

char *new_string(char str_old[N])
{
		char *str_new;
		int size,i,j=0;
		size=strlen(str_old)+strlen(str_old)/3;
		create_memory((void **)&str_new,size);
		for(i=0;i<strlen(str_old);i++)
		{
				str_new[j]=str_old[i];
				j++;
				if((i+1)%3==0)
				{
						str_new[j]=' ';
						j++;
				}
		}
		str_new[j]='\0';
		return str_new;
}

void create_memory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("create memory error!\n");
				exit(-1);
		}
}
