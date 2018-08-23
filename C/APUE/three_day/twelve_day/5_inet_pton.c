#include"../apue.h"
int main()
{
	int i;
	in_addr_t nip;
	char sip[16];
	inet_pton(AF_INET,"192.168.1.200",&nip);
	unsigned char *p = (unsigned char *)&nip;

	for(i=0;i<4;i++)
	{
		printf("%d ",*p++);
	}
	printf("\n");

	inet_ntop(AF_INET,&nip,sip,sizeof(sip));
	puts(sip);
}
