#include "pub.h"


void CreateTree(struct tree *root, char *data)
{
	int node_data = atoi(data);
	struct tree *create_tmp;
	
	if (NULL == root){
		create_tmp = AddTreeNode(node_data);
		Push_tree(create_tmp);
		return ;
	}
	
	if (node_data <= list_entry(root, sTreeNode, _tree)->data){
		CreateTree(root->left, data);

		if (stack->size!=0){
			root->left = list_entry(stack->top, sTree_stack, _list)->_tree;
			list_entry(stack->top, sTree_stack, _list)->_tree->root = root;
			Pop_tree();
		}

		return ;
	}

	if (node_data > list_entry(root, sTreeNode, _tree)->data){
		CreateTree(root->right, data);
	
		if (stack->size!=0){
			root->right = list_entry(stack->top, sTree_stack, _list)->_tree;
			list_entry(stack->top, sTree_stack, _list)->_tree->root = root;
			Pop_tree();
		}
		return ;
	}
}


struct tree *AddTreeNode(unsigned int data)
{
	pTreeNode tree_node = calloc(1, sizeof(sTreeNode));
	tree_node->data = data;
	init_tree(&tree_node->_tree);

	return &tree_node->_tree;

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

#if 1
void LDR_tree(struct tree *root)
{
	struct tree *root_tree = root;

	if (root_tree==NULL){
		return ;
	}

	LDR_tree(root_tree->left);
	PrintTreeNode(root_tree);
	LDR_tree(root_tree->right);

}
#endif


void PrintTreeNode(struct tree *root)
{
	printf("%d ", tree_entry(root, sTreeNode, _tree)->data);
}


void DelTreeNode(struct tree *root)
{
	struct tree *root_tree = root;
	struct tree *find_node;
	struct tree **del_node_root;
	struct tree *del_node_left;
	int del_data;

	printf("请输入要删除的数据.\n");
	scanf("%d", &del_data);

	find_node = SearchTreeNode(root, del_data);
	del_node_root = FindEqualNode(find_node->root, find_node);

	if (NULL==find_node->left || NULL==find_node->right){
			
		if (find_node->left!=NULL){
			*del_node_root = find_node->left;
			find_node->left->root = find_node->root;
		}
		else{
			*del_node_root = find_node->right;
			find_node->right->root = find_node->root;
		}
		free(tree_entry(find_node, sTreeNode, _tree));
	}
	else{
		del_node_left = find_node->left;
		*del_node_root = find_node->left;
		find_node->left->root = find_node->root;
		
		while(del_node_left->right!=NULL){
			del_node_left = del_node_left->right;
		}

		del_node_left->right = find_node->right;
	}
}



struct tree **FindEqualNode(struct tree *root, struct tree *find_node)
{
	if (root->left == find_node){
		return &root->left;
	}

	if (root->right == find_node){
		return &root->right;
	}
}


struct tree *SearchTreeNode(struct tree *root, int del_data)
{
	if (NULL == root){
		printf("无此数据节点.\n");
		return ;
	}
	
	if (tree_entry(root, sTreeNode, _tree)->data == del_data){
		return root;
	}

	if (del_data < tree_entry(root, sTreeNode, _tree)->data){
		SearchTreeNode(root->left, del_data);
		return ;
	}

	if (del_data > tree_entry(root, sTreeNode, _tree)->data){
		SearchTreeNode(root->right, del_data);
		return ;
	}

}
