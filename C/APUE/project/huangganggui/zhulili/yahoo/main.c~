#include"main.h"



int main()
{
	pNode pHeadA;
	pNode pHeadB;
	int choose;
	init_node(&pHeadA,sizeof(sNode));
	init_node(&pHeadB,sizeof(sNode));
	for(;;)
	{
		printf("请选择:\n");
		printf("1--------------输入链表A的数据\n");
		printf("2--------------输入链表B的数据\n");
		printf("3-----------打印链表A与B的数据\n");
		printf("4-------删除链表A与B相同的数据\n");
		printf("5-------------------------退出\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case inputA:
					insertA(pHeadA);
					break;
			case inputB:
					insertB(pHeadB);
					break;
			case print:
					pPrint(pHeadA,pHeadB);
					break;
			case del:	
					delete_node(pHeadA,pHeadB);
					break;
			case quit:
					return 0;
			default:
					printf("error");
					break;
		}
	}
	return 0;
}
