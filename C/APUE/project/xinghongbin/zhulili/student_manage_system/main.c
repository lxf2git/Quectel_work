#include"main.h"
enum name
{
	input=1,
	delete,
	print,
	search,
	save,
	quit
};
int main()
{
	int choose;
	pList plist = NULL;
	init_node(&plist,sizeof(sList));
	init_node_pstu(&(plist->head),sizeof(sStu));
	plist->head->stu_input = stu_input;
	plist->head->stu_print = stu_print;
	plist->pInsert = pinsert;
	plist->pDel = pdel;
	plist->pPrint = pPrint;
	plist->pSearch = pSearch;
	plist->pStu_Save = pStu_Save;
	for(;;)
	{
		
		printf("请选择\n");
		printf("1------------添加学生信息 \n");
		printf("2------------删除学生信息 \n");
		printf("3------------打印学生信息 \n");
		printf("4------------搜索学生信息 \n");
		printf("5------------保存学生信息 \n");
		printf("6------------退出管理系统 \n");
		scanf("%d",&choose);		
		switch(choose)
		{
		
			case input:
					stu_input(plist->head);
					break;			
			case delete:
					delete_node(plist->head);
					break;
			case print:
					stu_print(plist->head);
					break;
			case search:
					find(plist->head);
					break;	
			case save:
					save_list(plist->head);
					break;
			case quit:
					return 0;
					break;
		}
	}			
	return 0;
}
