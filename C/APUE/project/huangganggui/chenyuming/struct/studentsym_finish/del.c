#include "stusys.h"

int Del(pList pStusys)
{
	unsigned int del_num = 0;
	unsigned char exist_flag;
	pStu del_note = NULL;
	pStu del_note_tmp = NULL;

	printf("请输入要删除学生的学号\n");
	scanf("%d", &del_num);

	exist_flag = pStusys->pIDFind(pStusys->head, del_num);
	if (exist_flag == NOFIND){
		printf("不存在此学生\n");
		wait();
		return NOFIND;
	}

	del_note = pStusys->pDelPosition(pStusys->head, del_num);

	del_note_tmp = del_note->next->next;
	del_note->next->next = NULL;
	free(del_note->next);
	del_note->next = del_note_tmp;
	printf("删除成功!\n");
	wait();
	return SUCCESS;
}


pStu DelPosition(pStu pHead, unsigned int del_num)
{

	while(1){
		if(pHead->next->num == del_num){
			return pHead;
		}
		pHead = pHead->next;
	}
}
