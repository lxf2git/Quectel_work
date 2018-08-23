#include "stusys.h"

int Print(pList pStusys)
{
	pStu pHead = pStusys->head;
	
	if (pHead->next == NULL)
		printf("无学生信息!\n");

	else{
		printf("**打印信息**\n");
		printf("\n");
		while(1){
			pHead = pHead->next;
			pHead->pStu_print(pHead);

			if (pHead->next == NULL)
				break;
		}
		printf("**打印信息**\n");
		wait();
		return SUCCESS;
	}
}
