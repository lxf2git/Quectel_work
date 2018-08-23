#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * Getmemory()//p = &str  *p  str
{
	char p[20]="HELLO BABY";	
	
	return p;
	

}
int main()
{
	char *str=NULL;

	str = Getmemory();//str=&

	printf("str:%s\n",str);	

	return 0;

}
