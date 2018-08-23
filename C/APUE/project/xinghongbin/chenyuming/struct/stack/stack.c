#include "pub.h"

struct list *InitStack()
{
	pStack *stack = calloc(1, sizeof(sStack));

	stack->size = 0;
	stack->top = stack;
	init_list(&stack->_list);
	return &stack->_list;
}


void Push(struct list *stack, struct list *push_node)
{
	list_entry(stack, sStack, _list)->top = push_node;
	list_entry(stack, sStack, _list)->size++;
	list_add_tail(stack, push_node);
}


struct list *Pop(struct list *stack)
{
	struct list *pop_node = list_entry(stack, sStrack, _list)->top;
	list_entry(stack, sStack, _list)->top = pop_node->next;
	list_remove(pop_node);
	return pop_node;
}
