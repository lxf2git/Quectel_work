#include"../../apue.h"
int main()
{
	int n;	
	char *p = NULL;
	int fd = open("mmap",O_RDWR|O_CREAT,0777);	
	if(fd<0)
	{
		show_err("open");
	}

	ftruncate(fd,1024);//将文件截到1k长

	 p = (char *)mmap(0,1024,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);//建立文件和内存的映射
	if(p==MAP_FAILED)
	{
		show_err("mmap");
	}
//从键盘输入数据 放到共享内存 另一个程序读取
for(;;)
{
	n = read(0,p,1024);
	if(n<0)
	{
		break;
	}
}
	munmap(p,1024);//解除映射

	close(fd);



	return 0;

}
