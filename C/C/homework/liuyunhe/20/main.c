#include"main.h"

int main()
{
		long id;
		int password;
		double belance;
		printf("输入ID：\n");
		scanf("%d",&id);
		printf("输入密码：\n");
		scanf("%d",&password);
		create(belance,password);
		showMenu(password);
		return 0;
}
