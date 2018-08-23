#include"main.h"
int menu_m(void)
{	
	int data;
	sList pl;
	pStu phead;
	init_memory(&phead);
	read_fp(phead);
	while(1)
	{

		printf("插入选择---------------1\n");
		printf("删除选择---------------2\n");
		printf("查找选择---------------3\n");
		printf("输出选择---------------4\n");
		printf("保存选择---------------5\n");
		printf("退出选择---------------6\n");
		scanf("%d",&data);
		switch(data)
		{
			case 1:
			
				insert_chain(phead,pl);

				break;

			case 2:

				delete_chain(phead,pl);
				break;


			case 3:
				
				search_chain(phead,pl);			
				
				break;			

			case 4:
				
				print_chain(phead,pl);
				
				break;
	
			case 5:

				save_chain(phead,pl);
				
				break;

			case 6:

				return 0;

				
				
			default :
				printf("输入有误!\n");
				
				 break;
		}
	}
}
