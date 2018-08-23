#include<stdio.h>

int main()
{
	char *p = "hello";
	p[1]='E';
	printf("%s",p);	
	

#if 0	
	char str[10]="hello";
   	str[1]='E';
#endif
	return 0;

}
