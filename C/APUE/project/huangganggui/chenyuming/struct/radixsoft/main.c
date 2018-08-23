#include "pub.h"

static list_declare(data_head);


void InsertData(struct list *, char *);
void PrintData(struct list *);
void Quit(struct list *);

int main(int argc, char *argv[])
{
	int i;

	for(i=1; i<argc; i++){
		InsertData(&data_head, argv[i]);
	}

	printf("排序前:\n");
	PrintData(&data_head);

	radixsort(&data_head);

	printf("排序后:\n");
	PrintData(&data_head);

	Quit(&data_head);

	return 0;
}

void InsertData(struct list *list_head, char *data)
{
	pData insert_tmp = calloc(1, sizeof(sData));
	insert_tmp->data = atoi(data);

	init_list(&insert_tmp->_list);
	list_add_tail(&data_head, &insert_tmp->_list);
}

void PrintData(struct list *list_head)
{
	struct list *print_tmp;
	 pData data_tmp;

	list_each(print_tmp, list_head){
		data_tmp = list_entry(print_tmp, sData, _list);
		printf("%u ", data_tmp->data);
	}
	printf("\n");
}

void Quit(struct list *list_head)
{
	struct list *free_tmp;

	list_each(free_tmp, list_head){
		list_remove(free_tmp);
		free(list_entry(free_tmp, sData, _list));
		free_tmp = list_head->next;
	}

}
