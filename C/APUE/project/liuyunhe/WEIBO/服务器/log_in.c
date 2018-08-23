#include"apue.h"
/*登录*/
void log_in_id(struct message *mess,pUser pHead)
{
		char ch[30];
		pUser tmpe;
		while(1)/*校验id*/
		{
				bzero(ch,sizeof(ch));
				strcpy(ch,"please input id");
				write(mess->sockfd,ch,sizeof(ch));
				bzero(ch,sizeof(ch));
				read(mess->sockfd,ch,sizeof(ch));
				for(tmpe = pHead->next;tmpe!=pHead;tmpe=tmpe->next)
				{
						if(strcmp(ch,tmpe->id)==0)
						{
								break;
						}
				}

				if(tmpe == pHead)
				{
						;
				}
				else
				{
						bzero(mess->userid,sizeof(mess->userid));
						strcpy(mess->userid,ch);
						bzero(ch,sizeof(ch));
						strcpy(ch,"input password");
						write(mess->sockfd,ch,sizeof(ch));
						break;
				}
		}

		while(1)/*校验密码*/
		{
				bzero(ch,sizeof(ch));
				read(mess->sockfd,ch,sizeof(ch));
				if(strcmp(ch,tmpe->password)==0)
				{
						bzero(ch,sizeof(ch));
						strcpy(ch,"*p*");
						write(mess->sockfd,ch,strlen(ch)+1);
						break;
				}

				else
				{
						bzero(ch,sizeof(ch));
						strcpy(ch,"input password");
						write(mess->sockfd,ch,sizeof(ch));

				}
		}
}

void log_in_name(struct message *mess,pUser pHead)
{
		char ch[30];
		pUser tmpe;
		while(1)/*校验id*/
		{
				bzero(ch,sizeof(ch));
				strcpy(ch,"please input name");
				write(mess->sockfd,ch,sizeof(ch));
				bzero(ch,sizeof(ch));
				read(mess->sockfd,ch,sizeof(ch));
				for(tmpe = pHead->next;tmpe!=pHead;tmpe=tmpe->next)
				{
						if(strcmp(ch,tmpe->name)==0)
						{
								break;
						}
				}

				if(tmpe == pHead)
				{
						;
				}
				else
				{
						bzero(mess->userid,sizeof(mess->userid));
						strcpy(mess->userid,tmpe->id);
						bzero(ch,sizeof(ch));
						strcpy(ch,"input password");
						write(mess->sockfd,ch,sizeof(ch));
						break;
				}
		}

		while(1)/*校验密码*/
		{
				bzero(ch,sizeof(ch));
				read(mess->sockfd,ch,sizeof(ch));
				if(strcmp(ch,tmpe->password)==0)
				{
						bzero(ch,sizeof(ch));
						strcpy(ch,"*p*");
						write(mess->sockfd,ch,strlen(ch)+1);
						break;
				}

				else
				{
						bzero(ch,sizeof(ch));
						strcpy(ch,"input password");
						write(mess->sockfd,ch,sizeof(ch));

				}
		}
}
