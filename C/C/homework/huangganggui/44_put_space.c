#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void deal(char *str_new,char*str_old);
void create_memory(char **str,char *s);
void input(char str[],int length);

int main()
{
	char str_old[1024];
	char *str_new;

	input(str_old,1024);
//	puts(str_old);
	
	create_memory(&str_new,str_old);

	deal(str_new,str_old);
	puts(str_new);

	free(str_new);
	return 0;
}

void input(char str[],int length)
{
	int i;
	char ch;
	for(i=0;scanf("%c",&ch)&&ch != 10; i++)
	{
		if(i>=length -1)
		{
			printf("Error ! The string you input is too long !\n");
			exit(-1);
		}
		*(str+i)=ch;
	}
	*(str +i)=0;
}

void create_memory(char **str,char *s)
{
	*str=(char *)malloc((strlen(s)/3*4+strlen(s)%3+1)*sizeof(char));
	if (NULL == *str)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}
void deal(char *str_new,char*str_old)
{
	int i,j;
	for(i=0,j=0;0 != *(str_old+i-1);i++,j++)
	{
		*(str_new+j)=*(str_old + i);
		if(0 == (i+1)%3)
		{
			j++;
			*(str_new+j) = ' ';
		}
	}
}
