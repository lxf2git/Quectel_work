#include"main.h"

int main(int argc, char **argv)
{
		int ret;
		char src_path[100],dest_path[100];
		getcwd(src_path,sizeof(src_path));
		getcwd(dest_path,sizeof(dest_path));
		if(argc!=3)
		{
				printf("%s dirent name\n",argv[0]);
				return -1;
		}
		if(argv[2][0]!='/'&&argv[1][0]!='/')
		{
				strcat(src_path,"/");
				strcat(src_path,argv[1]);
				strcat(dest_path,"/");
				strcat(dest_path,argv[2]);
				scna(src_path,dest_path);
		}
		else
		if(argv[2][0]!='/')
		{
				strcat(dest_path,"/");
				strcat(dest_path,argv[2]);
				scna(argv[1],dest_path);
		}
		else
		if(argv[1][0]!='/')
		{
				strcat(src_path,"/");
				strcat(src_path,argv[1]);
				scna(src_path,argv[2]);
		}
		else
		{
				scna(argv[1],argv[2]);
		}
		return 0;
}

void copy(char *src_file, char *dest_file)
{
		char buf[1024];
		int src_fid,dest_fid;
		int n;
		src_fid=open(src_file,O_RDONLY);
		if(src_fid<0)
		{
				printf("***\n");
		}
		dest_fid=open(dest_file,O_CREAT|O_EXCL|O_WRONLY,0777);
		if(dest_fid<0)
		{
				printf("...\n");
		}
		while(1)
		{
				n=read(src_fid,buf,sizeof(buf));
				if(0==n)
				{
						break;
				}
				if(n<0)
				{
						perror("read");
						exit(-1);
				}
				write(dest_fid,buf,n);
		}
		close(src_fid);
		close(dest_fid);
}

void scna(char *src_dir, char *dest_dir)
{
		int ret;
		char src_path[100],dest_path[100],src_file[100],dest_file[100];
		DIR *pdir=NULL;
		struct stat st;
		struct dirent *pdirent=NULL;
		pdir=opendir(src_dir);
		mkdir(dest_dir,0777);
		chdir(src_dir);
		if(NULL==pdir)
		{
				return;
		}
		while(1)
		{
				pdirent=readdir(pdir);
				if(NULL==pdirent)
				{
						break;
				}
				if(strcmp(pdirent->d_name,"..")!=0&&strcmp(pdirent->d_name,".")!=0)
				{
						ret=stat(pdirent->d_name,&st);
						if(ret<0)
						{
								perror("stat");
								exit(-1);
						}
						if(S_ISDIR(st.st_mode))
						{
								new_str(src_path,dest_path,src_dir,dest_dir,pdirent->d_name);
								scna(src_path,dest_path);
						}
						else
						{
								new_str(src_file,dest_file,src_dir,dest_dir,pdirent->d_name);
								copy(src_file,dest_file);
						}
				}
		}
		closedir(pdir);
		chdir("..");
}

void new_str(char *src,char *dest,char *src_dir,char *dest_dir,char *d_name)
{
		strcpy(src,src_dir);
		strcat(src,"/");
		strcat(src,d_name);
		strcpy(dest,dest_dir);
		strcat(dest,"/");
		strcat(dest,d_name);
}
