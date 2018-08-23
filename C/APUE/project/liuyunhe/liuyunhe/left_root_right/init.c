#include"main.h"

great_memory(pTree *pf)
{
		*pf=malloc(sizeof(sTree));
		if(*pf==NULL)
		{
				printf("sorry not malloc\n");
				exit -1;
		}
}

void init_tree(pTree pf)
{
		pf->tr_parent=NULL;
		pf->tr_lc=NULL;
		pf->tr_rc=NULL;
		pf->tr_data='#';
}
