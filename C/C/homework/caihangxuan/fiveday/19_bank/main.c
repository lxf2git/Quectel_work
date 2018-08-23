#include<stdio.h>
#include"id_passwd.h"
#include"menu.h"
int pass(long _id,int _passwd);
int a[100],b[100]={0},passwd,repasswd;
long id=0;
int main()
{	
	printf("注意：关闭程序会导致数据消失.");
	for(;;)
	{
		int s,revalue;
		printf("\n------------\n按1输入id号 \n按2创建一个新账户\n------------\n");
		scanf("%d",&s);
		if(s==1)
		{
			printf("请输入您的id\n");
			scanf("%d",&id);
			printf("请输入密码\n");
			scanf("%d",&passwd);
			revalue=pass(id,passwd);
			if(revalue==1)
				showMenu();
			else
				printf("\n------用户不存在或密码错误\n------\n");	
		}
		else if(s==2)
		{
			id=generatorid();
			printf("\n------\n您的id为%d\n------\n",id);
			for(;;)
			{
				printf("请设置您的密码\n");
				scanf("%d",&passwd);
				printf("请再输入一次\n");
				scanf("%d",&repasswd);
				if(passwd=repasswd)
				{
					printf("\n------\n您的密码设置成功\n------\n");
					input_passwd(id,passwd);
					break;
				}		
				else
					printf("\n------\n您两次密码输入不一致\n------\n");
			}
			
		}
	}
}


int pass(long _id,int _passwd)
{
	if(a[id]==passwd)
		return 1;
	else
		return 0; 
}

