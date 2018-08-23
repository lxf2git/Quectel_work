#include"apue.h"
/*粉丝列表*/
void look_fans(struct message *mess,pUser pHead)
{
		pUser tmpe;
		pFans fans;
		char ch[40];
		char buf[40];
		char xin[1024];
		int i=0;
		printf("mess->userid:%s\n",mess->userid);

		for(tmpe = pHead->next;tmpe!=pHead;tmpe = tmpe->next)
		{   
				if(strcmp(mess->userid,tmpe->id)==0)
				{   
						break;
				}   
		}   
		if(tmpe!=pHead)
		{
				for(fans = tmpe->fans_Head->next,i=0;fans!=tmpe->fans_Head;fans = fans->next)
				{
						i++;
						bzero(buf,sizeof(buf));
						my_itoa(buf,i);
						bzero(ch,sizeof(ch));
						bzero(xin,sizeof(xin));
						sprintf(ch,"fans %s :",buf);
				//		strcat(xin,ch);
						write(mess->sockfd,ch,sizeof(ch));
						
						bzero(ch,sizeof(ch));
						sprintf(ch,"id:%s",fans->fans_id);
						//strcat(xin,ch);
						write(mess->sockfd,ch,sizeof(ch));

						bzero(ch,sizeof(ch));
						sprintf(ch,"name:%s",fans->fans_name);
						//strcat(xin,ch);
						write(mess->sockfd,ch,sizeof(ch));
				}

				bzero(ch,sizeof(ch));
				strcpy(ch,"*#*");
				write(mess->sockfd,ch,sizeof(ch));				
		}
		else
		{
				printf("mess错误\n");

				bzero(ch,sizeof(ch));
				strcpy(ch,"*#*");
				write(mess->sockfd,ch,sizeof(ch));				
		}

}
