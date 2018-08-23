#include "pub.h"

void init_list(struct list *node)
{
	node->next = node;
	node->prev = node;
}


void list_add_tail(struct list *head, struct list *insert)
{
	insert->next = head;
	insert->prev = head->prev;
	head->prev->next = insert;
	head->prev = insert;
}


void list_add_head(struct list *head, struct list *insert)
{
	insert->next = head->next;
	insert->prev = head;
	head->next->prev = insert;
	head->next = insert;
}


void list_remove(struct list *del)
{
	del->next->prev = del->prev;
	del->prev->next = del->next;
	del->next = NULL;
	del->prev = NULL;
}
