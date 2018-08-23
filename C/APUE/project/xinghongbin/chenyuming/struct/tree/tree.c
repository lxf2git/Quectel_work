#include "pub.h"

void init_tree(struct tree *node)
{
	node->left = NULL;
	node->right = NULL;
	node->root = NULL;
}


void tree_add_left(struct tree *node, struct tree *insert)
{
	insert->root = node;
	node->left = insert;
}

void tree_add_right(struct tree *node, struct tree *insert)
{
	insert->root = node;
	node->right = insert;
}

void tree_remove_left(struct tree *del)
{
	del->root->left = NULL;
	del->root = NULL;
	del->left = NULL;
	del->right = NULL;
}

void tree_remove_right(struct tree *del)
{
	del->root->right = NULL;
	del->root = NULL;
	del->left = NULL;
	del->right = NULL;
}
