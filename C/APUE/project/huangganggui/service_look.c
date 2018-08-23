#include "apue.h"
int recv_friendCircle_look(sData_package data,sSocks socket_structure,pOnlineUser pHeadOnline)
{
		//char *name;
		//name = malloc(10);
		char buf[30];
		bzero(&(data.dorinform.data),sizeof(data.dorinform.data));
		int fd,ret;
		int fd_n,fd_f;
		sprintf(buf,"./%s/friendCircle",data.src_user);
		fd = open(buf,O_RDONLY);		
		if(fd < 0){
				perror("open");
				return -1;
		}
		
		ret = read(fd,data.dorinform.data,sizeof(data.dorinform.data));
		if(ret < 0){
				perror("read");
				return -1;
		}
		strcpy(data.dest_user,data.src_user);
		data.mode = FRIENDCIRCLE_LOOK;
		ret = sendto(socket_structure.sockfd_send,&data,sizeof(data),0,(struct sockaddr*)&(socket_structure.paddr_send), socket_structure.len);
		if(ret < 0){
				perror("sendto");
				return -1;
		}
		close(fd);
		bzero(&buf,sizeof(buf));
		sprintf(buf,"./%s/friendList",data.src_user);
		fd_n = open(buf,O_RDONLY);
		if(fd < 0){
				perror("open_n");
				close(fd_n);
				return -1;
		}

		while(1){
				bzero(&(data.dest_user),sizeof(data.dest_user));
				ret = read(fd_n,data.dest_user,sizeof(data.dest_user));
				if(ret < 0){
						close(fd_n);
						return -1;
				}

				bzero(&buf,sizeof(buf));
				sprintf(buf,"./%s/friendCircle",data.dest_user);
				fd_f = open(buf,O_RDONLY);
				if(fd_f < 0){
						perror("open_f");
						return -1;
				}

				bzero(&(data.dorinform.data),sizeof(data.dorinform.data));
				ret = read(fd_f,data.dorinform.data,sizeof(data.dorinform.data));
				if(ret < 0){
						close(fd_f);
						return -1;
				}else{
						data.mode = FRIENDCIRCLE_LOOK;
						ret = sendto(socket_structure.sockfd_send,&data,sizeof(data),0,(struct sockaddr*)&(socket_structure.paddr_send), socket_structure.len);
						close(fd_f);
						return -1;
				}
		}

}
