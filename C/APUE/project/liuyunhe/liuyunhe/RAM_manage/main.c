#include"main.h"

enum swi
{
		apply_=1,
		free_,
		print_,
		exit_
};
int main()
{
		int i;
		int app=0;
		pmanage apply_head;
		great_memory(&apply_head);
		manage_st(apply_head);		//建造apply
		
		pmanage myfree_head;
		great_memory(&myfree_head);

		pRecord precord_head;
		pre_memory(&precord_head);

		while(1)
		{
				printf("********************************\n");
				printf("1.apply  2.free 3.printf  4 exit\n");
				printf("please:\n");
				scanf("%d",&i);
				switch(i)
				{
					case apply_:
							apply(apply_head,myfree_head,precord_head);
							app++;
							break;
					case free_:
							myfree(apply_head,myfree_head,precord_head,app);
							break;
					case print_:
							myprint(apply_head,myfree_head);
							break;
					case exit_:
							exit_free(apply_head);
							exit (-1);
							break;
					default:
							printf("sorry  mistake\n");
							break;
						
				}
		}
}
