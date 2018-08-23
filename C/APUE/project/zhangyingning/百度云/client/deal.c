#include"baiduy.h"
static int sockfd;
void creat_lu()
{
		sBdy catalog;
		bzero(&catalog,sizeof(sBdy));

		catalog.cmd = MKDIR;
		int i;
		usleep(500000);
		printf("  0 创建文件  \n");
		printf("  1 创建目录  \n");
		scanf("%d",&i);
		switch(i)
		{
				case 0:catalog.file_op.file_type = 0;
					   printf("输入文件名.\n");
					   scanf("%s",catalog.file_op.file_name);
break;

				case 1:catalog.file_op.file_type = 1;
					   printf("输入目录名.\n");
					   scanf("%s",catalog.file_op.file_name);
				break;
				default:printf("操作失败.\n");break;
		}
		if(write(sockfd,&catalog,sizeof(sBdy))<0)
		{
			printf("mkdir shibai\n");
		}
		printf("%d   %s\n",
catalog.file_op.file_type,catalog.file_op.file_name);	
}
void find_data()
{
		sBdy look_all_data;
		bzero(&look_all_data,sizeof(sBdy));

		look_all_data.cmd = FIND;
		write(sockfd,&look_all_data,sizeof(sBdy));
	//	while(1)
	//	{
				bzero(&look_all_data,sizeof(sBdy));
				printf("************\n");
				read(sockfd,&look_all_data,sizeof(sBdy));
	//			{
	//					break;
	//			}
				printf("&&&&&&&&&&&&\n");
				write(1,look_all_data.buf,strlen(look_all_data.buf));
	//	}
		printf("\n");		
}
int get_mes(pRe phead)
{
		printf("get_mes:%p\n",phead);
		int fd = open("record_file",O_RDONLY);
		if(fd<0)
		{
				printf("记录文件打开失败.\n");
				return -1;
		}
		pRe i_node,ptmp,ptmp1;
		ptmp = phead;
		while(1)
		{	
			init(&i_node);
			if(read(fd,i_node,sizeof(sRe))<=0)
			{
				free(i_node);
				close(fd);
				printf("文件关闭.\n");
				break;
			}
		//	printf("从文件中读取:%d %s\n",i_node->flag_up_down,i_node->file);
			ptmp->next = i_node;
			ptmp = i_node;
			i_node = NULL;
		}
		ptmp1 = phead->next;
		while(ptmp1!=NULL)
		{
			printf("从文root取:%d %s\n",ptmp1->flag_up_down,ptmp1->file);
			ptmp1 = ptmp1->next;
		}
}
void cat_record(pRe phead)
{
		printf("cat_record:%p\n",phead);
		pRe ptmp=phead->next;
		while(ptmp!=NULL)
		{
				printf("文件:%s ",ptmp->file);
				if(ptmp->flag_up_down==1)
				{
						printf("操作:下载\n");
				}
				if(ptmp->flag_up_down==2)
				{
						printf("操作:上传\n");
				}
				ptmp = ptmp->next;
		}
}
void dele(pRe phead)
{
		pRe ptmp=phead->next;
		pRe pp;
		while(ptmp!=NULL)
		{
			pp = ptmp->next;
			free(ptmp);
			ptmp = pp;
		}	
		phead->next = NULL;	
		int fd = open("record_file",O_TRUNC|O_RDWR);
		if(fd<0)
		{
			printf("删除文件信息失败.\n");
			return ;
		}
		close(fd);
}
/*
用户成功登录的相关操作
*/
int op_deal(int tmp)
{
		usleep(500000);			               //模拟载入
		sockfd = tmp;
		int op_choose;
		sRe re_phead;
		re_phead.next=NULL;
		int ret = get_mes(&re_phead);	               //再文件中取出信息重新建立链表
		if(ret<0)
		{
				printf("获取记录信息失败.\n");
		}
		
		while(1)
		{
				printf("   1    上传文件  \n");
				printf("   2    下载文件  \n");
				printf("   3 创建文件或目录  \n");
				printf("   4      查看    \n");
				printf("   5    查看记录    \n");
				printf("   6    清除记录    \n");
				printf("   7  返回上一界面  \n");
				scanf("%d",&op_choose);
				usleep(500000);
				switch(op_choose)
				{
						case 1:put_file(sockfd,&re_phead);break;
						case 2:get_file(sockfd,&re_phead);break;
						case 3:creat_lu();break;
						case 4:find_data();break;
						case 5:cat_record(&re_phead);break;
						case 6:dele(&re_phead);break;
						case 7:return -1;break;
						default:printf("无效操作\n");break;
				}				
		}
}

