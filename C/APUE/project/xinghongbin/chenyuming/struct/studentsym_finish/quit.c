#include "stusys.h"

int Quit(pList pStusys)
{
	pStu free_tmp = NULL;
	int i;
	
	if (pStusys->head->next != NULL){
		while(1){
			free_tmp = pStusys->head->next;
			pStusys->head->next = free_tmp->next;
			free_tmp->pStu_print = NULL;
			free_tmp->pStu_input = NULL;
			free(free_tmp);
			
			if (pStusys->head->next == NULL){
				break;
			}
		}
	}
	free(pStusys->head);
	pStusys->pIDFind = NULL;
	pStusys->pInsertPosition = NULL;
	pStusys->pDelPosition = NULL;
	pStusys->pLoad = NULL;

	for (i = 0; i < 5; i++)
		pStusys->pFun_stu[i] = NULL;

	pStusys->pFun_search[0] = NULL;
	pStusys->pFun_search[1] = NULL;
}
