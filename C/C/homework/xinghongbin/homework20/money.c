#include"main.h"
extern int id_name;
extern double balance[];
void saveMenu()
{
		printf("正在使用存款功能\n");
		printf("请输入ID\n");
		scanf("%d",&id_name);
		double sum;
		int i;
		do
		{
				printf("1:100元\n");
				printf("2:200元\n");
				printf("3:500元\n");
				printf("4: 其他\n");
				printf("5:返回主菜单\n");
				printf("6:推出系统\n");
				scanf("%d",&i);
		}while(((i!=1)&&(i!=2)&&(i!=3)&&(i!=4)&&(i!=5)&&(i!=6))&&printf("输入错误\n"));
		switch(i)
		{
				case 1:sum=100;break;
				case 2:sum=200;break;
				case 3:sum=500;break;
				case 4:;printf("输入金额\n");scanf("%lf",&sum);break;
				case 5:return;
				case 6:exit(0);		
		}
		save(sum);
		showmen();        //主界面
		
}
void save(double a)
{
		balance[id_name]=balance[id_name]+a;
		printf("余额%lf\n",balance[id_name]);		
}

void withdrawMenu()
{
		double sum;
		int p,i;
		printf("正在使用取款功能\n");
		p=passwd();
		do
		{
				printf("1:100元\n");
				printf("2:200元\n");
				printf("3:500元\n");
				printf("4: 其他\n");
				printf("5:返回主菜单\n");
				printf("6:推出系统\n");
				scanf("%d",&i);
		}while(((i!=1)&&(i!=2)&&(i!=3)&&(i!=4)&&(i!=5)&&(i!=6))&&printf("输入错误\n"));
		switch(i)
		{
				case 1:sum=100;break;
				case 2:sum=200;break;
				case 3:sum=500;break;
				case 4:;printf("输入金额\n");scanf("%lf",&sum);break;
				case 5:return;
				case 6:exit(0);		
					   
		}
		withdraw(sum,p);
		showmen();        //主界面
}
int withdraw(double sum,int p)
{
		int b;
		if(0==p)
		{
			printf("密码正确\n");	
			if(balance[id_name]>=sum)
			{
					balance[id_name]=balance[id_name]-sum;
					printf("取出%lf元\n",sum);
			}
			else
					printf("余额不足");
		}
		else
			printf("密码错误\n");
			return 0;
		
}
void queryMenu()
{
		int i,p;
		printf("正在使用查询功能\n");
		p=passwd();
		do
		{
				printf("1:查询余额\n");
				printf("2:查询 I D\n");
				printf("3:更换密码\n");
				printf("4: 其他\n");
				printf("5:返回主菜单\n");
				printf("6:推出系统\n");
				scanf("%d",&i);
		}while(((i!=1)&&(i!=2)&&(i!=3)&&(i!=4)&&(i!=5)&&(i!=6))&&printf("输入错误\n"));
		switch(i)
		{
				case 1:printf("%d\n",query());break;
				case 2:printf("%d\n",id_name);break;
				case 3:passwd();break;
				case 4:printf("系统繁忙\n");break;
				case 5:return;
				case 6:exit(0);		
		}			   
		
		showmen();        //主界面

}


float query()
{
		printf("%lf\n",balance[id_name]);
		return 0;

}
