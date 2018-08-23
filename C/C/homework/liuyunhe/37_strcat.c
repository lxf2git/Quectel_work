#include<stdio.h>

char my_strcat(char *dest,char *src)
{
		int i=0,j;
		while(*(dest+i)!=0)
		{
				i++;
		}
		for(j=0;*(src+j)!=0;j++)
		{
				*(dest+j+i)=*(src+j);
				printf("%c\n",*(dest+j+i));
		}
}

int main()
{
		char str1[20]={'0'};
		char str2[10]={'0'};
		gets(str1);
		gets(str2);
		my_strcat(str1,str2);
		puts(str1);
		return 0;
}
