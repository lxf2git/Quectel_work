#include<stdio.h>

int mystrcpy(char *dest,char *src)
{
	char *strcpy(char *dest,char *src);
	return *dest;
}

int main()
{
	
	
	char *string1="a";
	char *string2="b";
	char *m=mystrcpy(string1,string2);
	printf("%s\n",string1);
	return 0;

}
