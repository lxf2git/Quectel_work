#include "stusys.h"

int Insert(pList pStusys)
{
	unsigned char value;
	unsigned char id_exist;
	pStu insert_pos = NULL;
	pStu insert_node = NULL;
	
	value = create_memory((void **)&insert_node, sizeof(sStu));
	if (value == FAIL)
		return value;
	
	pStusys->head->pStu_input(insert_node);
	
	id_exist = pStusys->pIDFind(pStusys->head, insert_node->num);

	if (id_exist == FIND){
		printf("此ID已存在！\n");
		free(insert_node);
		wait();
		return EXIST;
	}



	if (id_exist == NOFIND){
		insert_node->pStu_print = Stu_print;
		insert_node->pStu_input = Stu_input;

		insert_pos = pStusys->
			pInsertPosition(pStusys->head, insert_node);
	}

	
	
	insert_node->next = insert_pos->next;
	insert_pos->next = insert_node;
	printf("插入成功!\n");
	wait();

	return SUCCESS; 		
		
}


int IDFind(pStu pHead, unsigned int num)
{
	
	while(1){
		if (pHead->num == num)
			return FIND;
		
		if (pHead->next ==NULL)
			return NOFIND;
		
		pHead = pHead->next;
		
	}

}


pStu InsertPosition(pStu pHead, pStu insert_node)
{
	while(1){

		if (pHead->next == NULL){
			return pHead;
		}

		if (insert_node->num < pHead->next->num){
			return pHead;
		}
		pHead = pHead->next;
	
	}
}
