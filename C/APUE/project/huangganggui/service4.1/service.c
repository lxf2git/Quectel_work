#include "function.h"

/*
enum
{
        LOGIN,          //登入       0
        REGISTER,       //注册       1
        ADDFRIEND,      //添加好友    2
        DELFRIEND,      //删除好友    3
        ADDVIP,         //VIP       4
        ADDBALANCD,     //充值       5
        SERVICE_REPLY,  //服务器答复  6
        TELLS_INVITE,   //群聊邀请   7
        TELLS_REPLY,    //群聊答复   8
        FILE_REQUES,    //文件请求   9
        TELL_REQUES,    //谈话请求   10
        REQUES_EXIT,    //请求结束   11
        LOGINERROR,     //登录失败   12
        LOGINSUCCEED,   //登录成功   13
        REGISTERERROR,  //注册失败   14
        REGISTERSUCCEED,//注册成功   15
        LEAVE,          //下线通知   16
        CHECK,          //检测      17 
        FRIENDRE,       //好友回应   18
        FRIENDLIST,     //好友链表   19
        END             //最后一个
};
*/



int main()
{
  /*
   *    xiaogang ->文件系统
   * */      
        int mkdirret;

        mkdirret = mkdir(".info", 0777);
        if (mkdirret < 0)
        {
            if (EEXIST != errno)
            {
                perror("mkdir");
                exit(-1);
            }
        }

        chdir(".info");  //切换工作目录至 .inif下

        system("touch onlineuser");




		sSocks Sockfd;
		init_sockfd(&Sockfd);

		int fdPipe[2];
		int ret = pipe(fdPipe);
		if(ret == -1){
				perror("pipe_fdPipe");
				return -1;
		}

		int semid = semget(0x8888,1,IPC_CREAT|0666);
		if(semid == -1){
				perror("semget");
				exit(-1);
		}
		semctl(semid,0,SETVAL,0);
		struct sembuf buf;
		buf.sem_op = 0;
		buf.sem_num = 0;

		if(fork() != 0){
				usleep(100*1000);
				create_sockfd(fdPipe,Sockfd,buf,semid);
		}else
				deal_pess(fdPipe,buf,semid);
		return 0;
}

int create_sockfd(int *fdPipe,sSocks Sockfd,struct sembuf buf,int semid)
{
		sData_package bufData;
		sData_package buffData;
		bzero(&bufData,sizeof(bufData));
		bzero(&buffData,sizeof(buffData));
		Sockfd.len = sizeof(struct sockaddr_in);
	//	socklen_t len = sizeof(struct sockaddr_in);
		while(1){
				int ret=recvfrom(Sockfd.sockfd_recv,&bufData,sizeof(bufData),0,(struct sockaddr *)&(Sockfd.paddr_recv_n),&(Sockfd.len));
			//	int ret=recvfrom(Sockfd.sockfd_recv,&bufData,sizeof(bufData),0,(struct sockaddr *)&(Sockfd.paddr_recv_n),&len);
				strcpy(bufData.sourceAddr,inet_ntoa(Sockfd.paddr_recv_n.sin_addr));
				Sockfd.paddr_rech.sin_addr.s_addr = inet_addr(bufData.sourceAddr);


//      xiaogang
                printf("回复校验\n");
                sData_package checkData;
                bzero(&checkData,sizeof(checkData));
			    
                checkData.mode = CHECK;

                printf("端口号:%d\n",ntohs(Sockfd.paddr_rech.sin_port));
                printf("IP");

                puts(inet_ntoa(Sockfd.paddr_rech.sin_addr));
                sendto(Sockfd.sockfd_rech,&checkData,sizeof(checkData),0,(struct sockaddr*)&Sockfd.paddr_rech,Sockfd.len);
				printf("发送完毕\n");


//      xiaogang end
        		if(ret < 0){
						perror("recvfrom");
						exit(-1);
				}


				if(bufData.mode == FILE_REQUES ||bufData.mode == TELL_REQUES || bufData.mode == ADDFRIEND ){
						Sockfd.paddr_send.sin_addr.s_addr = inet_addr(bufData.destAddr);
                        printf("信息的目的IP:%s\n", bufData.destAddr);
                }else{//回发信息
                
						Sockfd.paddr_send.sin_addr.s_addr = inet_addr(bufData.sourceAddr);
                        printf("信息的目的IP:%s\n", bufData.sourceAddr);
                
                }


				
				close(fdPipe[0]);
				write(fdPipe[1],&bufData,sizeof(bufData));

				buf.sem_op = -1;
				semop(semid,&buf,1);

				close(fdPipe[0]);

                printf("fifo write: paddr_send.sin_addr:%s\n",inet_ntoa(Sockfd.paddr_send.sin_addr));
				write(fdPipe[1],&Sockfd,sizeof(Sockfd));
		}

		return 0;

}


int init_sockfd(sSocks *Sockfd)
{
		Sockfd->sockfd_send = socket(AF_INET,SOCK_DGRAM,0);
		Sockfd->sockfd_recv = socket(AF_INET,SOCK_DGRAM,0);
		Sockfd->sockfd_chec = socket(AF_INET,SOCK_DGRAM,0);
		Sockfd->sockfd_rech = socket(AF_INET,SOCK_DGRAM,0);
		bzero(&(Sockfd->paddr_send_n),sizeof(Sockfd->paddr_send_n));//port 8888
		bzero(&(Sockfd->paddr_recv_n),sizeof(Sockfd->paddr_recv_n));//port 7653
		bzero(&(Sockfd->paddr_chec_n),sizeof(Sockfd->paddr_chec_n));//port 6563
		bzero(&(Sockfd->paddr_rech_n),sizeof(Sockfd->paddr_rech_n));//port 7777
		if(Sockfd->sockfd_send < 0 ||Sockfd->sockfd_recv < 0 ||Sockfd->sockfd_chec < 0 ||Sockfd->sockfd_rech < 0)
		{
				perror("socket_init_sockfd");
				exit(-1);
		}

		bzero(&(Sockfd->paddr_send),sizeof(Sockfd->paddr_send));//port 8888
		Sockfd->paddr_send.sin_family = AF_INET;
		Sockfd->paddr_send.sin_port = htons(8888);

		bzero(&(Sockfd->paddr_recv),sizeof(Sockfd->paddr_recv));//port 7563
		Sockfd->paddr_recv.sin_family = AF_INET;
		Sockfd->paddr_recv.sin_port = htons(7563);

		bzero(&(Sockfd->paddr_chec),sizeof(Sockfd->paddr_chec));//port 6563
		Sockfd->paddr_chec.sin_family = AF_INET;
		Sockfd->paddr_chec.sin_port = htons(6563);

		bzero(&(Sockfd->paddr_rech),sizeof(Sockfd->paddr_rech));//port 7777
		Sockfd->paddr_rech.sin_family = AF_INET;
		Sockfd->paddr_rech.sin_port = htons(7777);

		Sockfd->paddr_recv.sin_addr.s_addr = htonl(INADDR_ANY);//port 7563
		int ret = bind(Sockfd->sockfd_recv,(struct sockaddr *)&(Sockfd->paddr_recv),sizeof(Sockfd->paddr_recv));
		if(ret < 0){
				perror("bind_recv");
				return -1;
		}

		Sockfd->paddr_chec.sin_addr.s_addr = htonl(INADDR_ANY);//prot 6563
		ret = bind(Sockfd->sockfd_chec,(struct sockaddr *)&(Sockfd->paddr_chec),sizeof(Sockfd->paddr_chec));
		if(ret < 0){
				perror("bind_chec");
				return -1;
		}

}
