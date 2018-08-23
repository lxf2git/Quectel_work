#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void create_memory(char **p,int size);
int str_input(char *p);
void str_move(char *p,int n);
int main()
{
		int n;
		char *p;

		create_memory(&p,100);
		n=str_input(p);
		str_move(p,n);
		return 0;
}
void create_memory(char **p,int size)
{
		*p=malloc(size);
}
int str_input(char *p)
{
		int n;
		printf("input str\n");
		scanf("%s",p);
		printf("input n to move\n");
		scanf("%d",&n);
		return n;
}

void str_move(char *p,int n)
{
		int i,j;
		int length = strlen(p);
		
		for(;n<0;)
				n=n+length;
		n=n%length;
		for(i=length-1;i>=0;i--)
		{
				p[i+n]=p[i];
		}
		for(i=length,j=0;i<length+n;i++,j++)
		{
				p[j]=p[i];
		}
		p[length]='\0';
		printf("%s\n",p);
}
