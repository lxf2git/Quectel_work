
#define _FILE_OFFSET_BITS 64
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp = fopen("/home/Soft/rhel-server-6.4-i386-dvd.iso","r+");

	if(NULL==fp)
	{
		printf("fopen err");
		exit(-1);
	}	

	fseeko(fp,(off_t)1024*(off_t)1024*(off_t)1024*10,SEEK_SET);//1k=1024byte  1m=1k*1024 1g=1m*1024

	return 0;

}
