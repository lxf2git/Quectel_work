#include"apue.h"
/*注册*/
void my_register(struct message *mess,pUser pHead)
{
		char ch[30];
		pUser tmpe;
		pUser pnew = NULL;
		init_pUser(&pnew);
		while(1)/*注册id*/
		{
				bzero(ch,sizeof(ch));
				strcpy(ch,"please input id");
				write(mess->sockfd,ch,sizeof(ch));
				printf("%s\n",ch);
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
						strcpy(pnew->id,ch);
						bzero(ch,sizeof(ch));
						strcpy(ch,"please input name");
						write(mess->sockfd,ch,sizeof(ch));
						break;
				}
				else
				{
						;
				}
		}

		while(1)
		{
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
						strcpy(pnew->name,ch);
						bzero(ch,sizeof(ch));
						strcpy(ch,"please input password");
						write(mess->sockfd,ch,sizeof(ch));
						break;
				}
				else
				{
						bzero(ch,sizeof(ch));
						strcpy(ch,"please input name");
						write(mess->sockfd,ch,sizeof(ch));
				}
		}
		
		bzero(ch,sizeof(ch));
		read(mess->sockfd,ch,sizeof(ch));
		strcpy(pnew->password,ch);
		
		pHead ->next->prev = pnew;		/*头插*/
		pnew->next = pHead->next;
		pHead->next = pnew;
		pnew->prev = pHead;
		
		write_pUser(pnew);/*信息存入文件*/

		bzero(ch,sizeof(ch));
		strcpy(ch,"*#*");
		write(mess->sockfd,ch,sizeof(ch));
}
