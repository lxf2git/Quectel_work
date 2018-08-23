#include"main.h"
int main()
{
		pTree pt_arr;
		init_tree(&pt_arr);
		int x;
		while(1)
		{
				printf("1 create!\n");
				printf("2 delete!\n");
				printf("3 print!\n");
				printf("0 exit!\n");
				scanf("%d",&x);
			switch(x)
			{
				case CREATE:
						create(pt_arr);
						break;
				case DELETE:
						delete_Node(pt_arr);
						break;
				case PRINT:
						print(pt_arr);
						printf("\n");
						break;
				case EXIT:
						return 0;
				default:
						printf("input error! please input again!\n");
						break;
			}
		}
}
