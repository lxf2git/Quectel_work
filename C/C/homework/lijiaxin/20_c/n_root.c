#include"main.h"
void log_in();
void creatMenu()
{
		int i=0;
		do
		{
			printf("是否创建新用户，是输入1，不是输入0：\n");
			scanf("%d",&i);
			switch(i)
			{	
					case 1:log_in();break;
					case 0:creat();break;
					default:break;
			}
		}
		 while(0!=i);
}
void log_in()
{
		long addr;
		do
		{
			printf("请输入8位帐号id：\n");
			scanf("%ld",&addr);
			printf("请输入4位密码:\n");
			scanf("%d",&password);
		}while(id==addr&&printf("你的用户已被建立，请重新创建.\n"));
		id=addr;
}
void creat()
{
		int i=0;
		long id1;
		int password1;
		do
		{
				if(i==3)
				{
					exit(0);
				}
				printf("请输入8位用户id:\n");
				scanf("%ld",&id1);
				printf("请输入4位密码\n");
				scanf("%d",&password1);
				i++;
//				printf("%ld",id);
		}while(id!=id1 || password!=password1);
}





