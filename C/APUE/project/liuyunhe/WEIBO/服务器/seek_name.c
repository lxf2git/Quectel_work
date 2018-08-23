#include"apue.h"
/*搜索*/

my_itoa_name(char *ch,int value)
{
		int i,j;
		char tmp[32];
		bzero(tmp,sizeof(tmp));
		if(0==value)
		{
				ch[0]='0';
				ch[1]='\0';
				return;
		}
		for(i=0;i<32;i++)
		{
				tmp[i]=(value%10)+'0';
				value=value/10;
				if(value==0)
				{
						break;
				}
		}
		for(j=0;i>=0;j++,i--)
		{
				ch[j]=tmp[i];
				ch[j+1]='\0';
		}
	/*	printf("tmp:%s\n",tmp);*/
}

void seek_name(struct message *mess,pUser pHead)
{
		pUser tmpe;
		pFans fans;
		pAttenrion att;
		int i;
		char ch[40];
		char buf[40];
		bzero(ch,sizeof(ch));
		strcpy(ch,"please seek name");
		write(mess->sockfd,ch,sizeof(ch));
		bzero(ch,sizeof(ch));
		read(mess->sockfd,ch,sizeof(ch));
		
		for(tmpe = pHead->next;tmpe!=pHead;tmpe = tmpe->next)
		{
				if(strcmp(ch,tmpe->name)==0)
				{
						break;
				}
		}	

		if(tmpe == pHead)
		{
				bzero(ch,sizeof(ch));
				strcpy(ch,"not the same name");
				write(mess->sockfd,ch,sizeof(ch));
				
		}
		else
		{
				bzero(mess->destid,sizeof(mess->destid));
				strcpy(mess->destid,ch);
				bzero(ch,sizeof(ch));
				sprintf(ch,"id:%s",tmpe->id);
				write(mess->sockfd,ch,sizeof(ch));
				bzero(ch,sizeof(ch));
				sprintf(ch,"name:%s",tmpe->name);
				write(mess->sockfd,ch,sizeof(ch));
				for(fans = tmpe->fans_Head->next,i=0;fans!=tmpe->fans_Head;i++,fans = fans->next)
				{
					;
				}

				printf("粉丝数%d\n",i);
				bzero(buf,sizeof(buf));
				my_itoa_name(buf,i);
				bzero(ch,sizeof(ch));
				sprintf(ch,"fans:%s",buf);
				printf("%s\n",ch);
				write(mess->sockfd,ch,sizeof(ch));

				for(att = tmpe->attenrion_Head->next,i=0;att!=tmpe->attenrion_Head;i++,att =att->next)
				{
						;
				}
				printf("关注：%d\n",i);
				bzero(buf,sizeof(buf));
				my_itoa_name(buf,i);
				bzero(ch,sizeof(ch));
				sprintf(ch,"attenrion:%s",buf);
				printf("%s\n",ch);
				write(mess->sockfd,ch,sizeof(ch));

		}
				bzero(ch,sizeof(ch));
				strcpy(ch,"*#*");
				write(mess->sockfd,ch,strlen(ch)+1);
}
