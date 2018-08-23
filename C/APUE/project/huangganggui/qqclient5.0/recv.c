#include "qqclient.h"
extern Thread_Data * pHead_list;
extern Thread_Data * pHead_reply;
extern sData_package ThisMy;
extern Thread_Data * pHead_recv;
extern sem_t s;
extern Thread_Data * pHead_file;
int Recv_addfriend(sData_package package,Socks Socks)
{
		int ch;
		printf(GRE"%s请求加为好友 备注:（%s）"NONE"\n",package.src_user,
						package.dorinform.data);
		
		sData_package send_friend;
		bzero(&send_friend,sizeof(send_friend));
		send_friend.mode = FRIENDRE;
		sprintf(send_friend.destAddr,"%s",package.sourceAddr);
		sprintf(send_friend.sourceAddr,"%s", package.destAddr);
		sprintf(send_friend.dest_user,"%s", package.src_user);
		sprintf(send_friend.src_user ,"%s",package.dest_user);
		sprintf(send_friend.dorinform.data,"%s",package.dorinform.data);
		sprintf(send_friend.time,"%s",package.time);
//		printf("同意按y\n");
//		while( (ch = getchar()) == '\n'|| ch == ' ');
//		sprintf(package.dorinform.data,"%c",ch);
//		getchar();
		
//		read(0,package.dorinform.data,sizeof(package.dorinform.data));
//		scanf("%s",send_friend.dorinform.data);
//		SendToService(Socks,send_friend);
		
		Thread_Data * pTemp_reply;
		chain_init(&pTemp_reply);	//初始化链表
		pTemp_reply->data = send_friend;
		chain_insert(pHead_reply,pTemp_reply);
		return 0;
}


int Recv_file(sData_package package,Socks Socks)
{
		sem_wait(&s);
		printf("文件处理%s\n",package.fileName);
		Thread_Data * pHead;
		chain_init(&pHead);
		pHead->data.mode = HEAD;
		int fd,ch;
		char *pPoint_end,*pPoint_sta;
		char buf_temp[500];

		bzero(buf_temp,sizeof(buf_temp));
		char path[500],buf_fileName[500];
		bzero(buf_fileName,sizeof(buf_fileName));
		strcpy(buf_fileName,package.fileName);
		bzero(path,sizeof(path));
		
		puts(ThisMy.dest_user);
		sprintf(path,"/USERS/%s/",ThisMy.dest_user);
		printf("path:%s\n",path);
		int ret = chdir(path);
		if(ret == -1)
		{
				perror("chadir");
		}
		getcwd(buf_temp,sizeof(buf_temp));

		printf("%s\n",buf_temp);
		dir_init("DOWNFILE");
		pPoint_sta = buf_fileName;
		while((pPoint_end = strchr(pPoint_sta,'/')) != NULL)
		{
				*pPoint_end = '\0';
				dir_init(pPoint_sta);
				pPoint_sta = pPoint_end+1;
		}
		do	
		printf(RED"%s(TIME:%s):file down%s同意按Y____________________________________________________________________________--\n"NONE"\n",package.src_user,package.time,package.fileName);

//		ch =getchar();
		while( (ch = getchar()) !='n' && ch != 'y');
		if(ch == 'y')
		{
				getchar();
				int num = find_num(package.fileName);
				printf("正在下载\n");
				fd = open(pPoint_sta,O_WRONLY|O_APPEND|O_CREAT|O_EXCL,0666);
				if(fd == -1)
				{
						if(errno == EEXIST)
						{
								do
								printf("文件已经存在是否覆盖\n");
								while( (ch = getchar()) !='n' && ch != 'y');
								if(ch == 'n')
								{
										perror(pPoint_sta);
										chdir(path);
										sem_post(&s);
										free_fileName(package.fileName,pHead);
										return -1;
								}
						}
						else
						{
										perror(pPoint_sta);
										chdir(path);
										sem_post(&s);
										free_fileName(package.fileName,pHead);
										return -1;
						}
				}
				sem_post(&s);
				write(fd,package.dorinform.data,strlen(package.dorinform.data));
				while(1)
				{
						Thread_Data * pTemp;
						pTemp = read_Data(pHead_recv);
						if((strcmp(pTemp->data.fileName,package.fileName)) == 0)
						{
							printf("file:%s  (%d/%d) 正在下载\n",pTemp->data.fileName,pTemp->data.number,num);
							write(fd,pTemp->data.dorinform.data,strlen(package.dorinform.data));
							free(pTemp);
						
						}
						else
						{
								if(pTemp->data.mode == END)
										break;
							printf("file:%s  num%d 重新插入\n",pTemp->data.fileName,pTemp->data.number);
								chain_insert(pHead,pTemp);
						}
				}
				chain_insert(pHead_recv,pHead);
				close(fd);
		}
		else
		{
				sem_post(&s);
				free_fileName(package.fileName,pHead);
		}
		chdir(path);
		getchar();
		return 0;
}
int free_fileName(char *fileName,Thread_Data *pHead)
{
				while(1)
				{
						Thread_Data * pTemp;
						pTemp = read_Data(pHead_recv);
						if((strcmp(pTemp->data.fileName,fileName)) == 0)
						{
								free(pTemp);
						}
						else
						{
								printf("file:%s  num%d 重新插入\n",pTemp->data.fileName,pTemp->data.number);
								if(pTemp->data.mode == END)
										break;
								chain_insert(pHead,pTemp);
						}
				}
				chain_insert(pHead_recv,pHead);

}
int Recv_tell(sData_package package,Socks Socks)
{
	
		printf(GRE"%s:(%s) :::%s"NONE"\n",package.src_user,package.time,package.dorinform.data);
		return 0;
}

int Recv_service(sData_package package,Socks Socks)
{
		printf(RED"service:(%s):%s"NONE"\n",package.time,package.dorinform.data);
		
}
int Recv_del(sData_package package,Socks Socks)
{
		list_del(package.src_user);
}
int Recv_exit(sData_package package,Socks Socks)
{
		if(strlen(package.fileName) != 0)
		printf("file:%s结束\n",package.fileName);

}
int Recv_head(sData_package package,Socks Socks)
{
		printf("PHEAD\n");

}

