#include"apue.h"
int choose_command(char *buf,char *buffile,int confd)
{
		char *buff[7]={"ls","put","get","cd","pwd","mkdir","quit"};
		char ll[10]={'\0'};
		int fd =open("file",O_CREAT|O_RDWR|0666);
		if(strcmp(buff[0],strncpy(ll,buf,2))==0)
		{
				sG_p buf1;
				bzero(&buf1,sizeof(buf1));
				char temp[1024]={'\0'};
				sprintf(temp,"ls -l %s > file",buf+3);
				system(temp);
				read(fd,buf1.file_buf,1024);
			//	puts(buf1.file_buf);
			
				write(confd,&buf1,sizeof(buf1));
		}

		if(strncmp(buff[1],strncpy(ll,buf,3),3)==0)
		{
				printf("ssssssssss\n");
				sG_p buf1;
				bzero(&buf1,sizeof(buf1));
				int ff=open(&buf[4],O_CREAT|O_RDWR|0666);
				printf("buf4:%s\n",&buf[4]);
				write(ff,buffile,1024);
				close(ff);
				strcpy(buf1.file_buf,"put_success");
				write(confd,&buf1,sizeof(buf1));
		}

		if(strncmp(buff[2],strncpy(ll,buf,3),3)==0)
		{

				int ff=open(buf+4,O_RDONLY);
				sG_p buf1;
				bzero(&buf1,sizeof(buf1));
				if(ff<0)
				{
						strcpy(buf1.file_buf,"nofind_file");
						write(confd,&buf1,sizeof(buf1));
						close(ff);
				}
				else
				{
					strcpy(buf1.file_name,buf+4);	
					read(ff,buf1.file_buf,1024);
					puts(buf1.file_buf);
					write(confd,&buf1,sizeof(buf1));
					close(ff);
				}
		}
		if(strncmp(buff[3],strncpy(ll,buf,2),2)==0)		
		{
				sG_p buf1;
				bzero(&buf1,sizeof(buf1));
				chdir(buf+3);
				printf("%s\n",buf+3);
				strcpy(buf1.file_buf,"cd_success");
				write(confd,&buf1,sizeof(buf1));
		}
		if(strncmp(buff[4],strncpy(ll,buf,3),3)==0)
		{
				sG_p buf1;
				bzero(&buf1,sizeof(buf1));
				char temp[1024]={'\0'};
				sprintf(temp,"%s > file",buf);
				system(temp);
				read(fd,buf1.file_buf,1024);
				write(confd,&buf1,sizeof(buf1));
		}

		if(strncmp(buff[5],strncpy(ll,buf,5),5)==0)
		{
				sG_p buf1;
				bzero(&buf1,sizeof(buf1));
				char temp[1024]={'\0'};
				system(buf);		
				strcpy(buf1.file_buf,"mkdir_success");
				write(confd,&buf1,sizeof(buf1));
		}
		if(strncmp(buff[6],strncpy(ll,buf,4),4)==0)
		{
				return 1;
		}
		close(fd);
		system("rm -f file");
}
