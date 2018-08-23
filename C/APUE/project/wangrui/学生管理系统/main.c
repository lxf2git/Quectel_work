#include"main.h"

enum function
{
	insert=1,
	del,
	search,
	print,
	save,
	quit
};

int main()
{
	pList p = NULL;
	init_node_p(&p,sizeof(sList));
	pStu ps = NULL;
	init_node(&ps,sizeof(sStu));
	p->head = NULL;
	init_node_p(&(p->head),sizeof(sList));

	ps->stu_print = stu_print;
	ps->stu_input = stu_input;

	p->pInsert = pInsert;
	p->pDel = pDel;
	p->pPrint = pPrint;
	p->pSearch = pSearch;
	p->pStu_Save = pStu_Save;
	printf("**********欢迎使用本系统**********\n");
	int choose;
	for(;;){
			printf("********1--插入学生信息***********\n");
			printf("********2--删除学生信息***********\n");
			printf("********3--查找学生信息***********\n");
			printf("********4--输出学生信息***********\n");
			printf("********5--保存学生信息***********\n");
			printf("********6----退出本程序***********\n");
			printf("------------请选择功能------------\n");
			scanf("%d",&choose);
			if(choose<1||choose>6){
					printf("功能选择有误，请重新选择功能\n");
					main();
			}
			switch(choose)
			{
				case insert:
							ps->stu_input(p->head);
							break;
				case del:
							del_chain(p->head);
							break;
				case search:
							search_chain(p->head);
							break;
				case print:
							p->pPrint(p->head);
							break;
				case save:
							save_chain(p->head->next);
							break;
				case quit:
							return 0;
			}
			}
	return 0;
}
