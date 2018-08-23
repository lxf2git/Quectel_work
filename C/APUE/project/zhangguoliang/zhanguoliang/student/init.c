#include"init.h"

void init_stu(pStu *p)
{
	*p=(pStu)malloc(sizeof(sStu));
	(*p)->age=0;
	(*p)->next=NULL;
	(*p)->stu_print=sprint;
	(*p)->stu_input=sinput;
}

void init_list(pList *p)
{
	(*p)=(pList)malloc(sizeof(sList));
	(*p)->Head=pHead;
	(*p)->pInsert=Insert;
	(*p)->pDel=Del;
	(*p)->pPrint=Print;
	(*p)->pSearch=Search;
	(*p)->pStu_Save=Save;
}
