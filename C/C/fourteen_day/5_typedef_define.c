#include<stdio.h>
#define CHR char *
typedef  char*  CH;
int main()
{
	CHR a,c;//char *a,c;
	CH b,d;//char *b,*d;
	printf("sizeof(a):%d\n",sizeof(a));	
	printf("sizeof(c):%d\n",sizeof(c));	
	printf("sizeof(b):%d\n",sizeof(b));	
	printf("sizeof(d):%d\n",sizeof(d));	
		
	return 0;

}
