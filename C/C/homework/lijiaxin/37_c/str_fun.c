#include"str_fun.h"

char *mystrcpy(char *dest, char *src)
{
		int i=0;
		while(*(src+i)!='\0')
		{
			*(dest+i) = *(src+i);
			i++;
		}
		*(dest+i) = '\0';
		return dest;
}


char *mystrcat(char *dest, char *src)
{
		int i=0,j=0;
		while(*(dest+i)!='\0')
		{
			i++;
		}
		while(*(src+j)!='\0')
		{
			*(dest+i+j) = *(src+j);
			j++;
		}
		*(dest+i+j) = '\0';
		return dest;
}

int mystrcmp(char *s1, char *s2)
{
		int i;
		for(i=0;;i++)
		{
				if(*(s1+i)=='\0'&&*(s2+i)=='\0')
			
						return 0;
				if(*(s1+i)!=*(s2+i))
				return (*(s1+i)-*(s2+i));
	
		}
}
