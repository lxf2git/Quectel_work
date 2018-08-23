#include "pub.h"

void CreateTree(struct tree *root, char *data)
{
	int index;
	struct tree **root_tree = &root->left;

	Push_tree(root);

	for(index=0; data[index]!='\0'; index++){
		if (data[index]!='-'){
			*root_tree = AddTreeNode(data[index]);
			Push_tree(*root_tree);
			root_tree = &(*root_tree)->left;
			continue;
		}
	
		if (root_tree == &root->right)
			break;

		root_tree = &(list_entry(stack->top, sTree_stack, _list)->_tree->right);
		Pop_tree();
	}
}


struct tree *AddTreeNode(char data)
{
	pTreeNode add_node = calloc(1, sizeof(sTreeNode));
	init_tree(&add_node->_tree);
	add_node->data = data;
	return &add_node->_tree;
}


void DLR_tree(struct tree *root)
{
	struct tree *root_tree = root;

	while(root_tree!=NULL || stack->size!=0){
		if (root_tree!=NULL){
			PrintTreeNode(root_tree);
			Push_tree(root_tree);
			root_tree = root_tree->left;
			continue;
		}
		root_tree = list_entry(stack->top, sTree_stack, _list)->_tree->right;
		Pop_tree();
	}
	printf("\n");
}


void LDR_tree(struct tree *root)
{
	struct tree *root_tree = root;

	while(root_tree!=NULL || stack->size!=0){
		if (root_tree!=NULL){
			Push_tree(root_tree);
			root_tree = root_tree->left;
			continue;
		}
		
		root_tree = list_entry(stack->top, sTree_stack, _list)->_tree->right;
		PrintTreeNode(list_entry(stack->top, sTree_stack, _list)->_tree);
		Pop_tree();
	}
	printf("\n");
}


void LRD_tree(struct tree *root)
{
	struct tree *root_tree = root;
	struct tree *have_visitd;

	while(root_tree!=NULL || stack->size!=0){
		
		if (root_tree!=NULL){
			Push_tree(root_tree);
			root_tree = root_tree->left;
			continue;
		}
		
		root_tree = list_entry(stack->top, sTree_stack, _list)->_tree->right;
			
		if (root_tree==NULL || have_visitd==root_tree){
			PrintTreeNode(list_entry(stack->top, sTree_stack, _list)->_tree);
			have_visitd = list_entry(stack->top, sTree_stack, _list)->_tree;
			Pop_tree();
			root_tree=NULL;
		}
	}
	printf("\n");
}


void PrintTreeNode(struct tree *root)
{
	printf("%c", tree_entry(root, sTreeNode, _tree)->data);
}


void Push_tree(struct tree *push_node)
{
	pTree_stack stack_node = calloc(1, sizeof(sTree_stack));
	init_list(&stack_node->_list);

	stack_node->_tree = push_node;
	Push(stack, &stack_node->_list);
}


void Pop_tree()
{
	struct list *pop_node = Pop(stack);
	pTree_stack free_tmp = list_entry(pop_node, sTree_stack, _list);
	free(free_tmp);
}
