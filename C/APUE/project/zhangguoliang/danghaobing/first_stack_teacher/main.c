#include"main.h"

int main()
{
		pTree root;
		creat_chain(&root);
		if(root==NULL)
		{
				printf("nul tree!\n");
				return -1;
		}
		printf("================prev trav===============\n");
		show_pre(root);
		printf("\n================mid trav================\n");
		show(root);
		printf("\n================last trav===============\n");
		show_last(root);
		printf("\n");
		return 0;
}
