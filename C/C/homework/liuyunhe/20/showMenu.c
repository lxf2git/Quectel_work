#include"main.h"

int showMenu(int password)
{
		int a;
		int sum=0;
		while(1)
		{
		printf("1:save\n");//存款
		printf("2:whithdrawMenu\n");//取钱
		printf("3:query\n");//查询
		printf("4:quit\n");//退出
		scanf("%d",&a);
		switch(a)
		{
				case 1:
				sum=save(sum);
				break;
				case 2:
				sum=withdraw(sum,password);
				break;
				case 3:
				query(sum);
				break;
				case 4:
				return 0;
				break;
				default:
				printf("输入错误");
				break;
		}
		}

}
