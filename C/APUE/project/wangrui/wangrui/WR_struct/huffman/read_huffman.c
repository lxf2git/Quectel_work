#include"huffman.h"

void read_huffman_tree(pNode *pnode,FILE *fp)
{
//	pNode pnode = NULL;
	int ret = 0;
	init_node(pnode);
	ret = fread(*pnode,sizeof(sNode),1,fp);
	if((*pnode)->weight == -1)
	{
		free_node(pnode);
	}
	else
	{
		read_huffman_tree(&(*pnode)->lc,fp);
		read_huffman_tree(&(*pnode)->rc,fp);
	}
}
