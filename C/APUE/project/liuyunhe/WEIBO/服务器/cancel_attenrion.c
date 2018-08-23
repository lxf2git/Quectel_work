#include"apue.h"
/*取消关注*/
int cancel_attenrion(struct message *mess,pUser pHead)
{
		char buf[30];
		pUser tmpe;
		pAttenrion att=NULL;
		pFans fans=NULL;
		bzero(buf,sizeof(buf));
		strcpy(buf,"please cancel attenrion：");
		write(mess->sockfd,buf,sizeof(buf));
		bzero(buf,sizeof(buf));
		read(mess->sockfd,buf,sizeof(buf));/*接受取关人的id*/
		printf("buf:%s\n",buf);
		for(tmpe= pHead->next;tmpe!=pHead;tmpe=tmpe->next)
		{
				printf("****\n");
				if(strcmp(tmpe->id,mess->userid)==0)
				{
						for(att = tmpe->attenrion_Head->next;att!=tmpe->attenrion_Head;att = att->next)
						{
								if(strcmp(att->attenrion_id,buf)==0)
								{
										att->prev->next = att->next;
										att->next->prev = att->prev;
										att->next=att;
										att->prev=att;
										if(att!=NULL)
										{
												free(att);
												att = NULL;
										}
										break;			
								}
						}
						write_attenrion(mess->userid,tmpe->attenrion_Head);/*刷新关注文件*/
				}
				

				if(strcmp(tmpe->id,buf)==0)
				{
						for(fans = tmpe->fans_Head->next;fans!=tmpe->fans_Head;fans = fans->next)
						{
								if(strcmp(fans->fans_id,mess->userid)==0)
								{
										fans->prev->next = fans->next;
										fans->next->prev = fans->prev;
										fans->next=fans;
										fans->prev=fans;
										if(fans!=NULL)
										{
												free(fans);
												fans = NULL;
										}
										break;			
								}
						}
						
				write_fans(buf,tmpe->fans_Head);
				}
		}

		printf("取关成功\n");
}
