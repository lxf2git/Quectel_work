#include"main_st.h"
#include"insert.h"
#include"search.h"
#include"delete.h"
#include"interface.h"
#include"init.h"
#include"save.h"

void interface()
{
	printf("--------------------------------------------\n");
	printf("---------------请选择功能-------------------\n");
	printf("---------------1:插入一个学生---------------\n");
	printf("---------------2:删除一个学生---------------\n");
	printf("---------------3:查找学生信息---------------\n");
	printf("---------------4:输出学生信息---------------\n");
	printf("---------------5:保存信息-------------------\n");
	printf("---------------6:退出程序-------------------\n");
	printf("--------------------------------------------\n");
}

void search_face()
{
	printf("-------------------------------------------\n");
	printf("---------------请选择查找方法--------------\n");
	printf("---------------1:按年龄查找----------------\n");
	printf("---------------2:按id查找------------------\n");
	printf("-------------------------------------------\n");
}
void choose(sList sFun, pStu pin)
{
	int num;
	int serc;
	pStu phead = sFun.phead;

	sFun.pInsert = insert;
	sFun.pDel = del;
	sFun.pSearch = search;
	sFun.pPrint = print;
	sFun.pStu_Save = save;

	FILE *fp;
	load(phead,fp);
					(sFun.pPrint)(phead);
	int chos1,chos2,chos3,chos4,chos5,chos6;//接受选择的功能是否成功
	interface();
	printf("请选择：");
	scanf("%d",&num);
	while(num != EXIT)
	{
	switch(num)
	{
		case INSERT:
				{
					pin = pfun_in();
					printf("pfun_in--->after!\n");
//	pidfind=find_id;
//	pinposite = posite_in;
					chos1 = (sFun.pInsert)(phead,
											pin,
											find_id,
											posite_in
											);
					printf("sFun--->after\n");
					judge(chos1);
					break;
				}
		case DELETE:
				{
					chos2 = (sFun.pDel)(phead, del_age);
					judge(chos2);
					break;
				}
		case SEARCH:
				{
					search_face();
					chos3 = (sFun.pSearch)(phead,fun_sear);
					judge(chos3);
					break;
				}
		case PRINT:
				{
					(sFun.pPrint)(phead);
					chos4 = SUC;
					judge(chos4);
					break;
				}
		case SAVE:
				{
					chos5 = (sFun.pStu_Save)(phead,fp);
					judge(chos5);
					break;
				}
		case EXIT:
				{
					exit_my(&phead);
					break;
				}
		default:
				{
					printf("input error\n");
				}
	}
	interface();
	printf("请选择：");
	scanf("%d",&num);
	}
}

void judge(int n)
{
	if(n == 0)
	{
		printf("success!\n");
	}
	else if(n == -1)
	{
		printf("failed!\n");
	}
}

int main()
{
//	interface();
	pStu pin=NULL;
	FILE * fp=NULL;

	sList sFun;
	init_node(&sFun.phead,sizeof(sStu));

	choose(sFun, pin);
	return 0;
}
