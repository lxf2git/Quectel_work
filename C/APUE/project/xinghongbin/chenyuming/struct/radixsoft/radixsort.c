#include "pub.h"

void radixsort(struct list *node_head)
{
	unsigned int max_num = find_max(node_head);
	int div_time = cal_time(max_num);
	int flag;
	int time;

	struct list radix_list[10];

	for(flag=0; flag<10; flag++){
		radix_list[flag].next=&radix_list[flag];
		radix_list[flag].prev=&radix_list[flag];
	}

	for(time=1; time<=div_time; time++){
		distribute(radix_list, node_head, time);
		collect(radix_list, node_head);
	}

}


unsigned int find_max(struct list *node_head)
{
	unsigned int max_tmp = list_entry(node_head->next, sData, _list)->data;
	unsigned int tmp;
	struct list *node_tmp;

	list_each(node_tmp, node_head){
		tmp = list_entry(node_tmp, sData, _list)->data;
		
		if (tmp > max_tmp)
			max_tmp = tmp;
	}

	return max_tmp;
}


int cal_time(unsigned int max_num)
{
	int time = 1;
	int div_tmp = 10;

	while(1){
		if (max_num%div_tmp==max_num)
			break;

		div_tmp*=10;
		time++;
	}

	return time;
}


void distribute(struct list *radix_list, struct list *node_head, int time)
{
	struct list *ergodic_node;
	unsigned int data_tmp;
	int insert_bit;

	list_each(ergodic_node, node_head){
		data_tmp = list_entry(ergodic_node, sData, _list)->data;
		insert_bit = sort_bit(time, data_tmp);
		sort_list_insert(radix_list, ergodic_node, insert_bit);
		ergodic_node = node_head;	
	}
}


int sort_bit(int time, unsigned int data_tmp)
{
	int div_tmp = 1;
	radix_div_sum(div_tmp, time);
	data_tmp = data_tmp/div_tmp;
	
	return (data_tmp%10);

}

void sort_list_insert(struct list *radix_list, struct list *node, int insert_bit)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;

	list_add_tail(&radix_list[insert_bit], node);
}



void collect(struct list *radix_list, struct list *node_head)
{
	int i;
	struct list *collect_tmp;

	for(i=0; i<10; i++){
		if (radix_list[i].next == &radix_list[i])
			continue;
		
		while(1){
			collect_tmp = radix_list[i].next;
			
			if (collect_tmp == &radix_list[i])
				break;
	
			list_remove(collect_tmp);
			list_add_tail(node_head, collect_tmp);
		}
	}
}
