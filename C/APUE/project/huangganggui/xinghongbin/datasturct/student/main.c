#include"struct.h"
#include<stdlib.h>
#include"init.h"
#include"chain.h"
#include"printf.h"
#include"search.h"
#include"save.h"
void menu_chain(pStu pHead,pList plist);
int main()
{
		pStu pHead;
		chain_init(&pHead);
		pList plist;
		list_init(&plist);
		init_file(pHead,plist);
		menu_chain(pHead,plist);
		findtiall(&pHead);
		
		
}





void menu_chain(pStu pHead,pList plist)
{
		int choose;
		int ret;
		int save=1;
		do
		{
				
				printf("                   -------------------\n");
				printf("------------------>");
				printf("please choose  way|\n");
				printf(" student           1  chain INPUT    |\n");
				printf("                   2  chain DEL      |\n");
				printf("      management   3  chain SEARCH   |\n");
				printf("                   4  chain OUTPUT   |\n");
				printf("                   5  chain SAVE     |\n");
				printf("           system  6  chain EXIT     |\n");
				printf("                   -------------------\n");

				printf("plese input choose:");
				ret=scanf("%d",&choose);
				switch(choose)
				{
						case INPUT: 
								create_chain(pHead ,plist);
								break;
						case DEL:
								del_chain(pHead ,plist);
								break;
						case SEARCH:
								search_chain(pHead,plist);
								break;
						case PRINTF:
								chain_output(pHead);
								break;
						case SAVE:
								open_file(pHead,plist);
//								get_file();
								break;
						case EXIT:
//								exit_chain(save,p_head);
								return;
								break;
						default:
								printf("input error\n");
								break;				
				}

		}while(ret !=0);
		printf("input error\n");

}
