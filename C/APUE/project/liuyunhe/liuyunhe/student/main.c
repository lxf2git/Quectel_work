#include"main.h"

enum en_name
{
		insert_=1,
		del_,
		search_,
		print_,
		save_,
		exit_,
};
int main()
{
		int pr;
		sList slist;
		//		init_Node(&slist,sizeof(sList));
		init_Node(&slist.pHead,sizeof(sStu));
		printf("load***\n");
		load(slist.pHead);
		while(1)
		{
		printf("1 insert 2 del 3 search(1 age 2 id) 4 print 5 save 6 exit\n");
		scanf("%d",&pr);
			switch(pr)
			{
				case insert_:
						insert(slist.pHead,slist);
						break;
				case del_:
						del(slist.pHead,slist);
						break;
				case search_:
						search(slist.pHead,slist);
						break;
				case print_:
						print(slist.pHead,slist);
						break;
				case save_:
						save(slist.pHead,slist);
						break;
				case exit_:
						printf("exit\n");
						Destory_list(&slist.pHead);
						exit (-1);
						break;
				default:
						printf("输入错误\n");
						break;
			}
		}
		return 0;
}
