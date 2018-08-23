#include"search.h"
#include"mian.h"

void catch()
{
	int ret;
	ret=catch_1();
	if(ret==0)
	{
		printf("你输入的名字不存在\n");
	}
}
int catch_1()
{
	char str[20];
	printf("请输入你查询的学生的Name\n");
	getchar();
	gets(str);
	pStu stmp;
	stmp=pHead;
	while(stmp->next != NULL)
	{
		if(strcmp(stmp->next->name,str)==0)
		{
			printf("Name:%s Age:%d Id:%d\n",stmp->next->name,
						stmp->next->age,stmp->next->id);
			return 1;
		}
		stmp=stmp->next;
	}
	return 0;
}
