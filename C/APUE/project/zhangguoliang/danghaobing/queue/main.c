#include"main.h"
int main()
{
		pTree root;
		creat_chain(&root);
		if(root==NULL)
		{
				printf("There is no chain save\n");
				return 0;
		}
		show_glob(root);
		return 0;
}
