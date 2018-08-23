#include"../apue.h"
int main()
{
	unsigned int x = 0x12345678;
	char *p = NULL;
	int i;
	for(p=(char*)&x,i=0;i<4;i++,p++)
	{
		printf("%x  ",*p);
	}
	printf("\n");
	puts("==============================");
	x = htonl(x);

	for(p=(char*)&x,i=0;i<4;i++,p++)
	{
		printf("%x  ",*p);
	}
}
