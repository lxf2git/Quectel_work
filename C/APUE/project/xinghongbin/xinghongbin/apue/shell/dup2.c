#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 #include <string.h>
int myDup(char*fileName,int mode);
int judge_dup(int argc,char **argv)
{
		int i;
		char *str;
		for(i=1;i<argc;i++)
		{
			if(	(str = strchr(argv[i],'>') ) != NULL)
			{
					if (*(str+1) == '>') 
							addion(str+2,1);
					else
							myDup(str+1,1);
					return 0;
			}
			if(	(str = strchr(argv[i],'<') ) != NULL)
			{

					myDup(str+1,0);
					return 0;
			}
			
		}	
		return 0;
}
int myDup(char*fileName,int mode)
{
		int fd;
		fd=open(fileName,O_RDWR|O_CREAT|O_TRUNC,0666);
		if(fd == -1)
		{
				perror("open file");
				return 0;
		}
		dup2(fd,mode);
		return 0;

}
int addion(char *fileName,int mode)
{
		int fd;
		fd=open(fileName,O_RDWR|O_CREAT|O_APPEND,0666);
		if(fd == -1)
		{
				perror("open file");
				return 0;
		}
		dup2(fd,mode);
		return 0;


}
