#include<stdio.h>
#include<string.h>

int main()
{
	char string[5]={'a','\0','b','\0'};	
	char string1[50]="123457890";
	char string2[20]="hi baby";
	printf("%s",strcpy(string1,string2));	
	//printf(string1);
	return 0;

}
