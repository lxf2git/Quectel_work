#include"main.h"

int main()
{
	int i,in=0;
	init_Stu(&pHead,sizeof(sStu));
	for(i=0;;i++)
	{
		printf("<1>*************输入学生信息\n");
		printf("<2>*************删除学生信息\n");
		printf("<3>*************查找学生信息\n");
		printf("<4>*************打印所有学生信息\n");
		printf("<5>*************保存所有学生信息\n");
		printf("<6>*************退出\n");
		printf("输入你选择的服务：\n");
		scanf("%d",&in);
		switch(in)
		{
			case INSERT : input_chain(); break;
			case DEL : del(); break;
			case SEARCH :catch(); break;
			case PRINT : put_chain(); break;
			case SAVE : save(); break;
			case EXIT : exit(0);
			default : printf("请重新输入：\n"); break;
		}
	}
	return 0;
}
