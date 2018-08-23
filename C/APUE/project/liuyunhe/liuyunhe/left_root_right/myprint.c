#include"main.h"

void myprint(pTree pTree_head)
{
		printf("%4c",pTree_head->tr_data);
		if(pTree_head->tr_lc!=NULL)
		{
				myprint(pTree_head->tr_lc);
		}

		if(pTree_head->tr_rc!=NULL)
		{
				myprint(pTree_head->tr_rc);
		}
		
}

