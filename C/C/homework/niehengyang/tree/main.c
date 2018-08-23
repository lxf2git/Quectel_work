#include"main.h"

enum choose_name
{
	Create=1,
	Delete,
	Print	
};

int main()
{
	int choose;
	pTr Head=NULL;
	pTr head=NULL;
	create_memory(&Head,sizeof(sTr));
	create_memory(&head,sizeof(sTr));
	while(1)
	{
	printf("**********TREE*********\n");
	printf("*********1.create******\n");
	printf("*********2.delete******\n");
	printf("*********3.print*******\n");
	printf("***********************\n");
	printf("please input your choose\n");
	scanf("%d",&choose);
	switch(choose)
	{
		case Create:
		create_tree(Head);
		break;
		case Delete:
		//delete tree(Head,head);
		break;
		case Print:
		//print tree(Head,head);
		break;
	
	}
	}
}
