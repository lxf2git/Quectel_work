#include"baiduy.h"

static int sockfd;

void init(pRe *ptmp)
{
	 *ptmp = (pRe)malloc(sizeof(sRe));
	 if(ptmp==NULL)
	 {
			 perror("malloc");
			 exit(-1);
	 }
	 (*ptmp)->flag_up_down=0;
	 (*ptmp)->next = NULL;
}

void creat_record_chain(pRe pHead,pRe pnode)
{


		int fd = open("record_file",O_WRONLY);
		if(fd<0)
		{
				printf("保存记录失败.\n");
				return ;
		}
		lseek(fd,0,SEEK_END);
		int ret = write(fd,pnode,sizeof(sRe));
		if(ret<=0)
		{
				printf("写入失败.\n");
		}
		printf("写入文件中.\n");
		close(fd);

		pRe ptmp=NULL;
		ptmp = pHead;
		printf("记录结构体信息:%d %s\n",pnode->flag_up_down,pnode->file);
		while(ptmp->next!=NULL)
		{
				ptmp = ptmp->next;
		}
		ptmp->next = pnode;
}

int get_file(int tmp,pRe phead)
{
		pRe i_node=NULL;
		init(&i_node);	

		sBdy download;
		bzero(&download,sizeof(download));
		sockfd = tmp;
		download.cmd = GET;
		download.file_op.file_type = 1;
		printf("下载文件名.\n");
	   	scanf("%s",download.file_op.file_name);

		strcpy(i_node->file,download.file_op.file_name);

		write(sockfd,&download,sizeof(sBdy));
	
		i_node->flag_up_down = 1;
     		creat_record_chain(phead,i_node);
		printf("下载文件写入链表:%d %s\n",i_node->flag_up_down,i_node->file);
		char buf1[100]={'\0'};
		char buf2[100]={'\0'};
		printf("输入存储路径(绝对).\n");
		scanf("%s",buf1);

		int i=1;
		int len;

		while(1)
		{
				bzero(&download,sizeof(sBdy));
		
				read(sockfd,&download,sizeof(sBdy));
				if(i==1)
				{
					     printf("xxxxxxxx\n");
						 len = strlen(download.file_op.file_name) - strlen(strrchr(download.file_op.file_name,'/'));
				        strcpy(buf2,buf1);
			//			printf("buf2:%s\n",buf2);
				}
				i = 0;
				strcpy(buf1,buf2);
				printf("download:%s\n",download.file_op.file_name);
				strcat(buf1,download.file_op.file_name+len);
		//		printf("buf1:%s\n",buf1);
				
				strcpy(download.file_op.file_name,buf1);

				if(strncmp(download.buf,"no_file",7)==0)
				{
						printf("文件不存在.\n");
						return 0;
				}
		
				char buf[100]={'\0'};
				if(download.file_op.file_type==1)
				{
					sprintf(buf,"mkdir %s",download.file_op.file_name);
					system(buf);
				}
				if(download.file_op.file_type==0)
				{
						int fd = open(download.file_op.file_name,O_CREAT|O_EXCL|O_RDWR,0666);
						if(fd<0)
						{
								if(errno==EEXIST)
								{
										fd = open(download.file_op.file_name,O_WRONLY);
										if(fd<0)
										{
												perror("2 open.");
												exit(-1);
										}
										lseek(fd,0,SEEK_END);
								}
								else
								{
										perror("1open");
										exit(-1);
								}
						}						
						int yy=write(fd,download.buf,strlen(download.buf));

				//		printf("%d %s\n",yy,download.buf);
						bzero(download.buf,512);
						close(fd);
				}
				if(download.file_op.file_type==2)				
				{
						break;
				}
		}
}
