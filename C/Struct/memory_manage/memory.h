#ifndef MEMORY_H
#define MEMORY_H
struct memory
{
		int  mem_index;
		int  mem_size;
};
struct node 
{
		struct memory memory_node;
		struct node *next;
		struct node *prev;
};

struct tmp_chain
{
		struct node **data;
		struct tmp_chain *next;
		struct tmp_chain *prev;
}

#endif
