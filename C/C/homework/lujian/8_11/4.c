#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  N  (1000)
void creat(void**s, int size);
int input(char* s);
int deal_str(char* s);
int main() 
{
	char *s = NULL;

	creat((void**)&s, N*sizeof(*s));
	input(s);
	deal_str(s);

	if (NULL != s)
	{
	free(s);
	s=NULL;
	}

	 return 0; 
}

void creat(void**s, int size)
{

	*s = malloc(size);

	if (NULL == *s)
	{
		printf("please input malloc error  \n"); 	
	
	}
}

int input(char* s)
{
	printf("please input \n");
   	gets(s);	

	return 0; 
}

int deal_str(char* s)
{	
		int n, i, j;
		char str[N];
				n = strlen(s);
		if (1==n)
		{
				puts(s);
				return 0;

		}
		else
		{
				for (i=0; i<(n-1)*(n-1)+n; i++)
				{
						str[i] = '#';		
				}
				str[i]='\0';
				for (i=0, j=0;str[i] !='\0' ; j++)
				{
						str[i] = *(s+j);
						i = i +(j+1)*2;
				}

		}
		puts(str);

		return 0; 

}











