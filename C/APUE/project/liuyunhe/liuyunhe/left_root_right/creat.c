#include"main.h"

creat_lc_rc(pTree pTree_head)
{
		char ch;
		printf("请输入一个字符\n");
		scanf("%c",&ch);
		getchar();
//		printf("%d\n",ch);
		if(ch!=32)
		{
				printf("左\n");
				pTree pTree_new;
				great_memory(&pTree_new);
				init_tree(pTree_new);
				pTree_head->tr_lc=pTree_new;
				pTree_new->tr_parent=pTree_head;
				pTree_new->tr_data=ch;
				creat_lc_rc(pTree_new);
		}

		printf("请输入一个字符\n");
		scanf("%c",&ch);
		getchar();
		if(ch!=32)
		{
				printf("右\n");
				pTree pTree_new;
				great_memory(&pTree_new);
				init_tree(pTree_new);
				pTree_head->tr_rc=pTree_new;
				pTree_new->tr_parent=pTree_head;
				pTree_new->tr_data=ch;
				creat_lc_rc(pTree_new);
		}

}

void creat(pTree pTree_head)
{
		char ch;
		printf("请输入一个根头\n");
		getchar();
		scanf("%c",&ch);
		getchar();
						if(ch!=32)
						{
								pTree_head->tr_data=ch;
								creat_lc_rc(pTree_head);
						}
						else
						{
								printf("输入的根头不能为空\n");
						}
}
