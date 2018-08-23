#include"apue.h"
/*查看关注人的围博*/
int look_weibo(struct message *mess,pUser pHead)
{
		/*	comment(mess,comment_Head);*/
		printf("mess->userid:%s\n",mess->userid);
		char att_id[30];
		char ch[1024];
		char  buf[2];
		pUser tmpe,tmpe_id;
		pAttenrion att;
		for(tmpe = pHead->next;tmpe!=pHead;tmpe = tmpe->next)
		{
				if(strcmp(mess->userid,tmpe->id)==0)
				{
						printf("tmpe_id:%s\n",tmpe->id);
						break;
				}
		}
		
		if(tmpe!=pHead)
		{
				for(att = tmpe->attenrion_Head->next;att!=tmpe->attenrion_Head;att = att->next)
				{
						bzero(att_id,sizeof(att_id));
						strcpy(att_id,att->attenrion_id);
						printf("att_id:%s\n",att_id);
						for(tmpe_id = pHead->next;tmpe_id!=pHead;tmpe_id = tmpe_id->next)
						{
								if(strcmp(att_id,tmpe_id->id)==0)
								{
										break;
								}
						}

						if(tmpe_id!=pHead)
						{
								bzero(ch,sizeof(ch));
								if(tmpe_id->publish_Head->next!=tmpe_id->publish_Head)
								{
										sprintf(ch,"%s :  \n %s",tmpe_id->id,tmpe_id->publish_Head->next->content);
										printf("ch:%s\n",ch);
										write(mess->sockfd,ch,strlen(ch)+1);
										bzero(buf,sizeof(buf));
										read(mess->sockfd,buf,sizeof(buf));/*接收 1.评论 2不评 0 推出 */
										printf("____\n");
										printf("%s\n",buf);
										switch(buf[0])
										{
												case '1':
														printf("评论\n");
														comment(*mess,tmpe_id->publish_Head->next->comment_Head);/*思维*/
														printf("评论ok");
														break;
												case '2':
														break;
												case '0':
														return;
														break;
												default:
														printf("输入不对\n");
										}

								}
						}
						else
						{
								printf("id:%s\n",att_id);
								printf("关注的僵尸账户\n");
						}

				}

		}

		bzero(ch,sizeof(ch));
		strcpy(ch,"*#*");
		write(mess->sockfd,ch,strlen(ch)+1);

}
