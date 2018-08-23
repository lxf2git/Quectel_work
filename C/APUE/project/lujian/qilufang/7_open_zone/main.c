#include"main.h"
int main()
{	
	int in;
	pMem pHead;
	pMem pHead_app;
	pRec pHead_rec;
	init_chain_rec(&pHead_rec,sizeof(sRec));
	init_chain(&pHead_app,sizeof(sMem));
	init_chain(&pHead,sizeof(sMem));
	memory_chain(pHead);
	all_mem(&pHead);
	while(1)
	{
		printf("/******<1>*****************apply*******/\n");
		printf("/******<2>*****************free********/\n");
		printf("/******<3>*****************print*******/\n");
		printf("/******<4>*****************exit********/\n");
		printf("/******<5>********all_mem_output*******/\n");
		printf("请输入你的选项：\n");
		scanf("%d",&in);
		switch(in)
		{
			case APPLY :	apply_chain(pHead_app,pHead,pHead_rec); break;
			case FREE :	myfree(pHead,pHead_app,pHead_rec); break;
			case PRINT :	
					printf("申请链表：\n");					
					output(pHead_app);
					printf("释放链表：\n");
					output_rec(pHead_rec); 
					break;
			case EXIT : 	My_free(&pHead);
					My_free(&pHead_app);
					My_free_rec(&pHead_rec);
					exit(0);					
					break;
			case ALLPUT :	
					printf("总链表：\n");					
					output(pHead);
					break;
			default :	printf("小伙输错了，请重输！\n"); break;
		}
	}
	return 0;
}
