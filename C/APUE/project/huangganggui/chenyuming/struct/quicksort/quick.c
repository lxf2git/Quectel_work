#include "pub.h"

void quicksort(struct list *data_head)
{
	struct list *low_flag, *high_flag;
	low_flag = data_head->next;
	high_flag = data_head->prev;
	
	sort_fun(data_head, low_flag, high_flag);
	
}

struct list *sort_swap(struct list *low_flag, struct list *high_flag)
{
	unsigned int swap_tmp;
	
	while (low_flag!=high_flag){
		while(low_flag!=high_flag){
			if (list_entry(low_flag, sData, _list)->data > list_entry(high_flag, sData, _list)->data){
				swap_tmp = list_entry(low_flag, sData, _list)->data;
				list_entry(low_flag, sData, _list)->data = list_entry(high_flag, sData, _list)->data;
				list_entry(high_flag, sData, _list)->data = swap_tmp;
				low_flag = low_flag->next;
				break;
			}
			high_flag = high_flag->prev;
		}

		while(low_flag!=high_flag){
			if (list_entry(low_flag, sData, _list)->data > list_entry(high_flag, sData, _list)->data){
				swap_tmp = list_entry(low_flag, sData, _list)->data;
				list_entry(low_flag, sData, _list)->data = list_entry(high_flag, sData, _list)->data;
				list_entry(high_flag, sData, _list)->data = swap_tmp;
				high_flag = high_flag->prev;
				break;
			}
			low_flag = low_flag->next;
		}
	}
}


void sort_fun(struct list *data_head, struct list *low_flag, struct list *high_flag)
{
	struct list *sort_key;
		
	if (low_flag!=data_head && high_flag!=data_head && low_flag<high_flag){
		sort_key = sort_swap(low_flag, high_flag);
		
		sort_fun(data_head, low_flag, sort_key->prev);
		sort_fun(data_head, sort_key->next, high_flag);
	}
}
