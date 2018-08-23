#include"./apue.h"
int main()
{
  int fd;
  pid_t cmp;
  pid_t pid;
  char buf[256];
  memset(buf,0,sizeof(buf));
  fd=open("file1",O_RDWR);
  if(fd<0)
    {
      perror("open");
    }
  while(1)
    {
      if(read(fd,&cmp,sizeof(pid_t))==0)
	{
	  break;
	}
      sprintf(buf,"kill -9 %d",cmp);
      system(buf);
      memset(buf,0,sizeof(buf));
    }
  close(fd);
  
	return 0;
}
