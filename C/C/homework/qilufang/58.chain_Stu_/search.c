#include"search.h"


int catch_1(int flog)
{
	int in=0;
	if(flog==1)
	{
		printf("请输入你查询的学生的Age\n");
		scanf("%d",&in);
		pStu stmp;
		stmp=pHead;
		while(stmp->next != NULL)
		{
			if(stmp->next->age==in)
			{
				printf("Name:%s Age:%d Id:%d\n",stmp->next->name,
							stmp->next->age,stmp->next->id);
			}
			stmp=stmp->next;
		}
		return 1;
	}
	else if(flog==2)
	{
		printf("请输入你查询的学生的Id\n");
		scanf("%d",&in);
		pStu stmp;
		stmp=pHead;
		while(stmp->next != NULL)
		{
			if(stmp->next->id==in)
			{
				printf("Name:%s Age:%d Id:%d\n",stmp->next->name,
							stmp->next->age,stmp->next->id);	
			}
			stmp=stmp->next;
		}
		return 1;
	}
	else
	{
		printf("你输入错误!\n");
		return;			
	}	
	return 0;
}
void catch()
{
	int ret;
	int in;
	printf("|输入1*******按年龄查询|**|输入2********按Id查询|\n");
	scanf("%d",&in);	
	ret=catch_1(in);
	if(ret==0)
	{
		printf("不存在满足条件的学生!\n");
	}
}

