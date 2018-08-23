#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//见名知意
int main(int argc,char **argv)
{
	int fid_src,fid_dest;
	int ret1,ret2;
	char buf[1024];

	if(argc != 3)
	{
		printf("%s file_name\n",argv[0]);
		return -1;
	}

	fid_src = open(argv[1],O_RDONLY);
	if(fid1 < 0)
	{
		perror("open1");
		goto ERR;
	}
	fid_dest = open(argv[2],O_CREAT|O_EXCL|O_RDWR, 0777);
	if(fid2 < 0)
	{
			if(errno==EEXIST)
			{
					fid_dest=open(argv[2], O_WRONLY|O_TRUNC);
					if()
			}
	}


	while(1)
	{
		ret1 = read(fid1, &buf, 1);
		if(ret1 <= 0)
		{
			break;
		}
		ret2 = write(fid2, &buf, 1);
		if(ret2 <= 0)
		{
			break;
		}
	}
ERR:
	close(fid1);
	close(fid2);
	return 0;
}
