#include<stdio.h> 
#include <dirent.h>
#include"apue.h"
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <fcntl.h>
#include<string.h>
#include<unistd.h>
sBdy buf;
int getfile(char *filename,char *file ,int confd)
{
		printf("接到的文件名字:%s\n",filename);
		int fd=open (filename,O_RDONLY);
		if(fd<0)
		{
				sprintf(file,"no_file");
				sprintf(buf.buf,"%s",file);
				write (confd,&buf,sizeof(buf));
				close(fd);
				return 0;//打不开		
		}
		else
		{
			while(1)
			{
				if(read(fd,file,512)<=0)
				{
					close(fd);
					break;
				}
				buf.file_op.file_type = 0;
				strncpy(buf.buf,file,strlen(file));
			//	sprintf(buf.buf,"%s",file);
				printf("文件内容:%s\n",buf.buf);
				sprintf(buf.file_op.file_name,"%s",filename);
				write (confd ,&buf,sizeof(buf));
				printf("传递的文件:%s\n",buf.file_op.file_name);
				bzero(&buf,sizeof(buf));
			}
			close(fd);
			return 1;//传完
		}
}
void putfile(char *filename,char *file)
{
		printf("filename:%s\n",filename);
		int fd=open(filename,O_CREAT|O_WRONLY,0666);
		write(fd,file,strlen(file));
		close(fd);
}
void putdocument(char *filename,char *file,int confd)
{
		char a[100];
		
		sprintf(a,"mkdir %s",filename);
		system(a);
				
}
int  getdocument(char *filename,char *file,int confd)
{
		//目录
		char sour_path[100]={'\0'};
		struct stat info;
		struct dirent *pdir=NULL;
		DIR *dp=opendir(filename);
		//printf("传递前:%s\n",filename);
		if(NULL==dp)
		{
				getfile(filename,file,confd);
				return -1;				
		}
		if((chdir(filename))<0)
		{
				perror("chdir");
				return -1;
		}
		
		//确定目录 传回绝对路径		
		bzero(&buf,sizeof(buf));
		buf.file_op.file_type = 1;
		sprintf(buf.file_op.file_name,"%s",filename);
		write (confd ,&buf,sizeof(sBdy));
		
		printf("第2次传递:%s\n",buf.file_op.file_name);
		
		while(1)
		{
				//遍历	
				pdir=readdir(dp);
				if(pdir==NULL)
				{
						chdir("..");
						return 0;
				}
				if(pdir->d_name[0]!='.')
				{
						lstat(pdir->d_name,&info);
						//文件
						if(S_ISREG(info.st_mode))
						{
								bzero(sour_path,sizeof(sour_path));
								getcwd(sour_path,100);
								strcat(sour_path,"/");
								strcat(sour_path,pdir->d_name);
								printf("文件:%s\n",pdir->d_name);//
								getfile(sour_path,file,confd);
						}
						//目录
						if(S_ISDIR(info.st_mode))
						{
								bzero(&buf,sizeof(buf));
								buf.file_op.file_type = 1;
								bzero(sour_path,sizeof(sour_path));
								getcwd(sour_path,100);
								strcat(sour_path,"/");
								strcat(sour_path,pdir->d_name);
								sprintf(buf.file_op.file_name,"%s",sour_path);
								printf("目录:%s\n",buf.file_op.file_name);//
							//	write (confd ,&buf,sizeof(sBdy));
								
								getdocument(sour_path,file,confd);
						}
				}
		}
}


void find(char *filename,char *file ,int a,int confd)
{
		bzero(&buf,sizeof(buf));
		int ff=open("file",O_TRUNC|O_RDWR,0666);
		system("du -a > file");
		lseek(ff,0,SEEK_SET);
		read(ff,file,512);
		printf("a:%s\n",file);
		sprintf(buf.buf,"%s",file);
		printf("%s\n",buf.buf);		
		write(confd,&buf,sizeof(buf));
		bzero(&buf,sizeof(buf));
		close(ff);
}
void make(char *filename,int a)
{
				char k[100]={};
		if(a==0)
		{
			printf("后%s\n",filename);	
			sprintf(k,"touch %s",filename);
			system(k);
		}
		if(a==1)
		{
				sprintf(k,"mkdir %s",filename);
				system(k);
		}
}
int getandput(char *filename ,char *file,int a,int b,int confd,int num)
{
		printf("filename:%s\n",filename);
		printf("%d  %d\n",a,b);
		char temp[1024];
		if(a==3)
		{
				bzero(temp,sizeof(temp));
				getcwd(temp,sizeof(temp));
				printf("temp:%s\n",temp);
				strcat(temp,"/");
				strcat(temp,filename);

				printf("第一次接到;%s\n",temp);
				getdocument(temp,file,confd);
				//传输结束
				buf.file_op.file_type=2;
				write(confd,&buf,sizeof(buf));
				bzero(&buf,sizeof(buf));
				printf("ssssssssss\n");
		}
		if(a==2&&b==0)
		{
				char buff[1024];
				bzero(&buff,sizeof(buff));
				getcwd(buff,1024);
				printf("file_buf:%s\n",buff);
				strcat(buff,filename+num);
				printf("file_num%d\n",num);
				printf("a:%s\n",buff);
				putfile(buff,file);
		}
		if(a==2&&b==1)
		{
				char buff[1024];
				bzero(&buff,sizeof(buff));
				getcwd(buff,1024);
				strcat(buff,filename+num);
				printf("document_buf:%s\n",buff);
				printf("document_num%d\n",num);
				
				putdocument(buff,file,confd);
		}
		if(a==5)
		{
				find(filename,file,b,confd);
		}

		if(a==4)
		{
				printf("中%s\n",filename);
				make(filename,b);
		}
		printf("bbbbbbb\n");
}
