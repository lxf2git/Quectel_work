#include"main.h"
void file_cp(char *path_start,char *path_end)
{
	char arr[N];
	int nb=0;
	memset(arr,0,sizeof(arr));
	int op_start=0;
	int op_end=0;
	op_start=open(path_start,O_RDONLY);
	/*char now_addr[M];
	getcwd(now_addr,sizeof(now_addr));
	puts(now_addr);*/
	if(op_start<0)
	{
		perror("open_start");
		exit(-1);
	}
	op_end=open(path_end,O_CREAT|O_EXCL|O_WRONLY);
	if(op_end<0)
	{
		op_end=open(path_end,O_TRUNC|O_WRONLY);
		if(op_end<0)
		{
			perror("open_end");
			exit(-1);
		}
	}
	while(1)
	{	
		memset(arr,0,sizeof(arr));
		if((nb=read(op_start,arr,120))<0)
		{
			perror("read");
			exit(-1);
		}
		if(nb==0)
		{
			break;
		}
		if((write(op_end,arr,nb))<0)
		{
			perror("write");
			exit(-1);
		}
		
	}
	get_prevDir_Addr(path_end);
	get_prevDir_Addr(path_start);
	close(op_start);
	close(op_end);
}
