#include"main.h"
enum nun
{
		creat_=1,
		print,
		exit_
};
int main()
{
		int nun;
		pTree pTree_head;
		great_memory(&pTree_head);
		init_tree(pTree_head);
		while(1)
		{
				printf("********************\n");
				printf("1.输入 2.打印 3.退出\n");
				scanf("%d",&nun);
				switch(nun)
				{
						case creat_:
								creat(pTree_head);
								break;
						case print:
								myprint(pTree_head);
								printf("\n");
								break;
						case exit_:
								exit (-1);
								break;

				}
		}
}
