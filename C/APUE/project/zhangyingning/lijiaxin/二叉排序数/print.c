#include"tree_sort.h"

void show_tree(pTree root)
{
		if(root->tr_lc!=NULL)
		{
				show_tree(root->tr_lc);
		}
		printf("%c ",root->tr_data);
		if(root->tr_rc!=NULL)
		{
				show_tree(root->tr_rc);
		}
}
int print_(pTree pHead)
{
		show_tree(pHead);
		printf("\n");
		return 0;
}
