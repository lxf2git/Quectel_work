#include "qqclient.h"
//extern char myuser[20];
extern sData_package ThisMy;
Thread_Data * pHead_reply;
Thread_Data * send_addfriend(int mode,char* destAddr,char* dest_user)
{
				my_jmpMenu(2);
 		Sendinit[ADDFRIEND] = init_addfriend;

		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage = Sendinit[ADDFRIEND](NULL,destAddr);
		printf("添加备注\n");
		read(0,dataPackage.dorinform.data,sizeof(dataPackage.dorinform.data));
//		scanf("%s",dataPackage.dorinform.data);
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;
		
}
Thread_Data * send_reply(int mode,char* destAddr,char* dest_user)
{
		my_jmpMenu(2);

		Thread_Data * pTemp = pHead_reply->next;
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		dataPackage.mode = END;

		if(pTemp != pHead_reply)
		{
				if(pTemp->data.mode == FRIENDRE)
				{
						printf(GRE"%s(TIME:%s)请求加为好友 备注:（%s）"NONE"\n",pTemp->data.dest_user,pTemp->data.time,
										pTemp->data.dorinform.data);
						printf("同意按y\n");
						read(0,pTemp->data.dorinform.data,sizeof(pTemp->data.dorinform.data));
				}
				pTemp->next->prev = pTemp->prev;
				pTemp->prev->next = pTemp->next;
				pTemp->next = pTemp;
				pTemp->prev = pTemp;
				return  pTemp; 

		}
		chain_init(&pTemp);
		pTemp->data = dataPackage;
		return  pTemp; 

}

Thread_Data * send_file(int mode,char* destAddr,char *dest_user)
{
		my_jmpMenu(2);
		Sendinit[FILE_REQUES] = init_file;
		Thread_Data *pTemp,*pHead_file,*pTemp_file;
		chain_init(&pTemp);
		chain_init(&pHead_file);
		Thread_Data *pFile ,*pFile_sta;
		chain_init(&pFile_sta);
		int ret ;
		char buf_file[200];
		sData_package dataPackage;
		char path[200];
		char fileName[200];
		char buf_name[500];
		bzero(path,sizeof(path));
		bzero(fileName,sizeof(fileName));
		bzero(buf_name,sizeof(buf_name));
		printf("put your path(末尾加/):");
		fflush(stdout);
		scanf("%s",path);
		getchar();
		printf("put your fileName:");
		fflush(stdout);
		scanf("%s",fileName);
		getchar();
		chdir(path);
		ret = create_file_chain(pHead_file,fileName);
		chdir("-");
		
		if(ret == -1)
		{
				printf("ret == -1\n");
				dataPackage.mode = HEAD;
				pFile_sta->data = dataPackage;
				return pFile_sta;

		}
//		show_chain(pHead_file);
		int num_sta = 0;
		bzero(buf_file,sizeof(buf_file));
		bzero(&dataPackage,sizeof(dataPackage));
		dataPackage = Sendinit[FILE_REQUES](buf_file,destAddr);
		sprintf(dataPackage.fileName,"$%s",fileName);
		sprintf(dataPackage.dest_user,"%s",dest_user);
		sprintf(dataPackage.destAddr,"%s",destAddr);
		pFile_sta->data = dataPackage;
		pFile_sta->id = pthread_self();
		while(1)
		{
				chain_init(&pFile);
				int num = 0;
				pTemp_file = read_Data(pHead_file);
				if(pTemp_file->data.mode ==END)
						break;
		//	printf("发送初始化文件处理中%s\n",pTemp_file->data.fileName);
				sprintf(buf_name,"%s%s",path,pTemp_file->data.fileName);
				int fd = open(buf_name,O_RDONLY);
				if(fd == -1)
				{
						dataPackage.mode = END;
						pFile->data = dataPackage;
						perror(buf_name);
						return pFile;
				}
				bzero(buf_file,sizeof(buf_file));
				bzero(&dataPackage,sizeof(dataPackage));
				dataPackage = Sendinit[FILE_REQUES](buf_file,destAddr);
				sprintf(dataPackage.fileName,"$%s",pTemp_file->data.fileName);
				sprintf(dataPackage.dest_user,"%s",dest_user);
				sprintf(dataPackage.destAddr,"%s",destAddr);
				pFile->data = dataPackage;
				pFile->id = pthread_self();
				while(1)
				{
						chain_init(&pTemp);
						bzero(buf_file,sizeof(buf_file));
						bzero(&dataPackage,sizeof(dataPackage));
						ret = read(fd,buf_file,sizeof(buf_file)-1);
						if(ret == 0)
						{
								break;
						}
						dataPackage = Sendinit[FILE_REQUES](buf_file,destAddr);
						sprintf(dataPackage.fileName,"%s",pTemp_file->data.fileName);
						sprintf(dataPackage.dest_user,"%s",dest_user);
						sprintf(dataPackage.destAddr,"%s",destAddr);
						pTemp->data = dataPackage;
						pTemp->id = pthread_self();
						pTemp->data.number = num;
						chain_insert(pFile,pTemp);
						num++;

				}
				chain_init(&pTemp);
				bzero(&dataPackage,sizeof(dataPackage));
				dataPackage.mode = REQUES_EXIT;
				sprintf(dataPackage.fileName,"%s",pTemp_file->data.fileName);
				sprintf(dataPackage.destAddr,"%s",destAddr);
				sprintf(dataPackage.dest_user,"%s",dest_user);
				pTemp->data = dataPackage;
				pTemp->id = pthread_self();
				pTemp->data.number = num;
				chain_insert(pFile,pTemp);
				pFile->data.number = num;
			//	show_chain(pFile);
				chain_insert(pFile_sta,pFile);
				num_sta +=num;
			//	printf("12312321\n");
		}
		pFile_sta->data.number = num_sta;
//		show_chain(pFile_sta);
		printf("文件完成\n");
		return pFile_sta;
	

}
Thread_Data * send_tell(int mode,char* destAddr,char *dest_user)
{
				my_jmpMenu(2);
 		Sendinit[TELL_REQUES] = init_tell;
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		char buf_tell[200];
		printf("tell:");
		fflush(stdout);
		bzero(buf_tell,sizeof(buf_tell));
		read(0,buf_tell,sizeof(buf_tell));
//		scanf("%s",buf_tell);
		bzero(&dataPackage,sizeof(dataPackage));
		dataPackage = Sendinit[TELL_REQUES](buf_tell,destAddr);
		sprintf(dataPackage.dest_user,"%s",dest_user);
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;

}
Thread_Data *send_del(int mode,char*destAddr,char*dest_user)
{
				my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"%s",dest_user);
		sprintf(dataPackage.destAddr,"%s",destAddr);
		dataPackage.mode = DELFRIEND;
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;

}
Thread_Data *send_vip(int mode,char*destAddr,char*dest_user)
{
				my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		dataPackage.mode = ADDVIP;
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;
		
}
Thread_Data *send_bal(int mode,char*destAddr,char *dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;

	//如不是vip不可以	
		dataPackage.mode = ADDBALANCD;
		printf("input blance");
		fflush(stdout);
		read(0,dataPackage.dorinform.data,sizeof(dataPackage.dorinform.data));

		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		printf("充值的对象:");
		fflush(stdout);
		scanf("%s",dataPackage.dest_user);
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;
		
}
Thread_Data *send_leave(int mode,char *destAddr,char *dest_user)
{
				my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		dataPackage.mode = LEAVE;
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;
		
}

Thread_Data *send_tells(int mode,char *destAddr,char *dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		printf("input tells:");
		fflush(stdout);
		read(0,dataPackage.dorinform.data,sizeof(dataPackage.dorinform.data));
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		dataPackage.mode = TELLS_INVITE;
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;

}
Thread_Data *send_online(int mode,char *destAddr,char *dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		dataPackage.mode = ONLINE;
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;
}
Thread_Data *send_hide(int mode,char *destAddr,char *dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		dataPackage.mode = HIDE;
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;
}
Thread_Data *send_nearby(int mode,char *destAddr,char *dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		dataPackage.mode = NEARBY;
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;
}
Thread_Data *send_circleSend(int mode,char *destAddr,char *dest_user)
{
		my_jmpMenu(2);
		char buf[200];
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		bzero(buf,sizeof(buf));
		printf("input for friend:");
		fflush(stdout);
		read(0,buf,sizeof(buf));
		sprintf(dataPackage.dorinform.data,"朋友圈:%s",buf);
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		dataPackage.mode = 	FRENDCIRCLE_SEND;
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;
}
Thread_Data *send_circleLook(int mode,char *destAddr,char *dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		dataPackage.mode =  FRENDCIRCLE_LOOK;
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;

}
Thread_Data *send_down(int mode,char *destAddr,char *dest_user)
{
		my_jmpMenu(2);
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		bzero(&dataPackage,sizeof(dataPackage));
		sprintf(dataPackage.src_user,"%s",ThisMy.dest_user);
		sprintf(dataPackage.dest_user,"SERVICE");
		dataPackage.mode =  DISK_RECV;
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;

}
Thread_Data *send_upload(int mode,char *destAddr,char *dest_user)
{
		send_file(1,SERVICE_IP,"SERVICE");
}
