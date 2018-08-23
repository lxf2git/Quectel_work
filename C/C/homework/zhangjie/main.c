#include"main.h"

void showMenu()
{
		char j;
		printf("a----查询余额\n");
        printf("b----创建账户\n");
        printf("c--------存款\n");
        printf("d--------取款\n");
		printf("e----退出程序\n");
        printf("请选择\n");
		getchar();
        scanf("%c",&j);
		getchar();
        if(j==97)
		{
			queryMenu();
		}
		if(j==99)
		{
			saveMenu();
		}
		if(j==100)
		{
			withdrawMenu();
		}
		if(j==98)
		{
			creat();
		}
		if(j==101)
		exit (0);
}

void creat()
{
	int i,balance,n;
	char p;
	int a[5];
	int b[5];
	printf("请输入五位数密码\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("请确认密码\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<5;i++)
	{
		if(a[i]!=b[i])
		{
			n=0;
			break;
		}
		else
		{
			n=1;
		}
	}
	if(n==1)
	printf("ok\n");
	else if(n==0)
	creat();
	static int j=1;
	j++;
	balance=10;
	printf("你的帐号为%d\npassword为\n",j);
	for(i=0;i<5;i++)
	{
		password[i]=a[i];	
		printf("%d",password[i]);
	}
		printf("\n");
		showMenu();
}

void queryMenu()
{	
	int a[5];
	char p;
	int i,n;
	printf("请输入密码\n ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		if(a[i]!=password[i])
		{
			n=0;
			break;
		}
		else
		{
			n=1;
		}
	}
	 if(n==0)
	queryMenu();	
	else if(n==1)
	{
		printf("%d\n",balance);
	}
		showMenu();
}

void saveMenu()
{
	int i,sum,n;
	int a[5];
	printf("请输入密码\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		if(a[i]!=password[i])
		{
			n=0;
			break;
		}
		else
		{
			n=1;
		}
	}
	if(n==0)
	saveMenu();
	else if(n==1)
	{
		printf("请输入存款金额\n");	
		scanf("%d",&sum);
		balance+=sum;
		printf("当前总存款为%d\n",balance);
	}
		showMenu();
}

void withdrawMenu()
{	
	int i,sum,n;
	int a[5];
	printf("请输入密码\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		if(a[i]!=password[i])
		{
			n=0;
			break;
		}
		else
		{
			n=1;
		}
	}
	if(n==0)
	withdrawMenu();
	else if(n==1)
	{
		printf("请输入取款金额\n");
		scanf("%d",&sum);
		balance=balance-sum;
		printf("当前存款数为%d\n",balance);
	}
		showMenu();
}

void input()
{
	int i,n,k=1,m;
	int a[5];
	printf("请输入id号\n");
	scanf("%d",&m);
	j=m;
	if(j==1)
	{	
		printf("请输入密码\n");
		for(i=0;i<5;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<5;i++)
		{
			if(a[i]!=k)
			{
				n=0;
				break;
			}
			else
			{
				n=1;
			}
			k++;
		}
			if(n==0)
			input();
			else if(n==1)
			showMenu();
	}
	if(j!=1)
	input();
}
