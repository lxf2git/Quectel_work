#include"main.h"

int main()
{
	int out = 1;
	pStu pHead=NULL;
	init_memory(&pHead);
	load(pHead);
	while(out==1)
	{
		printf("please choose one of menu:\n");
		printf("/***************************/\n");
		printf("/*******1: ** insert *******/\n");
		printf("/*******2: ** delete *******/\n");
		printf("/*******3: ** search *******/\n");
		printf("/*******4: ** printf *******/\n");
		printf("/*******5: **  save  *******/\n");
		printf("/*******6: **  exit  *******/\n");

		enum menu {insert=1,del,search,print,save,exit_};

		int c;
		scanf("%d",&c);

		switch(c)
		{
			case insert:
					s_insert(pHead);		
					break;
			case del:
					s_del(pHead);
					break;
			case search:
					s_search(pHead);
					break;
			case print:
					s_print(pHead);
					break;
			case save:
					s_save(pHead);
					break;
			case exit_:
					printf("The file save in 'save.txt'\n");
					out=0;
					break;
			default:
					printf("choose error!\n");
					exit(-1);
					break;
		}
	}
}
