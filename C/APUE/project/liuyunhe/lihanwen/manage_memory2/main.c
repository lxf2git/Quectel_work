#include"main.h" 

void main()
{
	int i=0,m;
	enum menu {apply=1,free,print,exit};
	pMem pApply,pFree;
	init_memory(&pApply);
	init_memory(&pFree);

	builtmemory(pApply);
	m_print(pApply);
	
	while(i==0)
	{
		printf("===================\n");
		printf("===== 1:apply =====\n");
		printf("===== 2:free  =====\n");
		printf("===== 3:print =====\n");
		printf("===== 4:exit  =====\n");
		printf("===================\n");

		scanf("%d",&m);
		switch(m)
		{
			case apply:
							m_apply(pApply,pFree);
							break;
			case free:
							//m_free(pApply,pFree);
							break;
			case print:
							printf("Apply chain:\n");
							m_print(pApply);
							printf("Free chain:\n");
							m_print(pFree);
							break;
			case exit:
							printf("save in save.txt\n");
							i=1;
							break;
			default:
							printf("choose error!\n");
	//						destroy_chain(pApply);
							break;
		}

	}
}
