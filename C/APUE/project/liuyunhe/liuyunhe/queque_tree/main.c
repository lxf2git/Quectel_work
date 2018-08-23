#include"main.h"

enum data
{
		tree=1,
		que,
		exit_
};
int main()
{
		int data;
		pTree root=NULL;
		pStack pStack_head;
		init_pStack(&pStack_head);
		while(1)
		{
				printf("***********************\n");
				printf("1.建树  2.层次遍历  3.退出\n");
				scanf("%d",&data);
				getchar();
				switch(data)
				{
						case tree:
								tree_(&root);//建树
								break;
						case que:
								queque(pStack_head,root);//层次遍历
								break;
						case exit_:
								exit(-1);
								break;
						default:
								printf("sorry_\n");
								break;
				}
		}
}
