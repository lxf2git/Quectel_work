#include"main.h"
#include"struct.h"

int main()
{
	pList plist=NULL;
	init_list(&plist);
	init_stu(&(plist->Head));
	for(;;)
	{
		printf("please input your choose:\n");
		printf("1  insert   2  del   3  search  4   print  5   save  6   exit\n");
		int choose;
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				INSERT(plist->Head,plist);
				break;
			case 2:
				DEL(plist->Head,plist);
				break;
			case 3:
				SEARCH(plist->Head,plist);
				break;
			case 4:
				PRINT(plist->Head);
				break;
			case 5:
				SAVE(plist->Head,plist);
				break;
			case 6:
				exit(0);
		}
	}
	return 0;
}
