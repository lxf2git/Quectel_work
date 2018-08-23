#include"main.h"

int main()
{
		pStu pHead=NULL;
		pHead=create_node();
		init(pHead);
		menu(pHead);
		return 0;
}

int menu(pStu pHead)
{
		int function;
		while(1)
		{
				printf("-----------------\n");
				printf("|   1、插入     |\n");
				printf("|   2、删除     |\n");
				printf("|   3、查找     |\n");
				printf("|   4、打印     |\n");
				printf("|   5、保存     |\n");
				printf("|   6、退出     |\n");
				printf("-----------------\n");
				printf("    请选择功能:\n");
				scanf("%d",&function);
				if(-1==judge(function,pHead))
				{
						break;
				}
		}
		return 0;
}
int judge(int function,pStu pHead)
{
		switch(function)
		{
				case INSERT:
						insert(pHead);
						break;
				case DEL:
						del(pHead);
						break;
				case SEARCH:
						search(pHead);
						break;
				case PRINT:
						fun.pPrint(pHead);
						break;
				case SAVE:
						save(pHead);
						break;
				case EXIT:
						return -1;
						break;
				default:
						printf("输入错误!\n");
						break;
		}
		return 0;
}
