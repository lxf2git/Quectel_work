#include"main.h"
/*作业：***********************************《作业2》
实现：
ls       文件名称
ls -l    属性+文件名称
ls -a    所有文件名称
ls -i    inode+文件名称
ls -la   所有文件属性+文件名称
ls -li   文件属性+文件名称+inode
ls -lia  所有文件属性+文件名称+inode
ls -lia 文件/目录 
ls 文件/目录*/
int main(int argc,char **argv)
{
	DIR * pdir=NULL;
	int ret=0;
	int op_1=0;	
	FILE * op=NULL;
	char mode_output[4]={'0'};
	struct stat stat[N];
	char *file_name[N];
	memset(mode_output,0,sizeof(mode_output));
	judge_output(argc,argv,mode_output);
	op_1=chdir(argv[argc-1]);
	if(op_1==0)
	{
			if(NULL==(pdir=opendir(argv[argc-1])))
			{
				printf("opendir_error!\n");
				return -1;
			}
			ret=open_deal(stat,file_name,pdir);
			if(argc==3)
			{			
				output(stat,mode_output,ret,file_name);
			}
			else
				output_1(file_name,ret);
	}
	else	
	{
			if(NULL==(pdir=opendir(".")))
			{
				printf("opendir_error!\n");
				return -1;
			}
			if(argc==3)
			{		
				lstat(argv[2],&stat[0]);
				file_name[0]=malloc(sizeof(char)*M);
				memset(file_name[0],0,sizeof(file_name[0]));
				strcpy(file_name[0],argv[2]);		
				ret=1;
				output(stat,mode_output,ret,file_name);
			}
			else
			{
				ret=open_deal(stat,file_name,pdir);
				if(argc==1)
				{
					output_1(file_name,ret);
				}
				else 
				{	chdir(".");
					op=fopen(argv[1],"r");
					if(argc==2&&op!=NULL)
					{
						fclose(op);
						printf("%s\n",argv[1]);
					}
					else
					{	
						output(stat,mode_output,ret,file_name);
					}
				}	
			}
	}
	closedir(pdir);
	return 0;

}
