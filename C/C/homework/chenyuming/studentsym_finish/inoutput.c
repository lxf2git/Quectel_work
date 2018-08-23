#include "stusys.h"

void Stu_input(pStu stu)
{
	printf("请输入学号:\n");
	scanf("%d", &stu->num);

	printf("请输入年龄:\n");
	scanf("%d", &stu->age);

	stu->next = NULL;

	stu->pStu_print = Stu_print;
	stu->pStu_input = Stu_input;
}

void Stu_print(pStu stu)
{
	printf("学号:%d\n", stu->num);
	printf("年龄:%d\n", stu->age);
	printf("\n");

}
