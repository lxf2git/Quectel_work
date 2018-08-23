#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
typedef struct
{
		int id;
		char name[20];
		char hehe[20];
}cdata;
int main()
{
	int fd = open("file",O_RDWR|O_APPEND|O_CREAT,0666);
	int i;
	off_t offset=0;
	offset=lseek(fd,0,SEEK_END);
	ftruncate(fd,offset);
	cdata udata;
	cdata *p=NULL;
	p=(cdata *)mmap(0,offset,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);//这里第二个参数只要不是0，那它就能自动分配空间
	cdata hehe;
	hehe.id=100;
	strcpy(hehe.name,"anfwef");
	p[0]=hehe;
//	strcpy((p[2]).name,"hihi");p[1].id=10100;
	
	printf(" %d %s\n %d %s\n %d %s\n",(p[0]).id,(p[0]).name,(p[1]).id,(p[1]).name,p[2].id,p[2].name);
	munmap(p,offset);
/*	cdata udata;
	for(i=0;i<20;i++)
	{
		udata.id = 501278893;
		strcpy(udata.name,"duoduo");
		write(fd,&udata,sizeof(udata));
	}*/
	close(fd);
	
	return 0;
}
