#include"init.h"
void create_memory(pStu *p,int size)
{
		*p = (pStu)malloc(size);
		if(NULL==*p)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}

void init_Node(pStu *p,int size)
{
		create_memory(p,size);
		(*p)->age=0;
		(*p)->next=NULL;
		(*p)->stu_print = stu_out;
		(*p)->stu_input = stu_in;
}

void create_lmemory(pList *p,int size)
{
		*p = (pList)malloc(size);
		if(NULL==*p)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}

void init_list(pList *plist, int size)
{
		create_lmemory(plist,size);
		(*plist)->head = NULL;
		(*plist)->pInsert = Insert;
		(*plist)->pDel = Del;
		(*plist)->pPrint = Print;
		(*plist)->pSearch = Search;
		(*plist)->pStu_Save = Stu_Save;
}
