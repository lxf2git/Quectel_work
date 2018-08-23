#include"apue.h"


/*用户信息*/
void write_pUser(pUser pnew)
{
		int fd = open("file",O_RDWR|O_CREAT,777);
		if(fd<0)
		{
				show_err("open_file");
		}
		lseek(fd,0,SEEK_END);
		if(pnew!=NULL)
		{
				write(fd,pnew->id,sizeof(pnew->id));
				write(fd,pnew->password,sizeof(pnew->password));
				write(fd,pnew->name,sizeof(pnew->name));
		}
		mkdir(pnew->id,0777);
		close(fd);
}

/*用户粉丝*/
void write_fans(char *id,pFans fans_Head)
{
		printf("id:%s\n",id);
		chdir(id);
		char ch[40];
		bzero(ch,sizeof(ch));
		sprintf(ch,"%s_fans",id);
		
		unlink(ch);

		int fd = open(ch,O_RDWR|O_CREAT,777);
		pFans pnew = NULL;
		for(pnew=fans_Head->next;pnew!=fans_Head;pnew=pnew->next)
		{
				write(fd,pnew->fans_id,sizeof(pnew->fans_id));
				write(fd,pnew->fans_name,sizeof(pnew->fans_name));
		}
		
		close(fd);
		chdir("../");
}

/*用户关注*/
void write_attenrion(char *id,pAttenrion pattenrion_head)
{
		printf("id:%s\n",id);
		chdir(id);
		char ch[40];
		bzero(ch,sizeof(ch));
		sprintf(ch,"%s_attenrion",id);
		
		unlink(ch);

		int fd = open(ch,O_RDWR|O_CREAT,777);
		pAttenrion pnew = NULL;
		for(pnew = pattenrion_head->next;pnew!=pattenrion_head;pnew=pnew->next)
		{
				write(fd,pnew->attenrion_id,sizeof(pnew->attenrion_id));
				write(fd,pnew->attenrion_name,sizeof(pnew->attenrion_name));
		}
		close(fd);
		chdir("../");
}

/*围博内容*/
void write_publish(char *id,pPublish pnew)
{
		printf("id:%s\n",id);
		chdir(id);
		char ch[40];
		bzero(ch,sizeof(ch));
		sprintf(ch,"%s_publish",id);
		int fd = open(ch,O_RDWR|O_CREAT,777);
		
		lseek(fd,0,SEEK_END);
		if(pnew!=NULL)
		{
				write(fd,pnew->content,sizeof(pnew->content));
		}
		close(fd);
		chdir("../");
}
