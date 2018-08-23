#include"apue.h"

void create_memory(pF *pnode)
{
		*pnode=(pF)malloc(sizeof(sF));
		if(NULL==*pnode)
		{
				printf("mallco fail");
				exit(-1);
		}
}
void init_node(pF *pnode)
{
		create_memory(pnode);
		(*pnode)->next=*pnode;
		(*pnode)->prev=*pnode;
}
void creat_tail_chain(pF pHead,char *name,char *passwd)
{
		int i;
		pF pnew=NULL;
		init_node(&pnew);
		strcpy(pnew->ftp_usrname,name);
		strcpy(pnew->ftp_passwd,passwd);
		pnew->prev=pHead->prev;
		pHead->prev->next=pnew;
		pHead->prev=pnew;
		pnew->next=pHead;
}
int login_infor(pF pHead,char *name,char *passwd)
{
		pF ptmp=NULL;
		for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
		{
				if(strcmp(name,ptmp->ftp_usrname)==0)
				{
						return 2;
				}
		}
		creat_tail_chain(pHead,name,passwd);
		return 1;
}
void delete(pF pHead,char *name)
{		
		pF ptmp=NULL;
		for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
		{
				if(strcmp(name,ptmp->ftp_usrname)==0)
				{
						ptmp->prev->next=ptmp->next;
						ptmp->next->prev=ptmp->prev;
						ptmp->prev=ptmp;
						ptmp->next=ptmp;
				}
		}
}
void show_chain(pF pHead)
{
		pF ptmp=NULL;
		for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
			{
					printf("%s %s\n",ptmp->ftp_usrname,ptmp->ftp_passwd);
			}
			
}
/*int main()
{
		pF pHead=NULL;
		init_node(&pHead);
		for(;;)
		{
		char a[30],b[30];
		printf("输入名字密码\n");
		scanf("%s%s",a,b);
		int f=find(pHead,a,b);
		printf("%d\n",f);
		show_chain(pHead);
		
		}
		struct sockaddr_in selfaddr,conaddr;
		int ret,confd;
		socklen_t len =sizeof(conaddr);
		

		
}*/
