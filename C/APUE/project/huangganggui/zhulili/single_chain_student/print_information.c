#include"print_information.h"

void print_information(pNode pHead)
{
	pNode ptmp = NULL;
	printf("打印学生信息:\n");
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		
		printf("id：%d  姓名：%s  年龄：%d \n",ptmp->id,ptmp->name,ptmp->age);
	}
	printf("\n");
}
