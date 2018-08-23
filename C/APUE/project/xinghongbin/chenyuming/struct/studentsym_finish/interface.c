#include "stusys.h"

int interface()
{
	int flag = 0;
		
	printf("***********************************\n");
	printf("	学生信息管理系统\n");
	printf("\n");
	printf("	1.插入学生信息\n");
	printf("	2.删除学生信息\n");
	printf("	3.查询学生信息\n");
	printf("	4.打印学生信息\n");
	printf("	5.保存学生信息\n");
	printf("	6.退出");
	printf("\n");
	printf("***********************************\n");
	printf("\n");

	printf("请选择操作:\n");
	
	while(1){
		scanf("%d", &flag);

		if (flag>=1 && flag<=6){
			break;
		}
		else{
			printf("选择有误，请重新输入\n");
		}
	}
	
	return flag;
}
