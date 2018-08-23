#include "stusys.h"

void init(pList pStusys)
{
	create_memory((void **)&pStusys->head, sizeof(sStu));

	pStusys->head->num = 0;
	pStusys->head->age = 0;
	pStusys->head->next = NULL;
	pStusys->head->pStu_input = Stu_input;
	pStusys->head->pStu_print = Stu_print;

	pStusys->pFun_stu[0] = Insert; 
//	pStusys->pInsert = Insert;
	pStusys->pIDFind = IDFind;
	pStusys->pInsertPosition = InsertPosition;
	
	pStusys->pFun_stu[1] = Del; 
	pStusys->pDelPosition = DelPosition;
//	pStusys->pDel = Del;
	
	pStusys->pFun_stu[2] = Search; 
//	pStusys->pSearch = Search;
	pStusys->pFun_search[0] = num_search;
	pStusys->pFun_search[1] = age_search;
	
	pStusys->pFun_stu[3] = Print; 
//	pStusys->pPrint = Print;

	pStusys->pFun_stu[4] = Save; 
	pStusys->pLoad = Load; 

	pStusys->pFun_stu[5] = Quit; 
	
}
