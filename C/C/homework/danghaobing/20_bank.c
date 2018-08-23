#include"stdio.h"
int creatMenu();
int showMenue(int id);
int main()
{
		int in_ch,passwd,i;
		int id;
		static int c_id=1000;
		int a[50000];//一个id与passwd相关连的数组
		for(;;)
		{
		printf("1 输入帐号密码\n");
		printf("2 创建账户\n");
		printf("3 退出程序\n");
		scanf("%d",&in_ch);
		switch(in_ch)
		{
				case 1:
						for(i=1;i<=4;i++)
						{
						printf("请输入帐号：");
						scanf("%d",&id);
						printf("请输入密码：");
						scanf("%d",&passwd);
						if(a[id]==passwd)
						{
							printf("密码输入正确！\n");
							showMenu(id);
							break;
						}
						else
							printf("密码输入错误！请重新输入\n");
						if(i==4)
						{
								printf("您输入的次数太多，卡已吞！\n");
								return 0;
						}

						}
						break;
						

				case 2:
						c_id++;//double balance;//余额
						a[c_id]=creatMenu(c_id);//获取信息 创建账户
						printf("账户：%d\n密码:%d\n请认真记好！\n",c_id,a[c_id]);
						break;
				case 3:
						return 0;
		}

		}
}
int creatMenu(int c_id)//创建账户
{
	int c_passwd;
	c_id=generatorID();
	printf("您的帐号为:%d\n",c_id);
	printf("请输入您的个人密码：");
	scanf("%d",&c_passwd);
	printf("账户创建成功！\n");
	return c_passwd;

}
int generatorID()//创建ID号
{
		static int i=1000;
		i++;
		return i;
}
int showMenu(int id)
{
		int c_menu,c_c_menu,c_continue;
		int sum;//本次操作金额
		int balance;//余额
		int b[50000]={0};
		
		for(;;)
		{
				printf("1 查询账户信息\n");
				printf("2 存款\n");
				printf("3 取款\n");
				printf("4 返回上一菜单\n");
				scanf("%d",&c_menu);
				switch(c_menu)
				{
						case 1:
							printf("您的余额为：%d\n",b[id]);
							printf("按任意键继续！\n");
							scanf("%d",&c_continue);
							break;
						case 2:
							for(;;)
							{
							printf("请输入要充入的钱数：\n");
							scanf("%d",&sum);
							//printf("b[%d]=%d",id,b[id]);
							b[id]=b[id]+sum;
							printf("存储成功!本次操作金额为：%d\n您的余额为：%d\n",sum,b[id]);
							printf("是否继续存钱？\n");
							printf("1 继续存钱\n");
							printf("2 退出存款菜单\n");
							scanf("%d",&c_c_menu);
							if(c_c_menu==2)
							break;
							}
							break;
						case 3://取款
							for(;;)
							{
									printf("请输入要取出的钱数：\n");
									scanf("%d",&sum);
									b[id]=b[id]-sum;
									printf("取款成功，请拿好,本次操作金额：%d\n您的账户余额：%d\n",sum,b[id]);
									printf("1 继续取款\n");
									printf("2 退出取款菜单\n");
									scanf("%d",&c_c_menu);
									if(c_c_menu==2)
									break;

							}
														
							
							break;
						case 4:
							return 0;
							break;

			
				}
		}
}
