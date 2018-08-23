#include "pub.h"

pStack stack;

int main(int argc, char **argv)
{
	stack = InitStack();
	sTreeNode root;
	init_tree(&root._tree);
	
	root.data = argv[1][0];
	CreateTree(&root._tree, &argv[1][1]);
	DLR_tree(&root._tree);
	LDR_tree(&root._tree);
	LRD_tree(&root._tree);
	return 0;                      
}
