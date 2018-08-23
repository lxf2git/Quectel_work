#include"main.h"
#include"insert.h"
#include"del.h"
#include"print.h"
#include"save.h"
#include"search.h"
#include"creat.h"

int main()
{
	FILE *fd=NULL;
	pStu pHead=NULL;
	init_stu(&pHead,sizeof(sStu));
	menu(pHead,fd);
	destory(&pHead);
	return 0;
}

int menu(pStu pHead,FILE *fd)
{	
	int n;
	file_chain_insert(pHead,fd);
	pStu pnew=NULL;
	int (*pf[2])(pStu,int)={find_id,find_age};
	sList fun={pHead,pInsert,pDel,pPrint,pSearch,pStu_Save};
	do
	{
		printf("请选择功能：\n");
		printf("******1:INSERT*****：\n");
		printf("******2:DEL********：\n");
		printf("******3:SEARCH*****：\n");
		printf("******4:PRINT******：\n");
		printf("******5:SAVE*******：\n");
		printf("******6:EXIT*******：\n");
		scanf("%d",&n);
		switch(n)
		{
			case INSERT:
				init_stu(&pnew,sizeof(sStu));
				fun.pInsert(pHead,pnew,pidfind,pinsertposition);
				break;
			case DEL:
				fun.pDel(pHead,pdelp);
				break;
			case SEARCH:
				fun.pSearch(pHead,pf);
				break;
			case PRINT:
				fun.pPrint(pHead);
				break;
			case SAVE:
				fun.pStu_Save(pHead,fd);
				break;
			case EXIT:
				return 0;
				break;
			default:
				break;
		}
	}while(n>=INSERT||n<=EXIT);
}
