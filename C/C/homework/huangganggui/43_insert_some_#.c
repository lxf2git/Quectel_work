#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input(char *str);
void insert(char *str);

int main()
{
	char *str;
	str=(char *)malloc(1000*sizeof(char));
	if(NULL==str)
	{
		printf("malloc error\n");
		exit(-1);
	}
	
	input(str);

	insert(str);

	puts(str);
	free(str);
	return 0;
}

void input(char *str)
{
	printf("input a string,i will give you some '#'!\n");
	scanf("%s",str);
}

void insert(char *str)
{
	int i=0,k=0,s=1,j=1;
	for(i=1;0 != *(str + i);i++)
	{
		s= 2 * i -1;
		printf("s:%d\n",s);
		for(k=strlen(str);k >= i;k--)
		{
			*(str + k + s) = *(str + k);
		}
		for(k=0;k < s;k ++)
		{
			*(str + k + i)='#';

		}
		
		str +=s;

	}
}
