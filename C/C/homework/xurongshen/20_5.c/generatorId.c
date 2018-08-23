#include"my.h"

long generatorId()
{
	printf("generatorId --->success!\n");

	long id,passwd;
	user use;
	printf("请输入你的ID号：");
	scanf("%d",&id);
	printf("\n");
	printf("请输入你的ID号的密码：");
	scanf("%d",&passwd);
	printf("\n");

	use.id = id;
	use.passwd = passwd;
	printf("id=%d\n",use.id);
	return id;
}	
