#include "service.h"
void * show(void*p)
{
		while(1)
		{
				sleep(1);
				int ch = getchar();
				printf(WIT"显示登录链表"NONE"\n");
				show_chain((pGoin)p);
		}
}
int deal_pess(int *fdPipe)
{
		printf(GREED"deal_pass"NONE"\n");
		sData bufData;
		pGoin pHead,pTemp;
		init_chain(&pHead);
		close(fdPipe[1]);
		pthread_t id;
		pthread_create(&id,NULL,show,(void *)pHead);
		while(1)
		{
				bzero(&bufData,sizeof(bufData));
				int ret = read(fdPipe[0],&bufData,sizeof(bufData));      //从管道读出 结构体
				init_chain(&pTemp);
				strcpy(pTemp->user,bufData.uoc.user);
				strcpy(pTemp->addr,bufData.addr);

				int semid = semget(0x8888,1,IPC_CREAT|0666);
				if(semid == -1)
				{
						perror("semget");
						exit(-1);
				}
				semctl(semid,0,SETVAL,0);
				struct sembuf buf;
				buf.sem_op = 0;
				buf.sem_num = 0;


				if(bufData.mode == 0)
				{
						printf(GREED"deal mode =0 "NONE"\n");
						ret = search(pHead,pTemp);
						printf(GREED"deal 插入检索"NONE"\n");
						if(ret == 0)
						{
								printf(GREED"deal 链表插入"NONE"\n");
								insert(pHead,pTemp);
						}
						else
						{
								printf("user error\n");
								int cockfd = socket(AF_INET,SOCK_STREAM,0);
								struct sockaddr_in caddr;
								bzero(&caddr,sizeof(caddr));
								caddr.sin_family = AF_INET;
								caddr.sin_port = htons(8888);
								caddr.sin_addr.s_addr = inet_addr(bufData.addr);
								if(connect(cockfd,(struct sockaddr*)&caddr,sizeof(caddr)) < 0)
								{
										perror("8888 conect");
										return -1;
								}
								printf(PRO"client 链接客户8888"NONE"\n");
								send_data(cockfd,2);
								close(cockfd);

								continue;
						}

						mkfifo(bufData.addr,0666);
						printf(GREED"deal 子管道创建"NONE"\n");
						if(fork() == 0)
						{
								client_pess(bufData.addr,semid,buf);
						}

				}
					
				int fd = open(bufData.addr,O_RDWR);
				if(fd < 0)
				{
						perror("open  deal_pess");
						continue;
				}
				write(fd,&bufData,sizeof(bufData));
				printf(GREED"deal 写入子管道"NONE"\n");
				if((bufData.mode == 0) | (my_strcmp(bufData.uoc.cmd) == 1) )
				{
						buf.sem_op = -1;
						semop(semid,&buf,1);
					
						sData bufPasswd;
						bzero(&bufPasswd,sizeof(bufPasswd));
						read(fd,&bufPasswd,sizeof(bufPasswd));
						printf(GREED"deal 读出子管道"NONE"\n");

						if(bufPasswd.uoc.cmd[0] != '0')
						{
								printf(RED"deal 执行行删除"NONE"\n");
								delete(pHead,bufData.addr);
								close(fd);
								unlink(bufData.addr);
						}
						else
						{
								printf(GREED"deal passwd OK"NONE"\n");
								continue;
						}
				}
				else
						close(fd);


		}
}
int init_chain(pGoin *p)
{
		*p = malloc(sizeof(struct Goin));
		(*p)->next = (*p);
		(*p)->prev = (*p);

}
int show_chain(pGoin pHead)
{
		pGoin pTemp = pHead->next;
		while(pTemp !=pHead)
		{
				printf(WIT"addr:%s user:%s"NONE"\n",pTemp->addr,pTemp->user);
				pTemp = pTemp->next;

		}
		printf(WIT"链表结束"NONE"\n");
		return 0;

}
int search(pGoin pHead,pGoin pSear)
{
		pGoin pTemp = pHead->next;
		while(pTemp !=pHead)
		{
				if(strcmp(pTemp->user,pSear->user) ==0 )
				{
						return -1;
				}
				pTemp = pTemp->next;
		}
		return 0;
}
int insert(pGoin pHead,pGoin pInsert)
{
		pInsert->next = pHead;
		pInsert->prev = pHead->prev;
		pHead->prev->next = pInsert;
		pHead->prev = pInsert;

}
int delete(pGoin pHead ,char *addr)
{
		printf(RED"要删除用户IP%s"NONE"\n",addr);
		pGoin pTemp = pHead->next;
		while(pTemp != pHead)
		{
				if(strcmp(pTemp->addr,addr) ==0 )
				{
						printf(RED"找到链表并删除"NONE"\n");
						pTemp->next->prev = pTemp->prev;
						pTemp->prev->next = pTemp->next;
						free(pTemp);
						return 0;
				}
				pTemp = pTemp->next;
		}
		return -1;

}
