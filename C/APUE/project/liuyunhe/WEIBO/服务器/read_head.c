#include"apue.h"

int read_head(pUser puser_Head)
{
		int fid;
		char ch[40];
		printf("加载中\n");
		int fd = open("file",O_RDWR|O_CREAT,777);
		int n=0;
		if(fd<0)
		{
		  		show_err("open_file");
        }

		while(1)
		{
				pUser pnew = NULL;
				init_pUser(&pnew);

				n=read(fd,pnew->id,sizeof(pnew->id));	
				if(n==0)
				{
						break;
				}
				n=read(fd,pnew->password,sizeof(pnew->password));
				if(n==0)
				{
						break;
				}
				n=read(fd,pnew->name,sizeof(pnew->name));
				if(n==0)
				{
						break;
				}

				puser_Head->next->prev = pnew;
				pnew->next = puser_Head->next;
				puser_Head->next = pnew;
				pnew->prev = puser_Head;	
				printf("id:%s\n",pnew->id);
				
				chdir(pnew->id);

				bzero(ch,sizeof(ch));
				sprintf(ch,"%s_fans",pnew->id);
				fid = open(ch,O_RDWR|O_CREAT,777);
				if(fid<0)
				{
						continue;
				}
				while(1)
				{
						pFans pfans_pnew=NULL;
						init_pFans(&pfans_pnew);
						n=read(fid,pfans_pnew->fans_id,sizeof(pfans_pnew->fans_id));
						if(n==0)
						{
								break;
						}

						n=read(fid,pfans_pnew->fans_name,sizeof(pfans_pnew->fans_name));
						if(n==0)
						{
								break;
						}
						
						pnew->fans_Head->next->prev = pfans_pnew;
						pfans_pnew->next = pnew->fans_Head->next;
						pnew->fans_Head->next = pfans_pnew;
						pfans_pnew->prev = pnew->fans_Head;
				}
				close(fid);


				bzero(ch,sizeof(ch));
				sprintf(ch,"%s_attenrion",pnew->id);
				fid = open(ch,O_RDWR|O_CREAT,777);
				if(fid<0)
				{
						continue;
				}
				while(1)
				{
						pAttenrion att_pnew = NULL;
						init_pAtt(&att_pnew);
						
						n=read(fid,att_pnew->attenrion_id,sizeof(att_pnew->attenrion_id));
						if(n==0)
						{
								break;
						}
						n=read(fid,att_pnew->attenrion_name,sizeof(att_pnew->attenrion_name));
						if(n==0)
						{
								break;
						}
						
						pnew->attenrion_Head->next->prev = att_pnew;
						att_pnew->next =  pnew->attenrion_Head->next;
						pnew->attenrion_Head->next = att_pnew;
						att_pnew->prev = pnew->attenrion_Head;
						
				}
				close(fid);

				bzero(ch,sizeof(ch));
				sprintf(ch,"%s_publish",pnew->id);
				fid = open(ch,O_RDWR|O_CREAT,777);
				if(fid<0)
				{
						continue;
				}
				while(1)
				{
						pPublish pub_pnew;
						init_pPublish(&pub_pnew);
						n = read(fid,pub_pnew->content,sizeof(pub_pnew->content));
						if(n==0)
						{
								break;
						}

						pnew->publish_Head->next->prev = pub_pnew;
						pub_pnew->next = pnew->publish_Head->next;
						pnew->publish_Head->next = pub_pnew;
						pub_pnew->prev = pnew->publish_Head;
				}
				close(fid);

				chdir("../");
		}

		printf("加载成功\n");
}
