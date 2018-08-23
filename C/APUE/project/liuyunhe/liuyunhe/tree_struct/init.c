#include"init.h"

void init_tree(pTree pTree_new)
{
		pTree_new->tr_data=0;
		pTree_new->tr_parent=NULL;
		pTree_new->tr_lc=NULL;
		pTree_new->tr_rc=NULL;

}
int greate_memory(pTree *pf)
{
		*pf=malloc(sizeof(sTree));
		if(*pf==NULL)
		{
				printf("sorry no malloc\n");
				exit (-1);
		}
}
