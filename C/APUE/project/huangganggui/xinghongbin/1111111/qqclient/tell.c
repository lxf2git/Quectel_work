#include "qqclient.h"
struct pAnds
{
		Socks Socks;
		Thread_Data *pHead;
};
extern Thread_Data * pHead_list;
pthread_mutex_t queue_lock;
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
void * Send_choose(void *pHead)
{
		Thread_Data *pTemp;
		char destAddr[20];
		while(1)
		{
				list_show();
				bzero(destAddr,sizeof(destAddr));
				printf("输入目的ip\n");
				scanf("%s",destAddr);
				getchar();
				int mode;
				printf("2 添加好友\n3 文件请求\n4 谈话请求\n");
				scanf("%d",&mode);
				Thread_Data * (*tell_fun[5])(int,char*)={0,0,tell_addfriend,tell_file,tell_tell};

				pTemp = tell_fun[mode](mode,destAddr);	
			//	pthread_mutex_lock (&queue_lock);
				chain_insert((Thread_Data *)pHead,pTemp);
			//	pthread_mutex_unlock (&queue_lock);
		}


}
int Send_main(Socks Socks)
{
		Thread_Data * pHead,*pTemp;
		chain_init(&pHead);
		pthread_t threadid;
//		pthread_mutex_init(&queue_lock,NULL);
//		pthread_cond_init(&queue_ready,NULL);
		
//		pthread_create(&(threadid),NULL,create_send,(void*)pHead); //创建辅助线程，去创建线程。
		pthread_create(&(threadid),NULL,Send_choose,(void*)pHead); 
//		sData_package packageData;
		while(1)
		{
				pTemp = read_Data(pHead);
				if(pTemp->data.mode == END )
				{
						sleep(1);
						continue;
				}
				pthread_detach(threadid);   

				SendToService(Socks,pTemp->data);
//				pthread_detach(pTemp->id);
				free(pTemp);
		}


}
Thread_Data * read_Data(Thread_Data *pHead)              //从链表中读取数据。
{
		Thread_Data * pTemp = pHead->next;
		Thread_Data * pEnd;
		chain_init(&pEnd);
		pEnd->data.mode = END;
		while(pTemp != pHead)
		{
				pTemp->next = pHead->next;
				pTemp->next->prev = pHead;
				free(pEnd);
				return pTemp;
		}
		return pEnd;
}
int SendToService(Socks Socks,sData_package data)//发送到服务端
{
		signal(SIGALRM,myalarm);
		Send_fun(&data,&Socks.addr_send,Socks.sockfd_send);
		alarm(1);
		Recv_fun(&Socks.addr_recv,Socks.sockfd_recv);
		signal(SIGALRM,SIG_IGN);

}
int Recv_main(Socks Socks)
{
		struct pAnds *p_headAndSock;
		Thread_Data * pHead,*pTemp;
		chain_init(&pHead);
		pthread_t threadid;
		p_headAndSock->pHead = pHead;
		pthread_create(&(threadid),NULL,Recv_choose,(void*)&p_headAndSock); 
		sData_package package,send_package;
		while(1)
		{
				
				chain_init(&pTemp);
				package = Recv_fun(&Socks.addr_recv,Socks.sockfd_recv);
				pTemp->data = package;
				send_package.mode = CHECK;
				Send_fun(&send_package,&Socks.addr_Rchec,Socks.recv_check);
				chain_insert(pHead,pTemp);
				

		}
}

void * Recv_choose(void* p_headAndSock)
{

		Socks Sockss = ((struct pAnds *)p_headAndSock)->Socks;
		Thread_Data * pTemp,*pHead;
		pHead = ((struct pAnds *)p_headAndSock)->pHead;
		pTemp = read_Data(pHead);
		sData_package package;
		package = pTemp->data;
		
		int (*recv_fun[5])(sData_package,Socks)={0,0,Recv_addfriend,Recv_file,Recv_tell};

		recv_fun[package.mode](pTemp->data,Sockss);	
}



int Recv_list(sData_package package)
{
		Thread_Data *pTemp;
		chain_init(&pTemp);
		pTemp->data = package;
		create_list(pTemp);
		printf("(%s):(%s):%s\n",package.sourceAddr,package.time,package.dorinform.data);

		return 0 ;
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
		Thread_Data *pTemp = pHead_list->next;
		while(pTemp != pHead_list)
		{
				printf("%s",pTemp->data.destAddr);
				pTemp = pTemp->next;
		}
}
