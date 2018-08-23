#include "pub.h"

pStack stack;

int main(int argc, char **argv)
{
	unsigned char index;
	stack = InitStack();
	sTreeNode root;
	init_tree(&root._tree);
	list_entry(&root._tree, sTreeNode, _tree)->data = atoi(argv[1]);

	for(index=2; index<argc; index++){
		CreateTree(&root._tree, argv[index]);
	}

	LDR_tree(&root._tree);
	printf("\n");
	
	DelTreeNode(&root._tree);
	LDR_tree(&root._tree);
	printf("\n");

	return 0;
}
