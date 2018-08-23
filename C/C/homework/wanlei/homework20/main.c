#include"main.h"

int main()
{
	long id;
	int passwd;
	double balance;
	printf("请创建账户\n");
	id=creatMenu();
	passwd=password(id);
	showMenu();
	return 0;
}
