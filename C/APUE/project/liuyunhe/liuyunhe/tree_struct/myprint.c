#include"init.h"

void myprint(pTree pTree_head)
{
				if(pTree_head->tr_lc!=NULL)
				{
						myprint(pTree_head->tr_lc);
				}
				printf("%4d",pTree_head->tr_data);
				if(pTree_head->tr_rc!=NULL)
				{
						myprint(pTree_head->tr_rc);
				}
}
