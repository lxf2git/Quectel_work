#include"creat.h"
void creat_chain(pTree *root)
{
		char x;
		scanf("%c",&x);
		if(x==' ')
		{
				(*root) = NULL;
		}
		else
		{
			init_node(root);
			(*root)->data = x;
			creat_chain(&(*root)->lc);
			creat_chain(&(*root)->rc);
		}
}
