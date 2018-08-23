#include"../apue.h"
int main()
{
	char ip[]="192.168.1.200";
	struct in_addr addr;
	/*
	 *struct in_addr 
	 {
	 	in_addr_t s_addr;
	 }
	 * */
	printf("inet_addr:%d\n",inet_addr(ip));
	//inet_aton(ip,&addr);
	printf("addr:%d\n",addr.s_addr);

	printf("addr:%s\n",inet_ntoa(addr));

}
