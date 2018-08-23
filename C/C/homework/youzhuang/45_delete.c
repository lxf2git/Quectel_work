#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100

char *delete(char *p);
void input(char *p);
void create_memory(void **p,int size);

int main()
{
		char *p;
		create_memory((void **)&p,N*sizeof(char));
		input(p);
		printf("after delete#:%s\n",delete(p));
		free(p);
		return 0;
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

void input(char *p)
{
		printf("please input string:\n");
		scanf("%s",p);
}
char *delete(char *p)
{
		char *new_string;
		int i,j,k=0;
		create_memory((void **)&new_string,N*sizeof(char));
		for(i=0;i<strlen(p);i++)
		{
				if(p[i]=='#')
				{
						for(j=i+1;j<=strlen(p);j++)
						{
								if(p[j]=='\0')
								{
										new_string[k]='\0';
										return new_string;
								}
								if(p[j]=='#')
								{
										i=j;
										break;
								}
						}
				}
				else
				{
						new_string[k]=p[i];
						k++;
				}
		}
		new_string[k]='\0';
		return new_string;
}
