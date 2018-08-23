#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleList{
	struct DoubleList *prev;
	struct DoubleList *next;
	size_t data;
	char *name;
}sList, *pList;

pList InitList();
void Insert(pList, char *, char *);
void Print(pList);
void *CreateMemory(size_t);
void Quit(pList);

int main(int argc, char **argv)
{
	pList pHead = InitList();
	int i;
	
	for(i=1; i<argc; i+=2){
		Insert(pHead, argv[i], argv[i+1]);
	}
	Print(pHead);
	Quit(pHead);

	pHead->next = NULL;
	pHead->prev = NULL;
	free(pHead);
	
	return 0;
}


pList InitList()
{
	pList list_tmp = (pList)CreateMemory(sizeof(sList));
	
	list_tmp->data = 0;
	list_tmp->prev = list_tmp;
	list_tmp->next = list_tmp;

	return list_tmp;
}


void Insert(pList pHead, char *name_tmp, char *str)
{
	int i;
	pList insert_tmp = InitList();
	pList flag_tmp = pHead;
	int id_tmp = atoi(str);

	//	printf("输入数据.\n");
	//	scanf("%d", &insert_tmp->data);
	insert_tmp->name = name_tmp;
	insert_tmp->data = id_tmp;

	while(1){
		flag_tmp = flag_tmp->next;

		if (flag_tmp->data > insert_tmp->data){
			insert_tmp->prev = flag_tmp->prev;
			insert_tmp->next = flag_tmp;
			flag_tmp->prev->next = insert_tmp;
			flag_tmp->prev = insert_tmp;
			break;
		}
		
		if (flag_tmp->next == pHead){
			insert_tmp->prev = flag_tmp;
			insert_tmp->next = pHead;
			flag_tmp->next = insert_tmp;
			break;
		}
	}

}

void Print(pList pHead)
{
	pList print_tmp = pHead;
	
	printf("打印.\n");
	while(1){
		print_tmp = print_tmp->next;
		
		printf("%s\n", print_tmp->name);
		printf("%d\n", print_tmp->data);
		
		if (print_tmp->next == pHead)
			break;
	}


}


void *CreateMemory(size_t size)
{
	return malloc(size);
}


void Quit(pList pHead)
{
	pList free_tmp;

	while(1){
		free_tmp = pHead->next;

		pHead->next = free_tmp->next;
		free_tmp->next = NULL;
		free_tmp->prev = NULL;
		free(free_tmp);

		if (pHead->next == pHead)
			break;
	}
}
