#include "stusys.h"

int Save(pList pStusys)
{
	
	FILE *save_file;
	pStu pHead = pStusys->head;
	char file_name[SIZE_CHAR];

	printf("请输入要保存的文件名.\n");
	scanf("%s", file_name);

	save_file = fopen(file_name, "w+");
	if(NULL == save_file){
		printf("文件打开失败！\n");
		return FAIL;
	}

	while(1){
		pHead = pHead->next;

		if (NULL == pHead)
			break;

		fwrite(&pHead->num, 4, 1, save_file);
		fwrite(&pHead->age, 4, 1, save_file);
	}

	fclose(save_file);
	printf("保存成功!\n");
	return SUCCESS;
}

int Load(pList pStusys)
{
	char file_name[SIZE_CHAR];
	pStu pHead = pStusys->head;
	FILE *load_file;
	size_t value;

	printf("请输入载入的文件名\n");
	scanf("%s", file_name);

	if (!strcmp(file_name, "NO")){
		return SUCCESS;
	}

	load_file = fopen(file_name, "r");
	if (NULL == load_file){
		printf("文件载入失败.\n");
		return FAIL;
	}

	while(!feof(load_file)){
		value = create_memory((void **)&pHead->next, sizeof(sStu));
		if (value == FAIL)
			return value;
	
		pHead = pHead->next;
		fread(&pHead->num, 4, 1, load_file);
		fread(&pHead->age, 4, 1, load_file);
		pHead->pStu_print = Stu_print;
		pHead->pStu_input = Stu_input;
		pHead->next =NULL;
	}
	
	pHead = pStusys->head;

	while(1){
		pHead = pHead->next;

		if (pHead->next->next == NULL){
			free(pHead->next);
			pHead->next = NULL;
			break;
		}
	}

	fclose(load_file);
	printf("读取成功.\n");
	return SUCCESS;
}
