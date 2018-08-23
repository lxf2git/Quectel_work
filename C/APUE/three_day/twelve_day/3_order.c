#include"../apue.h"
int main()//小端模式
{
	union 
	{
		int ival;
		unsigned char ch[4];
	}v;

	v.ival = 0x12345678;
	printf("%x %x %x %x\n",v.ch[0],v.ch[1],v.ch[2],v.ch[3]);
	//printf("%p %p %p %p\n",&v.ch[0],&v.ch[1],&v.ch[2],&v.ch[3]);
	printf("%d %d %d %d\n",v.ch[0],v.ch[1],v.ch[2],v.ch[3]);
}
