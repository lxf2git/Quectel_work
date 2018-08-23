#include"baiduy.h"
static int len;
int find_data1(char *str1,int sockfd);
int put_file(int tmp,pRe phead)
{
		char fileBuf[100];
		pRe i_node=NULL;
		init(&i_node);
		i_node->flag_up_down = 2;

		printf("请输入上传文件.\n");
		
                scanf("%s",fileBuf);
		 len = strlen(fileBuf)-strlen(strrchr(fileBuf,'/'));
	//	printf("len:%d\n",len);
		printf("%d %s\n",i_node->flag_up_down,i_node->file);
		strcpy(i_node->file,strrchr(fileBuf,'/')+1);
		printf("记录链表的文件:%d %s\n",i_node->flag_up_down,i_node->file);
		
		creat_record_chain(phead,i_node);
		int ret = find_data1(fileBuf,tmp);
		if(ret==-1)
		{
			sBdy kk;
			bzero(&kk,sizeof(sBdy));
			ret = open(fileBuf,O_RDONLY);
			if(ret<0)
			{
				printf("没有文件或目录.\n");
				return 0;
			}
			kk.cmd = PUT;
			kk.file_op.file_type = 0;
			strcpy(kk.file_op.file_name,fileBuf);
			while(1)
			{
					if(read(ret,kk.buf,sizeof(kk.buf))<=0)
					{
					
							close(ret);					
							break;
					}
					
					kk.num = len;
					write(tmp,&kk,sizeof(sBdy));
		     		printf("%s\n",kk.buf);

	    			bzero(kk.buf,strlen(kk.buf)+1);
			}						
		}
		sBdy suc;
		suc.file_op.file_type = 2;
		suc.num =len;
		write(tmp,&suc,sizeof(sBdy));
		return 0;
}

int find_data1(char *str1,int sockfd)
{
		sBdy upload;
		bzero(&upload,sizeof(sBdy));
		
		int ret=0;
		char dest_tmp[]="/";
		printf("str1:%s\n",str1);
		upload.cmd = PUT;
		upload.num = len;
	//	printf("len:%d\n",upload.num);
		DIR *pdir = opendir(str1);
		if(pdir==NULL)
		{
				perror("opendir");
				return -1;
		}
		struct stat st;
		struct dirent *pdirent=NULL;
		
		ret = chdir(str1);
		if(ret<0)
		{
				perror("chdir");
		}
		upload.file_op.file_type = 1;
		strcpy(upload.file_op.file_name,str1);
		upload.num = len;
		write(sockfd,&upload,sizeof(sBdy));
//		printf("%d %s\n",upload.file_op.file_type,upload.file_op.file_name);
//		printf("cmd:%d\n",upload.cmd);

		while(1)
		{
				pdirent=readdir(pdir);
				if(pdirent==NULL)
				{
						printf("readdir error.\n");
						break;
				}
				ret = stat(pdirent->d_name,&st);
				if(ret<0)
				{
						perror("stat");
						goto ERR;
				}
				if(pdirent->d_name[0]=='.')
				{
						continue;
				}
	
				
				

				if(S_ISDIR(st.st_mode))
				{	

						strcpy(upload.file_op.file_name,str1);	
						strcat(upload.file_op.file_name,dest_tmp);
						strcat(upload.file_op.file_name,pdirent->d_name);
						printf("mulu-num:%d\n",upload.num);
						find_data1(upload.file_op.file_name,sockfd);

				}
				else
				{
						upload.file_op.file_type = 0;
						
				      	int fd = open(upload.file_op.file_name,O_RDONLY);
						if(fd<0)
						{
								perror("put_open");
								goto ERR;
						}

						strcpy(upload.file_op.file_name,str1);	
						strcat(upload.file_op.file_name,dest_tmp);
						strcat(upload.file_op.file_name,pdirent->d_name);
						while(1)
						{
								printf("读学操作.\n");
								if(read(fd,upload.buf,sizeof(upload.buf))<=0)
								{
										close(fd);
										break;
								}

				                upload.num = len;
								printf("wenjian_num %d\n",upload.num);
								write(sockfd,&upload,sizeof(sBdy));
								bzero(upload.buf,strlen(upload.buf));
						}
				}
				
		}
		chdir("../");
		closedir(pdir);
		return 0;
ERR:
	closedir(pdir);
	return -1;
}
