#include"find_age.h"

void  find_age(pNode p)
{
	int Age,flag=0;
	pNode pTrav = p;
	printf("请输入年龄进行查找：");
	scanf("%d",&Age);
	while(pTrav->next!=NULL)
	{	
		if(pTrav->next->age == Age)
		{
			printf("匹配的学生信息：\n");
			printf("id:%d  name:%s  age:%d\n",pTrav->next->id,pTrav->next->name,pTrav->next->age);
			flag = 1;
		}		
		pTrav = pTrav->next;			
	}
	if(flag == 0)
			printf("没有匹配的信息\n");
}
