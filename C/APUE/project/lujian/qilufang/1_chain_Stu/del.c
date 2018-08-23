#include"del.h"
void del(pStu pHead,sList slist)
{
	slist.pDel=del_1;
	slist.pDel(pHead,catch_1);
}
pStu catch_1(pStu pHead, int age)
{
	pStu stmp=pHead;
	while(stmp->next != NULL)
	{
		if(stmp->next->age==age)
		{
			return stmp;
		}
		stmp=stmp->next;
	}
	return NULL;
}
int del_1(pStu pHead, pStu (*pDelPosition)(pStu pHead, int age))
{
	int age;
	printf("请输入你删除学生的Age:\n");
	scanf("%d",&age);
	pStu del;
	pStu position = pDelPosition(pHead,age);
	if(position==NULL)
	{
		printf("你输入的学生年龄不存在！\n");
	}
	else
	{
		del=position->next;
		position->next=position->next->next;
		destory(del);

	}
}
