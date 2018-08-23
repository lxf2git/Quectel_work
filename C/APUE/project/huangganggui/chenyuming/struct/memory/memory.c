#include "pub.h"

void init_memory_list(struct list *list_head)
{
	int index;
	pData init_node;

	for(index=0; index<10; index++){
		init_node = calloc(1, sizeof(sData));
		init_node->size = 10;
		init_node->start_add = calloc(1, 10);
		init_node->end_add = init_node->start_add + 9;
		list_add_tail(list_head, &init_node->_list);
	}
}


void PrintData(struct list *list_head)
{
	struct list *print_node;
	pData data_node;

	list_each(print_node, list_head){
		
		data_node = list_entry(print_node, sData, _list);
		printf("(%d) start:%p end:%p\n", 
				data_node->size, 
				data_node->start_add, data_node->end_add);
	}
}



void ApplyMemory(struct syslist *sys_list)
{
	unsigned int apply_size;
	unsigned int sum_size;
	pRecordHead new_record_head;
	struct list *each_node;

	printf("请输入要申请的空间大小\n");
	scanf("%d", &apply_size);
	
	list_each(each_node, sys_list->apply_list){
		sum_size += list_entry(each_node, sData, _list)->size;		
	}

	if (apply_size > sum_size){
		printf("内存不足.\n");
		return ;
	}


	
	new_record_head = calloc(1, sizeof(sRecordHead));
	new_record_head->record_index = record_index++;
	list_add_tail(sys_list->record_list, &new_record_head->_list);
	new_record_head->record_list.next = &new_record_head->record_list;
	new_record_head->record_list.prev = &new_record_head->record_list;


	Fun_apply(sys_list, apply_size);
}


void Fun_apply(struct syslist *sys_list, unsigned int apply_size)
{
	struct list *max_node = find_max_size(sys_list->apply_list);
	
	if (apply_size <= list_entry(max_node, sData, _list)->size){
		Fun_apply_low(sys_list, apply_size, max_node);
		return ;
	}	
	
	if (apply_size > list_entry(max_node, sData, _list)->size){
		Fun_apply_high(sys_list, apply_size);
		return ;
	}
}

void Fun_apply_low(struct syslist *sys_list, unsigned int apply_size, struct list *max_node)
{
	struct list *equal_node = find_equal_size(sys_list->apply_list, apply_size);
	pRecordHead record_head = list_entry((sys_list->record_list->prev), sRecordHead, _list);
	pRecordNode record_node = calloc(1, sizeof(sRecordNode));
	pData new_node;

	if (NULL==equal_node){
		new_node = calloc(1, sizeof(sData));
		new_node->size = apply_size;
		new_node->start_add = list_entry(max_node, sData, _list)->start_add;
		new_node->end_add = list_entry(max_node, sData, _list)->start_add+apply_size-1;
		InsertFreeList(sys_list->free_list, new_node);
		list_entry(max_node, sData, _list)->start_add += apply_size;
		list_entry(max_node, sData, _list)->size -= apply_size;

		if (list_entry(max_node, sData, _list)->size == 0){
			list_remove(max_node);
			free(list_entry(max_node, sData, _list));
		}
		
		record_node->address = &new_node->_list;
		list_add_tail(&record_head->record_list, &record_node->_list);
	}

	else{
		list_remove(equal_node);
		InsertFreeList(sys_list->free_list, list_entry(equal_node, sData, _list));
		record_node->address = equal_node;
		list_add_tail(&record_head->record_list, &record_node->_list);
	}
}



void InsertFreeList(struct list *free_list, pData insert_node)
{
	struct list *ergodic_node;

	if (free_list->next == free_list){
		list_add_tail(free_list, &insert_node->_list);
		return ;
	}
	
	list_each(ergodic_node, free_list){
		if (list_entry(ergodic_node, sData, _list)->size > insert_node->size){
			list_add_head(ergodic_node->prev, &insert_node->_list);
			return ;
		}
	}
	list_add_tail(free_list, &insert_node->_list);
}


void Fun_apply_high(struct syslist *sys_list,  unsigned int apply_size)
{
	struct list *max_node = find_max_size(sys_list->apply_list);
	
	apply_size = apply_size - list_entry(max_node, sData, _list)->size;
	Fun_apply(sys_list, list_entry(max_node, sData, _list)->size);
	Fun_apply(sys_list, apply_size);

}	



struct list *find_max_size(struct list *list_head)
{
	struct list *max_node = list_head->next;
	struct list *find_node;

	list_each(find_node, list_head){
		if (list_entry(find_node, sData, _list)->size > 
				list_entry(max_node, sData, _list)->size)
			max_node = find_node;
	}
	return max_node;
}


struct list *find_equal_size(struct list *list_head, unsigned int apply_size)
{
	struct list *find_node;

	list_each(find_node, list_head){
		if (list_entry(find_node, sData, _list)->size == apply_size)
			return find_node;
	}
	return NULL;
}


void FreeMemory(struct syslist *sys_list)
{
	unsigned int free_num;
	struct list *record_free;
	printf("请输入销毁的序号.\n");
	scanf("%d", &free_num);

	list_each(record_free, sys_list->record_list){
		if (list_entry(record_free, sRecordHead, _list)->record_index == free_num){
			free_fun(sys_list, list_entry(record_free, sRecordHead, _list));
			return ;
		}
	}
		printf("无此序号申请内存.\n");
}


void free_fun(struct syslist *sys_list, pRecordHead record_free)
{
	struct list *free_node;
	list_each(free_node, (&record_free->record_list)){
		list_remove(list_entry(free_node, sRecordNode, _list)->address);
		list_add_tail(sys_list->apply_list, list_entry(free_node, sRecordNode, _list)->address);
		list_remove(free_node);
		free(list_entry(free_node, sRecordNode, _list));
		free_node = &record_free->record_list;
	}
}
