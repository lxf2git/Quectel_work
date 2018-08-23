#include"init.h"

void creat_tree(pTree *root)
{
	char ch;
	scanf("%c",&ch);
	getchar();
	if(ch==32)
	{
			root=NULL;
	}
	else
	{
			init_root(root);
			(*root)->ch=ch;
			creat_tree(&(*root)->tr_lc);
			creat_tree(&(*root)->tr_rc);
	}
	
}

void tree_(pTree *root)
{
		printf("建立树\n");
		creat_tree(root);
}
