#include"main.h"

/*typedef struct node
{
	int id;
	char name[100];
	int age;
	struct node *next;
	
}sNode,*pNode;
*/
enum name
{
	input=1,
	find,
	save,
	print,
	quit
};



int main()
{
	pNode pHead;
	pNode pnew_head;
	int num;
	int choose;
	init_node(&pHead,sizeof(sNode));
	for(;;)
	{
	printf("1--------------输入学生信息\n");
	printf("2----------按年龄查找并输出\n");
	printf("3--------------保存学生信息\n");
	printf("4----------打印所有学生信息\n");
	printf("5----------------------退出\n");
	//show_chain(pHead);
	
		scanf("%d",&choose);
		switch(choose)
		{
			case input:
						insert_chain(pHead);
						break;		
			case find:
						find_age(pHead);
						break;
			case save:	
						save_file(pHead);
						break;
			case print:	
						print_information(pHead);
						break;
			case quit:
						return 0;
						break;
			default:		printf("error\n");
						break;
		}
	}
	main();
	//Destory_list(&pHead);
	return 0;
}