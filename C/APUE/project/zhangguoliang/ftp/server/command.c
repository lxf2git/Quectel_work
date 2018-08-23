#include "apue.h"
#define OP_PERM 0777
#define S_TIME 500

void my_ls( struct recv_to_deal comd)
{
	int pde[2];
    set_err(pipe(pde),"pipe");
	bzero(buf,sizeof(buf));
	
		if(ZERO==fork())
		{
			bzero(buf,sizeof(buf));
			strcpy(buf,"ls ");
			strcat(buf,comd.to_ser.ftp_ls_path);
			dup2(pde[1],STDOUT_FILENO);
			system(buf);
			bzero(buf,sizeof(buf));
			exit(EMPTY);
		}
	read(pde[0],buf,sizeof(buf));
	sendto(sockfd,buf,strlen(buf)+1,0,(struct sockaddr*)&conaddr,sizeof(conaddr));
}

void my_cd(struct recv_to_deal comd)
{
	chdir(comd.to_ser.ftp_cd_path);
}

void my_pwd(struct recv_to_deal comd)
{
	bzero(buf,sizeof(buf));
	getcwd(buf,sizeof(buf));
	sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&conaddr,sizeof(conaddr));
}

void my_mkdir(struct recv_to_deal comd)
{
	bzero(buf,sizeof(buf));
	strcpy(buf,"mkdir ");
	strcat(buf,comd.to_ser.ftp_mkdir_path);
	system(buf);
}


void my_get(struct recv_to_deal comd)
{
	
	int fd = open(comd.to_ser.ftp_get_file,O_RDONLY);
	printf("start_read\n");
	while(read(fd,buf,sizeof(buf))>0)
	{
		sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&conaddr,sizeof(conaddr));
		bzero(buf,sizeof(buf));
	}
	close(fd);
}

void my_put(struct recv_to_deal comd)
{
	int fd = open(comd.to_ser.ftp_put_file,O_CREAT|O_WRONLY,OP_PERM);
	bzero(comd.to_ser.ftp_put_file,sizeof(comd.to_ser.ftp_put_file));
	usleep(S_TIME);
		bzero(buf,sizeof(buf));
		read(sockfd,buf,sizeof(buf));
		write(fd,buf,strlen(buf));

	close(fd);
	sem.sem_op=+1;
	semop(semid,&sem,1);
}

void my_quit()
{
	exit(EMPTY);
}

void err()
{
	sendto(sockfd,"input error",12,0,(struct sockaddr*)&conaddr,sizeof(conaddr));
}
