#include "qqclient.h"
struct pAnds
{
		Socks Socks;
		Thread_Data *pHead;
};
extern Thread_Data * pHead_list;
pthread_mutex_t queue_lock;
pthread_t send_chooseid;
pthread_t recv_chooseid;
extern Thread_Data * pHead_send;
extern Thread_Data * pHead_recv;
extern Thread_Data * pHead_file;
jmp_buf jmp_choose;
extern sData_package ThisMy;
extern sem_t s;
//pthread_cond_t queue_ready;
/*
void * create_send(void* pHead)
{
		pthread_t id;
		while(1)
		{
				list_show();
				printf(GRE"输入任意键继续"NONE"\n");
				getchar();
				pthread_create(&id,NULL,Send_choose,(void*)pHead);
		}

}
*/
/////////////////////////////////////////////////////////////////////////////////
//发送函数//////////////////////////////////////////////////////////////////////
void * Send_main(void *pSocks)
{
		struct Socks Socks = *(psock)pSocks;
		Thread_Data * pHead,*pTemp;
		pHead = pHead_send;
//		chain_init(&pHead);
		pthread_t threadid;
//		pthread_mutex_init(&queue_lock,NULL);
//		pthread_cond_init(&queue_ready,NULL);
//		pthread_create(&(threadid),NULL,create_send,(void*)pHead); //创建辅助线程，去创建线程。
		pthread_create(&(send_chooseid),NULL,Send_choose,(void*)pHead); 
//		sData_package packageData;
		while(1)
		{
				pTemp = read_Data(pHead);
				if(pTemp->data.mode == END )
				{
						sleep(1);
						continue;
				}
				else
				{
						printf("处理链表mode:%d\n",pTemp->data.mode);
				printf("发送处理:%s  %d\n",pTemp->data.fileName,pTemp->data.number);

						SendToService(Socks,pTemp->data);
						pTemp->next = pTemp;
						pTemp->prev = pTemp;
						free(pTemp);

				}
		}


}
void * Send_choose(void *pHead)
{
		Thread_Data *pTemp;
		sData_package data;
		char destAddr[20];
		char name[USER_NUMBER];
		while(1)
		{
				sem_wait(&s);
				int mode,ch;
				Thread_Data * (*send_fun[20])(int,char*,char*)=
				{
						send_addfriend,//0
						send_del,      //1
						send_vip,      //2
						send_bal,      //3
						send_file,     //4
						send_tell,     //5
						send_reply,    //6
						send_tells,		//7
						send_hide,
						send_online,
						send_circleSend,
						send_circleLook,
						send_upload,
						send_down,
						send_nearby,				
						send_leave     //15
				};
				list_show();
				sigsetjmp(jmp_choose,1);
				bzero(name,sizeof(name));
				bzero(&data,sizeof(data));
				bzero(destAddr,sizeof(destAddr));
				mode = 0;
				printf("输入字母返回上级菜单_____________________________________                                  \n");
				printf(" 0-------------添加好友|@@@@@@@@ |______________________|                                    \n");
				printf(" 1-------------删除好友|@@    @@ |_____ "GRE"1111111111              "NONE"   \n");
				printf(" 2-------------升级会员|@@    @@ |_____ "GRE"    11                  "NONE"    \n");
				printf(" 3-------------充值余额|@@@@@@@@ |_____ "GRE"    11                  "NONE"	\n");
				printf(" 4-------------发送文件|@@    @@ |_____ "GRE"    11   @@@@           "NONE"	\n");
				printf(" 5-------------发送信息|@@    @@ |_____ "GRE"    11   @aaa A @@@@@   "NONE"	\n");
				printf(" 6-------------叮〇〇〇|@@@@@@@@ |_____ "GRE"    11   @@@@   @ a @   "NONE"	\n");
				printf(" 7-------------万能喇叭(vip专享) |                                            \n");
				printf(" 8-------------  隐 身 | ^_^ ^_^ |							         	\n");
				printf(" 9-------------  上 线 | ^_^ ^_^ |		"RED"	               "NONE"						\n");
				printf("10-------------发朋友圈| ^_^ ^_^ |		"RED"  @@@@    @@@@    "NONE"						\n");
				printf("11-------------看朋友圈| ^_^ ^_^ |		"RED" @    @  @    @   "NONE"					\n");
				printf("12-------------上传网盘| ^_^ ^_^ |		"RED" @    @  @    @   "NONE"					\n");
				printf("13-------------  下 载 | ^_^ ^_^ |		"RED" @   @@  @   @@   "NONE"					\n");
				printf("14-------------附近的人| ^_^ ^_^ |		"RED"  @@@@@@  @@@@@@@ "NONE"					\n");
				printf("ctrl+c---------E X I T | ^_^ ^_^ |								\n");
				printf("y------------- 刷新好友| ^_^ ^_^ |								\n");
				printf("choose:");
				fflush(stdout);
				if((scanf("%d",&mode)== 0) || (mode >16))
				{
						getchar();
						sem_post(&s);
						usleep(1000*100);
						continue;
				}
				getchar();
					
				if(mode < 6 && mode >0)
				{
						printf("i|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_name:");
						fflush(stdout);
						scanf("%s",name);
						getchar();
						data = list_findname(name);
						if(data.mode == END)
						{
								printf(RED"好友列表中无这个好友"NONE"\n");
								printf("因为我健壮\n");
								usleep(1000*100);
								sem_post(&s);

								continue;
						}
				}
				

				pTemp = send_fun[mode](mode,destAddr,name);
				printf("发送链表插入\n");	
				chain_insert((Thread_Data *)pHead,pTemp);
				sem_post(&s);
				usleep(1000*100);
				

		}


}
int SendToService(Socks sockfd,sData_package Data)//发送到服务端
{
		struct sockaddr_in raddr;
		bzero(&raddr,sizeof(struct sockaddr_in));
		signal(SIGALRM,my_send);
		Socks Socks = sockfd;
		sData_package data = Data;
		sigsetjmp(jmp_SendData,1);

		printf("sendToService发送mode:%d \n",data.mode);
		Send_fun(&data,&Socks.addr_send,Socks.sockfd_send);
		alarm(2);
		Recv_fun(&raddr,Socks.send_check);
		signal(SIGALRM,SIG_IGN);
		alarm(0);
		printf("Service back\n");

}

void my_send(int sig)
{
		static int num = 0;
		printf("send_data number:%d重发\n",num);
		num ++;
		if(num == 10)
		{
				printf("链接超时\n");
				exit(-1);
				
		}
		siglongjmp(jmp_SendData,1);
}





/////////////////////////////////////////////////////////////////////
//接受函数//////////////////////////////////////////////////////////
void * Recv_main(void *pSocks)
{
		struct Socks Socks = *(psock )pSocks;
		struct pAnds headAndSock;
		Thread_Data * pHead,*pTemp;
		pHead = pHead_recv;
		headAndSock.pHead = pHead;
		headAndSock.Socks = Socks;
		pthread_create(&(recv_chooseid),NULL,Recv_choose,(void*)&headAndSock); 
		sData_package package,send_package;
		while(1)
		{
				
				chain_init(&pTemp);
				package = Recv_fun(&Socks.addr_recv,Socks.sockfd_recv);//8888
				pTemp->data = package;
		//		send_package.mode = CHECK;
		//		Send_fun(&send_package,&Socks.addr_Rchec,Socks.recv_check);//6563
				if(pTemp->data.fileName[0] == '$')
				{
						printf("文件第一个包\n");
						printf("file:%s\n",pTemp->data.fileName);
						chain_insert(pHead_file,pTemp);

				}
				else
				{
						printf("接受链表插入\n");
						chain_insert(pHead,pTemp);
				}
				

		}
}

void * Recv_choose(void* p_headAndSock)
{
		int (*recv_fun[21])(sData_package,Socks)={
				0,0,Recv_addfriend,Recv_del,0,
				0,Recv_service,0,0,Recv_file,
				Recv_tell,Recv_exit,0,0,0,
				0,0,0,0,Recv_list,Recv_head};

		Socks Sockss = ((struct pAnds *)p_headAndSock)->Socks;
		Thread_Data * pTemp,*pHead;
		pHead = ((struct pAnds *)p_headAndSock)->pHead;
		while(1)
		{
				pTemp = read_Data(pHead);
				if(pTemp->data.mode == END )
				{
						sleep(1);
						//printf("接受链表空了\n");
						continue;
				}

				printf("处理mode%d\n",pTemp->data.mode);
				recv_fun[pTemp->data.mode](pTemp->data,Sockss);	
		}
}


///////////////////////////////////////////////////////////////////////////////////////////
Thread_Data * read_Data(Thread_Data *pHead)              //从链表中读取数据。
{
		Thread_Data * pTemp = pHead->next;
		Thread_Data * pEnd;
		chain_init(&pEnd);
		pEnd->data.mode = END;
		while(pTemp != pHead)
		{
				pTemp->prev->next = pTemp->next;
				pTemp->next->prev = pTemp->prev;
				pTemp->next = pTemp;
				pTemp->prev = pTemp;
				free(pEnd);
				return pTemp;
		}
		return pEnd;
}


int Recv_list(sData_package package,Socks Socks)
{
		Thread_Data *pTemp;
		chain_init(&pTemp);
		pTemp->data = package;
		create_list(pTemp);
		printf("(%sto%s)(%sto%s):\n",package.sourceAddr,package.destAddr,package.src_user,package.dest_user,package.time);

		return 0 ;
}
int chain_insert(Thread_Data *pHead,Thread_Data *pInsert)
{
	//	printf("节点插入\n");
		Thread_Data *pInsert_taill;
		pInsert_taill = pInsert->prev;
		pInsert_taill->next = pHead;
		pInsert->prev = pHead->prev;
		pHead->prev->next = pInsert;
		pHead->prev = pInsert_taill;
		return 0;

}
int chain_init(Thread_Data **p)
{
		*p = (Thread_Data *)malloc(sizeof(Thread_Data));
		(*p)->next = (*p);
		(*p)->prev = (*p);
		(*p)->data.mode = HEAD;
}
void create_list(Thread_Data* pTemp)
{
		pTemp->next = pHead_list;
		pTemp->prev = pHead_list->prev;
		pHead_list->prev->next = pTemp;
		pHead_list->prev = pTemp;
}
void list_show()
{
		int ch = 0;
//		while(1)
//		{
				printf(RED"@@@@@@@@@@@@@@@@@@@@@@@@@@@@ my friend @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"NONE"\n");
				printf(RED"@                          Thismy :%10s                         @"NONE"\n",ThisMy.dest_user);
				Thread_Data *pTemp = pHead_list->next;
				while(pTemp != pHead_list)
				{
						ch =1;
						printf(RED"@Your Friend Name:%10s                              @"NONE"\n",pTemp->data.dest_user);
						pTemp = pTemp->next;
				}
				if(ch ==0)
				printf(RED"@                            空    空                                 @\n");
				printf(RED"@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END____@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"NONE"\n");
//				printf(GRE"是否刷新好友链表"NONE"\n");
//				while( (ch = getchar()) == '\n'|| ch == ' ');
//				ungetc(ch,stdin);
//				usleep(1000*200);
//				if((ch = getchar()) !='y')
//						break;

//		}
		getchar();
}

sData_package list_findname(char *name)
{
		Thread_Data *pTemp = pHead_list->next;
		sData_package data;
		data.mode = END;
		while(pTemp != pHead_list)
		{
				if(strcmp(pTemp->data.dest_user,name) == 0)
						return pTemp->data;
				else
						pTemp = pTemp->next;
		}
		return data;
}
sData_package list_del(char *name)
{
		Thread_Data *pTemp = pHead_list->next;
		sData_package data;
		data.mode = END;
		while(pTemp != pHead_list)
		{
				if(strcmp(pTemp->data.dest_user,name) == 0)
				{
						pTemp->prev->next = pTemp->next;
						pTemp->next->prev = pTemp->prev;
						pTemp->next = NULL;
						pTemp->prev = NULL;
						free(pTemp);
				}
				else
						pTemp = pTemp->next;
		}
		return data;
}
void show_chain(Thread_Data *pHead)
{
				Thread_Data *pTemp = pHead->next;
						printf("showfileName:%s  %d mode:%d\n",pHead->data.fileName,pHead->data.number,pHead->data.mode);
				
				while(pTemp != pHead)
				{
						printf("showfileName:%s  %d mode:%d\n",pTemp->data.fileName,pTemp->data.number,pTemp->data.mode);
						pTemp = pTemp->next;
				}

}

int find_num(char *fileName)
{
				Thread_Data *pTemp = pHead_file->next;
				while(pTemp != pHead_file)
				{
						if(strcmp(pTemp->data.fileName+1,fileName) == 0)
						{
								int num =pTemp->data.number;
								pTemp->prev->next = pTemp->next;
								pTemp->next->prev = pTemp->prev;
								pTemp->next = pTemp;
								pTemp->prev = pTemp;
								free(pTemp);
								return num;
						}
						pTemp = pTemp->next;
				}
				return -1;
		
}
