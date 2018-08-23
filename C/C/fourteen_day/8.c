
#include<stdio.h>
int main()
{
	char s[20],*sp="HELLO";
	sp = strcpy(s,sp);	
	s[0]='h';
	puts(sp);
	return 0;

}
