#include"main.h"
#include"insert.h"
#include"queue.h"

int main()
{
	pTree root=NULL;
	init_tree(&root,sizeof(sTree));
	creat_tree(&root);
	sQue sq;
	init_queue(&sq);
	print(&sq,root);
	return 0; 
}
