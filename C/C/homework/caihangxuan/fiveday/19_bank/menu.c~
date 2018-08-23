#include"menu.h"
#include"about_money.h"

void withdrawMenu();
void queryMenu();
void saveMenu();

extern int b[100];
extern long id;
void showMenu()
{
	int s;
	for(;;)
	{
	printf("\n------------\n按1查询账户\n按2存款\n按3取款\n按4返回上级\n------------\n");
	scanf("%d",&s);
	if(s==1)
		queryMenu();
	if(s==2)
		saveMenu();
	if(s==3)
		withdrawMenu();
	if(s==4)
		break;
	}	
	
}

void saveMenu()
{
	int sum,i,s;
	for(;;)
	{
		printf("\n\n按1请输入存款金额\n按2返回上级\n");
		scanf("%d",&s);
		if(s==2)
		return;
		if(s==1)
		printf("请打入存款 /元\n");
		scanf("%d",&sum);
		printf("一共是%d元，对吗？(1/0)\n",sum);
		scanf("%d",&i);
		if(i==1)
		{
		save(sum,id);
		printf("\n\n----------\n您的操作已成功\n-----------\n");
		}
		else
		printf("请重新输入\n");
		
	}
}

void queryMenu()
{
	int i,s;
	for(;;)
	{
		printf("\n\n按1请输入id\n按2返回上级\n");
		scanf("%d",&s);
		if(s==2)
		return;
		if(s==1)
		printf("请输入id\n");
		scanf("%d",&id);
		printf("\n\n----------\n您的余额为%d\n----------\n",b[id]);
	}
}

void withdrawMenu()
{
	int s,i;
	for(;;)
	{
		printf("\n\n按1请输入取款金额\n按2返回上级\n");
		scanf("%d",&s);
		if(s==2)
		return;
		if(s==1)
		printf("请输入取款金额\n");
		scanf("%d",&i);
		withdraw(i,id);
		printf("\n\n----------\n您的操作已成功\n----------\n");
	}
}
