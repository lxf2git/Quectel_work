#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ftp
{
		char ftp_usrname[30];
		char ftp_passwd[30];
		struct ftp *prev;
		struct ftp *next;
}sF,*pF;
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
int login_infor(pF pHead,char *name,char *passwd,int a)
{
		pF ptmp=NULL;
		if(a==0)
		{
		for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
		{
			
				if(strcmp(name,ptmp->ftp_usrname)==0)
				{
					//名字有了；
					printf("用户名已存在");
						return 2;
				}
		}
		
		creat_tail_chain(pHead,name,passwd);
		printf("注册成功\n");
		return 0;
		}
		if(a==1)
		{
				for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
				{
						if((strcmp(name,ptmp->ftp_usrname)==0)&&(strcmp(passwd,ptmp->ftp_passwd)==0))
						{
								//登录成功
								printf("登录成功\n");
								return 1;
						}
				}
				printf("登录失败\n");
				return 2;
		}
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
		int n;
		for(;;)
		{
				printf("注册  0    登录   1\n");
				scanf("%d",&n);
		char a[30],b[30];
		printf("输入名字密码\n");
		scanf("%s%s",a,b);
		int f=login_infor(pHead,a,b,n);
		printf("%d\n",f);
		show_chain(pHead);
		
		}
		

		
}*/
