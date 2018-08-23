#include"init.h"

enum data
{
		creat_=1,
		delete_,
		print_,
		exit_
};

int main()
{
		int data;
		pTree pTree_head;
		greate_memory(&pTree_head);
		init_tree(pTree_head);
	while(1)
	{
		printf("************************\n");
		printf("请输入选项\n");
		printf("1.输入2.删除3.打印4.退出\n");
		scanf("%d",&data);
		switch(data)
		{
				case creat_:
						creat(pTree_head);
						break;
				case delete_:
						delete(&pTree_head);
						break;
				case print_:
						myprint(pTree_head);
						printf("\n");
						break;
				case exit_:
						exit (-1);
						break;
				default:
						printf("sorry erroy\n");
						break;


		}
	}
}
