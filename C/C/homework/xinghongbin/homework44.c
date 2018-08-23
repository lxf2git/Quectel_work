#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create_memory(char **p,int size);
void input_oldstr(char *p);
int input_space_length(char *p);
void input_space(char *new,char *old);
int main()
{
		int length;
		char str_old[1024];
		char *str_new;

		input_oldstr(str_old);
		length=input_space_length(str_old);
//		printf("%d\n",length);
		create_memory(&str_new,length);
		input_space(str_new,str_old);

		return 0;


}

void create_memory(char **p,int size)
{
		*p = (char *)malloc(size);

}

void input_oldstr(char *p)
{
		scanf("%s",p);
}

int input_space_length(char *p)
{
		int length,space;
		length=strlen(p);
		space=length/3;
		length+=space;
		return length+1;

}

void input_space(char *new,char *old)
{
		int i;
		int offset=0;
		int length=strlen(old);
		printf("%d\n",length);
		for(i=0;i<=length+offset;i++)
		{
				if((i+1)%4!=0)
						new[i]=old[i-offset];
				else
				{
						new[i]=' ';
						offset++;
				}
		}
//		new[i]='\0';
		printf("%s\n",new);
}
