#include"main.h"
int main()
{
	sList slist;
	int i;
	init_node(&slist.pHead,sizeof(sStu));
	lode(slist.pHead);
	while(1)
	{
		printf("1.学生信息输入\n");
		printf("2.删除\n");
		printf("3.查找\n");
		printf("4.输出\n");		
		printf("5.保存\n");
		printf("6.退出\n");
		scanf("%d",&i);
		switch(i)
		{
			case insert_:
			Insert(slist,slist.pHead);
			break;
			case del_:
			Del(slist,slist.pHead);
			break;
			case sea_:
				Search(slist,slist.pHead);
			break;
			case print_:
				Print(slist,slist.pHead);
			break;
			case save_:
				Save(slist,slist.pHead);
			break;
			case exit_:
				Free(slist.pHead);
			exit(-1);
		}	
	}
}
