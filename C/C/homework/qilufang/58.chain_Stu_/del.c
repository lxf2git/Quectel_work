#include"del.h"
void del()
{
	int ret;
	ret=catch_2();
	if(ret==0)
	{
		printf("你输入的名字不存在\n");
	}
}
int catch_2()
{
	char str[20];
	printf("请输入你删除学生的Name\n");
	getchar();
	gets(str);
	pStu stmp;
	pStu del;
	stmp=pHead;
	while(stmp->next != NULL)
	{
		if(strcmp(stmp->next->name,str)==0)
		{
			del=stmp->next;
			stmp->next=del->next;
			del->next=NULL;
			free(del);
			return 1;
		}
		stmp=stmp->next;
	}
	return 0;
}
