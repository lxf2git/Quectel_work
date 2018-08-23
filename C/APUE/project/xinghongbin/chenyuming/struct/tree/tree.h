#ifndef _TREE_H_
#define _TREE_H_

struct tree{
	struct tree *left, *right, *root;
};


#define offset(type, member) (unsigned long)&(((type *)0)->member)

//ptr:已知元素的地址
#define tree_entry(ptr, type, member) ((type *)(((unsigned long)ptr) - (offset(type, member))))

#define tree_declare(name) \
struct tree name = {.next=&name, .prev=&name}

#define tree_each(node, head) for(node=(head->next); node!=head; node=(node->next)) 

void init_tree(struct tree *);
void tree_add_left(struct tree *, struct tree *);
void tree_add_right(struct tree *, struct tree *);
void tree_remove_left(struct tree *);
void tree_remove_right(struct tree *);

#endif
