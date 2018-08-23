#include"main.h"

int main()
{
	int i,in=0;
	init_Stu(&pHead,sizeof(sStu));
	for(i=0;;i++)
	{
		printf("<1>*************输入学生信息\n");
		printf("<2>*************查找学生信息\n");
		printf("<3>*************保存所有学生信息\n");
		printf("<4>*************打印所有学生信息\n");
		printf("<5>*************退出\n");
		printf("输入你选择的服务：\n");
		scanf("%d",&in);
		switch(in)
		{
			case INPUT : make_chain(); break;
			case CATCH : catch(); break;
			//case SAVE : save(); break;
			case PRINTF : output(pHead); break;
			case EXIT : exit(0);
			default : printf("请重新输入：\n"); break;
		}
	}
	return 0;
}
