#define _XOPEN_SOURCE
#include "../apue.h"
//gcc test.c -lcrypt -o exe
int main()
{
	char str[]="123456";
	char *p=NULL;

	p=crypt(str, "a");
	printf("p=%s\n", p);

	p=crypt(str, "b");
	printf("p=%s\n", p);
}
