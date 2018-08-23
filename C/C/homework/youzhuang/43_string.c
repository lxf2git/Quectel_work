#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100
void creat_memory(void **p, int size);
char *new_string(char *p);
void input(char *p);
int main()
{
		char *p;

		creat_memory((void **)&p,N*sizeof(char));
		input(p);
		printf("new string:%s\n",new_string(p));
		
		return 0;
}

void creat_memory(void **p, int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("creat memory error!\n");
				exit(-1);
		}
}

void input(char *p)
{
		printf("input:\n");
		scanf("%s",p);
}

char *new_string(char *p)
{
		char *new;
		int i,j=0,k,m=1;
		creat_memory((void **)&new,N*sizeof(char));
		for(i=0;i<strlen(p);i++)
		{
				new[j]=p[i];
				j++;
				if(i!=strlen(p)-1)
				{
						for(k=1;k<=m;k++)
						{
								new[j]='#';
								j++;
						}
						m+=2;
				}
		}
		new[j]='\0';
		return new;
}
