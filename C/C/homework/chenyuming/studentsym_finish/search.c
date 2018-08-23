#include "stusys.h"

int Search(pList pStusys)
{
	int search_way = 0;

	while(1){
		printf("******查询******\n");
		printf("请输入查询方式\n");
		printf("1.按学号查找\n");
		printf("2.按年龄查找\n");
		printf("3.退出\n");
		printf("******查询******\n");

		while(1){
			scanf("%d", &search_way);

			if (search_way==1 || search_way==2 || search_way==3)
				break;
			else 
				printf("输入有误,请重新输入\n");
		}
		
		if (search_way == 3)
			break;

		pStusys->pFun_search[search_way-1](pStusys->head);

		return SUCCESS;
	}
}

int num_search(pStu pHead)
{
	unsigned int search_num = 0;
	
	printf("请输入要查询的学号\n");
	scanf("%d", &search_num);
	
	while(1){
		pHead = pHead->next;

		if (pHead == NULL){
			printf("无此学生!\n");
			wait();
			return NOFIND;	
		}

		if (pHead->num == search_num){
			pHead->pStu_print(pHead);
			wait();
			return FIND;
		}
	}

}


int age_search(pStu pHead)
{
	int search_age = 0;
	int sum_search = 0;

	printf("请输入要查询的年龄\n");
	scanf("%d", &search_age);
	
	while(1){
		pHead = pHead->next;

		if (pHead == NULL)
			break;

		if (pHead->age == search_age){
			pHead->pStu_print(pHead);
			sum_search++;
		}
	}
	
	if (sum_search == 0){
		printf("未查找倒符合年龄的学生.\n");
		wait();
		return NOFIND;
	}
	else{
		printf("一共查找倒%d个学生.\n", sum_search);
		wait();
		return FIND;
	}
}
