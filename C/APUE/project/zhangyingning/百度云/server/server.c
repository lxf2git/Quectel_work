#include"apue.h"

pthread_mutex_t m;
pthread_cond_t c;
int confd;
int j = 0;
sBdy buff[10];

int main()
{	
		struct sockaddr_in selfaddr,conaddr;	
		int ret,i;
		socklen_t len = sizeof(conaddr);
		int sockfd = socket(AF_INET,SOCK_STREAM,0);	
		if(sockfd<0)
		{
				perror("socket");
		}

		bzero(&selfaddr,sizeof(selfaddr));
		selfaddr.sin_family = AF_INET;
		selfaddr.sin_addr.s_addr =htonl(INADDR_ANY); 
		selfaddr.sin_port = htons(8888);
		ret = bind(sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
		if(ret<0)
		{
				close(sockfd);
				perror("bind");
		}

		listen(sockfd,10);
		bzero(&conaddr,sizeof(conaddr));
		sBdy buf;
		bzero(&buf,sizeof(buf));
		pF phead=NULL;
		init_node(&phead);

		//建立线程池
		pthread_mutex_init(&m,NULL);
		pthread_cond_init(&c,NULL);
		pthread_t tid[10];
		for(i=0;i<10;i++)
		{
			pthread_create(&tid[i],NULL,thread1,NULL);
		}
		char user_file[1024];
		while(1)
		{	
				//反复等待客户连接	
				confd = accept(sockfd,(struct sockaddr*)&conaddr,&len);
				char temp[1024];
				if(confd<0)
				{
					continue;
				}
				while(1)
				{
					if((read(confd,&buf,sizeof(buf)))<0)
					{
						break;	
					}
					int n = login_infor(phead,buf.usrname,buf.passwd,buf.cmd);				
					if(n==0)//注册成功
					{								
						
						bzero(&user_file,sizeof(user_file));
						sprintf(user_file,"mkdir %s",buf.usrname);
						printf("siyou :%s\n",user_file);
						system(user_file);
						
						bzero(&buf,sizeof(buf));
						strcpy(buf.buf,"register_success");
						write(confd,&buf,sizeof(buf));
						usleep(50000);
						continue;
					}
					if(n==1) //登录成功
					{
						bzero(temp,sizeof(temp));	
						strcpy(temp,buf.usrname);	
						bzero(&buf,sizeof(buf));
						strcpy(buf.buf,"login_success");
						write(confd,&buf,sizeof(buf));
						break;
					}
					if(n==2)//失败
					{
						bzero(&buf,sizeof(buf));
						strcpy(buf.buf,"fail");
						write(confd,&buf,sizeof(buf));
						usleep(50000);
						continue;
					}				
				}
				j++;
				if(j==9)
				{
					j = 0;
				}
				printf("注册中:%d\n",confd);
				while(1)
				{
					//线程激活条件
					if((read(confd,&buff[j],sizeof(buff[j]))) > 0)
					{	
						strcpy(buff[j].usrname,temp);
						printf("写之qian:%s\n",buff[j].file_op.file_name);
					
						pthread_cond_signal(&c);
						printf("写之后:%s\n",buff[j].file_op.file_name);
					}
					break;
				}

		}
}

void *thread1(void *p)
{
		pthread_mutex_lock(&m); //上锁
		pthread_cond_wait(&c,&m);//信号激活
		int confd2 = confd;
		char buf[1024];	
		bzero(&buf,sizeof(buf));
		getcwd(buf,sizeof(buf));
		//sprintf(buf,"/%s",buff[j].usrname);
		strcat(buf,"/");
		strcat(buf,buff[j].usrname);
		chdir(buf);
		printf("线程中:%d\n",confd2);
		printf("buf:%s\n",buf);
		while(1)
		{
			getandput(buff[j].file_op.file_name,buff[j].buf,buff[j].cmd,buff[j].file_op.file_type,confd2,buff[j].num);
			bzero(&buff[j],sizeof(buff[j]));
			chdir(buf);
			printf("ccccccc\n");
	
			if((read(confd2,&buff[j],sizeof(buff[j])))<=0)
			{
				printf("ddddddddd\n");	
				break;
			}
		}
		pthread_mutex_unlock(&m); //解锁
		bzero(&buff[j],sizeof(buff[j]));
}
