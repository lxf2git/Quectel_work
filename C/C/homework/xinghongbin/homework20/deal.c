#include"main.h"
int password[6];
double balance[6];
//int *a[6];
long int id_name=0;
int id_num=0;
int creatMenu()
{
		int i=0;
		int a;
		printf("创建用户\n");
		generatorId();
//		while(ch=getchar()!='#');
		printf("请为用户创建密码\n");
		do
		{
			printf("请输入密码（6位）\n");	
			scanf("%d",&password[id_name]);

			printf("再次输入\n");
			printf("请输入密码（6位）\n");	
			scanf("%d",&a);

		}while((password[id_name]!=a)&&printf("两次输入不一致\n"));
		printf("设置成功\n");
		printf("你的账户信息为  id:%d  余额:%d \n",id_name,balance[id_name]);

		showmen();        //主界面

		return 0;

}
	
int generatorId()
{
		char ch;
		printf("请稍等...........\n");
//		printf("输入用户名#号开始\n");
//		while(ch=getchar()!='#');					//吸收
		id_num++;
	
		id_name=id_num;
//		scanf("%s",a[id_name]);						//为用户信息
		printf("你的ID帐号为%d\n",id_name);
		return 0;

}
int passwd()										//输入数组a与 保存密码数组b比较
{
		printf("请输入 ID号\n");
		scanf("%ld",&id_name);

		int a;
		printf("请输入密码（6位）\n");	
		scanf("%d",&a);

		if(password[id_name]!=a)
					return 1;
		return 0;
		
}

