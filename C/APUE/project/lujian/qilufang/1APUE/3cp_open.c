/*利用open\read\write\close实现cp命令*/

#include <sys/types.h>      
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	int fid_1;
	int fid_2;
	int ret;
	char cp[5]="mycp";
	char arr[1024];
	if(argc!=3||strcmp(argv[0],cp)!=0)
	{
		perror("file_name");
		return -1;
	}
	fid_1=open(argv[1],O_RDWR);
	if(fid_1<0)
	{
		perror("open");
		return -1;
	}
	open(argv[2],O_CREAT|O_EXCL);
	fid_2=open(argv[2],O_RDWR);		
	while(1)
	{
		memset(arr,0,strlen(arr));
		ret=read(fid_1,arr,120);
		write(fid_2,arr,ret);
		if(ret==0)
		{
			break;
		}
	}
	close(fid_1);
	close(fid_2);
	return 0;

}
