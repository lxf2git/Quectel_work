#include"main.h"

int main()
{
	pTree root;
	sStack sta;
	init_stack(&sta);
	int choose;
	while(1)
	{
	printf("*****************************\n");
	printf(" ********1.create tree******\n");
	printf(" ********2.prev show********\n");
	printf(" ********3.min show*********\n");
	printf(" ********4.last show********\n");
	printf(" ********5.exit soft********\n");
	printf("*****************************\n");
	printf("please input your choose:\n");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
		create_tree(&root);
		break;
		case 2:
		prev_show_tree(&sta,root);
		printf("\n");
		break;
		case 3:
		min_show_tree(&sta,root);
		printf("\n");
		break;
		case 4:
		last_show_tree(&sta,root);
		printf("\n");
		break;
		case 5:
		exit(-1);
		default:
		printf("input error!please input restart.\n");
	}
	}
}
