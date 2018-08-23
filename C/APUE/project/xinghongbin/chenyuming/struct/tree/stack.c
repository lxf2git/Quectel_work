#include "pub.h"

#define EMPTY 1
#define NOEMPTY 0

pStack InitStack()
{
	pStack stack = calloc(1, sizeof(sStack));

	stack->size = 0;
	stack->top = &stack->_list;
	init_list(&stack->_list);
	return stack;
}


void Push(pStack stack, struct list *push_node)
{
	stack->top = push_node;
	stack->size++;
	list_add_tail(&stack->_list, push_node);
}


struct list *Pop(pStack stack)
{
	struct list *pop_node = stack->top;
	list_remove(pop_node);
	stack->top = stack->_list.prev;
	stack->size--;
	return pop_node;
}


unsigned char IsEmpty(pStack stack)
{
	if (stack->size == 0){
		return EMPTY;
	}
	return NOEMPTY;
}
