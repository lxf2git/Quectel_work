#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>

struct list{
	struct list *next, *prev;
};


#define offset(type, member) (unsigned long)&(((type *)0)->member)

//ptr:已知元素的地址
#define list_entry(ptr, type, member) ((type *)(((unsigned long)ptr) - (offset(type, member))))

#define list_declare(name) \
	struct list name = {.next=&name, .prev=&name}

#define list_each(node, head) for(node=(head->next); node!=head; node=(node->next)) 

void init_list(struct list *);
void list_add_tail(struct list *, struct list *);
void list_remove(struct list *);

#endif
